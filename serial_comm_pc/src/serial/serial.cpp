#include "serial.h"
class SerialImpl: private boost::noncopyable {
	public:
   	SerialImpl(): io(), port(io), backgroundThread(), open(false), error(false) {}

    boost::asio::io_service io;
    boost::asio::serial_port port;
    boost::thread backgroundThread;
    bool open;
    bool error;
    mutable boost::mutex errorMutex; ///< Mutex for access to error

    /// Data are queued here before they go in writeBuffer
    boost::shared_array<unsigned char> writeBuffer; ///< Data being written
    size_t writeBufferSize; ///< Size of writeBuffer
    unsigned char readBuffer[Serial::readBufferSize];

    boost::function<void (const unsigned char*, size_t)> callback;
};

Serial::Serial(): pimpl(new SerialImpl) { serial_running=false; }
Serial::Serial(const std::string& devname, unsigned int baud_rate,
        asio::serial_port_base::parity opt_parity,
        asio::serial_port_base::character_size opt_csize,
        asio::serial_port_base::flow_control opt_flow,
        asio::serial_port_base::stop_bits opt_stop)
        : pimpl(new SerialImpl)	{
		serial_running=false;
    open(devname,baud_rate,opt_parity,opt_csize,opt_flow,opt_stop);
}

void Serial::open(const std::string& devname, unsigned int baud_rate,
        asio::serial_port_base::parity opt_parity,
        asio::serial_port_base::character_size opt_csize,
        asio::serial_port_base::flow_control opt_flow,
        asio::serial_port_base::stop_bits opt_stop)	{
    if(isOpen()) doClose();

    pimpl->port.open(devname);
    pimpl->port.set_option(asio::serial_port_base::baud_rate(baud_rate));
    pimpl->port.set_option(opt_parity);
    pimpl->port.set_option(opt_csize);
    pimpl->port.set_option(opt_flow);
    pimpl->port.set_option(opt_stop);

    thread t(boost::bind(&asio::io_service::run, &pimpl->io));
    pimpl->backgroundThread.swap(t);
    setErrorStatus(false);//If we get here, no error
    pimpl->open=true; //Port is now open
}

int Serial::getNativePort() {
	return pimpl->port.native_handle();
}

bool Serial::isOpen() const {
    return pimpl->open;
}

bool Serial::errorStatus() const {
    lock_guard<mutex> l(pimpl->errorMutex);
    return pimpl->error;
}

Serial::~Serial() {
	if(isOpen()) {
    try {
  	  doClose();
    } catch(...) {
      ;//Don't throw from a destructor
    }
 	}
}

void Serial::doRead() {
	//Read loop in spawned thread
	serial_running = true;
  while(1) {
    int received=::read(getNativePort(),pimpl->readBuffer,readBufferSize);
    if(received<0)
    {
			continue;
    } else {
     	if(pimpl->callback) pimpl->callback(pimpl->readBuffer, received);
   	}
	}
}

void Serial::doWrite(const unsigned char* data, size_t size) {
  if(::write(getNativePort(),&data[0],size*sizeof(unsigned char))!=(size*sizeof(unsigned char))) 
		setErrorStatus(true);
}


void Serial::doClose() {
    boost::system::error_code ec;
    pimpl->port.cancel(ec);
    if(ec) setErrorStatus(true);
    pimpl->port.close(ec);
    if(ec) setErrorStatus(true);
}

void Serial::setErrorStatus(bool e) {
  lock_guard<mutex> l(pimpl->errorMutex);
	if(e) printf("ERROR! (from serial lib)\n");
}

void Serial::setReadCallback(const boost::function<void (const unsigned char*, size_t)>& callback) {
    pimpl->callback=callback;
}

void Serial::clearReadCallback() {
    pimpl->callback.clear();
}

CallbackSerial::CallbackSerial(): Serial() { }

CallbackSerial::CallbackSerial(const std::string& devname,
        unsigned int baud_rate,
        asio::serial_port_base::parity opt_parity,
        asio::serial_port_base::character_size opt_csize,
        asio::serial_port_base::flow_control opt_flow,
        asio::serial_port_base::stop_bits opt_stop)
        :Serial(devname,baud_rate,opt_parity,opt_csize,opt_flow,opt_stop) { }

void CallbackSerial::setCallback(const boost::function<void (const unsigned char*, size_t)>& callback) {
    setReadCallback(callback);
}

void CallbackSerial::clearCallback() {
    clearReadCallback();
}

CallbackSerial::~CallbackSerial() {
    clearReadCallback();
}
