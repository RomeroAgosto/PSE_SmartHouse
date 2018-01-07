#include "send_receive_messages.h"
#include <string.h>
#include "../schedules/schedules.h"
#include <stdio.h>

#if RUN==1
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#endif

static int message_flag=1;
#if RUN ==1
static char message[5000];
#endif

int get_digits(int score_int, char *score_char) {
    int i=0, div;
    char dummy[100]; /*modulo has the value in the wrong order*/
    do{
        div=score_int%10;/*gets the rest of the division by 10*/
        score_int/=10; /*divides score by 10 and rounds */
        dummy[i]=div+'0';
        i++;
    } while (score_int!=0);
    int j=0;
    while (i>0){
        i--;
        score_char[j]=dummy[i]; /*reverse order for the right order*/
        j++;
    }
    score_char[j]='\0';/*end delimiter*/
    return j;
}
int send_message(char *message) {
    long int checksum=0;
    int i=0;
    do{
        i++;
        checksum=checksum+message[i]; /*adds all characters to a sum*/
    }while(message[i]!='\0');
    char check_sum[100], delimiter_checksum_start[]="(",delimiter_checksum_end[]=")", length_checksum[2], delimiter_overall[]="*";
    length_checksum[0]=get_digits(checksum,check_sum) +'0'; /*returns the length of the checksum*/
    length_checksum[1]='\0';
    strcat(message,delimiter_checksum_start); /*appends start delimiter for the checksum*/
    strcat(message,length_checksum); /*appends the length*/
    strcat(message,delimiter_checksum_end); /*enddelimiter for the checksum*/
    strcat(message,check_sum);/*appends the checksum itself*/
    strcat(message,delimiter_overall);/*appends the overall delimiter for our messages *  */
    return 1;

}

double power(double a, double b){
        int i;
        double result= a;
        for (i = 1; i < b; i++) {
            result= result*a;

        }
        return result;
    }

long int get_int(char* received_checksum,int length){
        int i;
        long int checksum=0,long_int_value;
        long int multiplier=0;
        for (i =length ; i>0 ; i--) {
            multiplier=power(10,length)/power(10,(length-i+1));
            long_int_value=(long int) (received_checksum[length-i]-'0');
            checksum=checksum+long_int_value*multiplier;
        }
        return checksum;
    }

long int check_received_message(char *message){
        int i=1;
        int checksum_length=0;
        long int checksum=0,checksum_calculated=0;
        char received_checksum[100];
        do{
            checksum_calculated=checksum_calculated+message[i];
            i++;
        }while(message[i]!='(');
        i++; /*to access the length and not the delimiter*/
        while(message[i]!=')'){ /*when the length delimiter is received -> length is known*/
            checksum_length=checksum_length+message[i]-'0';
            i++;
        }
        i++;
        int j=i;
        do{
            received_checksum[i-j]=message[i];
            i++;
        }while(message[i]!='*');
        checksum=get_int(received_checksum,checksum_length);
        printf("the send sum is: %ld, the calculated sum is: %ld",checksum,checksum_calculated);
        if (checksum!=checksum_calculated){return -1;};

    return 1;

    }
#if RUN == 0
char message[]="#+27300122002200*";
#endif
int message_handle() {
    if (message_flag==1){
        if (message[1]=='?') {
            create_normal_message(message);
            //send_message(message);
        } 
        else if (message[1]=='+') {
           printf("new schedule");
           get_schedule_message(message);
        }
        message_flag=0;
       
    }
        return 1;
}

#if RUN == 1
#define UART_PRIORITY_P 4
#define UART_PRIORITY_S 3
void init_uart(void){

    IFS0bits.U1RXIF = 0;
    IFS0bits.U1TXIF = 0;

    IPC6bits.U1IP = UART_PRIORITY_P;
    IPC6bits.U1IS = UART_PRIORITY_S;

    U1STAbits.URXISEL=0;
    U1STAbits.UTXISEL=0;

    IEC0bits.U1RXIE =1;

}


void __ISR(_UART_1_VECTOR,IPL4AUTO) _UART1Handler(void){
    static int message_counter;
    char charbuf[1];
    charbuf[0]= U1RXREG;
    message[message_counter]=charbuf[0];
    message_counter++;
    if (charbuf[0]=='*'){

        message_flag=TRUE;
        message_counter=0;
        printf("message is: %s\n",message);
    }
    
    IFS0bits.U1RXIF=0;
    IFS0bits.U1TXIF=0;

}
#endif
