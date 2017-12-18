#ifndef __SERIAL_H__
#define	__SERIAL_H__

	#include <vector>
	#include <string>
	#include <algorithm>
	#include <iostream>
	#include <boost/asio.hpp>
	#include <boost/bind.hpp>
	#include <boost/thread.hpp>
	#include <boost/utility.hpp>
	#include <boost/function.hpp>
	#include <boost/shared_array.hpp>
	#include <boost/bind.hpp>


	extern bool serial_running; //from simple_interface.h

	using namespace std;
	using namespace boost;

	class SerialImpl;

	class Serial: private boost::noncopyable {
		public:
			int getNativePort();
  	  static const int readBufferSize=5000;
  	  void doRead();
  	  void doWrite(const unsigned char*, size_t);
  	  void doClose();
  	  bool isOpen() const;
  	  bool errorStatus() const;
			bool serial_running;

    	Serial(const std::string& devname, unsigned int baud_rate,
       	boost::asio::serial_port_base::parity opt_parity=
        boost::asio::serial_port_base::parity(
        boost::asio::serial_port_base::parity::none),
       	boost::asio::serial_port_base::character_size opt_csize=
        boost::asio::serial_port_base::character_size(8),
        boost::asio::serial_port_base::flow_control opt_flow=
        boost::asio::serial_port_base::flow_control(
        boost::asio::serial_port_base::flow_control::none),
        boost::asio::serial_port_base::stop_bits opt_stop=
        boost::asio::serial_port_base::stop_bits(
        boost::asio::serial_port_base::stop_bits::one));

    	void open(const std::string& devname, unsigned int baud_rate,
        boost::asio::serial_port_base::parity opt_parity=
        boost::asio::serial_port_base::parity(
        boost::asio::serial_port_base::parity::none),
        boost::asio::serial_port_base::character_size opt_csize=
        boost::asio::serial_port_base::character_size(8),
        boost::asio::serial_port_base::flow_control opt_flow=
        boost::asio::serial_port_base::flow_control(
        boost::asio::serial_port_base::flow_control::none),
        boost::asio::serial_port_base::stop_bits opt_stop=
        boost::asio::serial_port_base::stop_bits(
        boost::asio::serial_port_base::stop_bits::one));

    	Serial();
    	virtual ~Serial()=0;

		private:
    	boost::shared_ptr<SerialImpl> pimpl;

		protected:
    	void setErrorStatus(bool e);
    	void setReadCallback(const boost::function<void (const unsigned char*, size_t)>& callback);
    	void clearReadCallback();
	};

	class CallbackSerial: public Serial {
		public:
    	void setCallback(const boost::function<void (const unsigned char*, size_t)>& callback);
    	void clearCallback();

    	CallbackSerial(const std::string& devname, unsigned int baud_rate,
        boost::asio::serial_port_base::parity opt_parity=
        boost::asio::serial_port_base::parity(
        boost::asio::serial_port_base::parity::none),
      	boost::asio::serial_port_base::character_size opt_csize=
        boost::asio::serial_port_base::character_size(8),
        boost::asio::serial_port_base::flow_control opt_flow=
        boost::asio::serial_port_base::flow_control(
        boost::asio::serial_port_base::flow_control::none),
        boost::asio::serial_port_base::stop_bits opt_stop=
        boost::asio::serial_port_base::stop_bits(
        boost::asio::serial_port_base::stop_bits::one));

    	CallbackSerial();
    	virtual ~CallbackSerial();
};

#endif//__SERIAL_H__
