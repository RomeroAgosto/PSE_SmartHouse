
#include <string.h>
#include <stdio.h>
#include "message.h"

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
    printf("the checksum is: %ld\n",checksum);


    char check_sum[100], delimiter_checksum_start[]="(",delimiter_checksum_end[]=")", length_checksum[2], delimiter_overall[]="*";
    length_checksum[0]=get_digits(checksum,check_sum) +'0'; /*returns the length of the checksum*/
    length_checksum[1]='\0';
    printf("%s\n",delimiter_checksum_start);
    strcat(message,delimiter_checksum_start); /*appends start delimiter for the checksum*/
    strcat(message,length_checksum); /*appends the length*/
    strcat(message,delimiter_checksum_end); /*enddelimiter for the checksum*/
    strcat(message,check_sum);/*appends the checksum itself*/
    strcat(message,delimiter_overall);/*appends the overall delimiter for our messages *  */
    printf("%s\n",message);
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
        int checksum_length=0,checksum_calculated=0;
        long int checksum=0;
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
