
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
    int checksum=0;
    int i=0;
    do{
        i++;
        checksum=checksum+message[i]; /*adds all characters to a sum*/
    }while(message[i]!='\0');
    printf("the checksum is: %d\n",checksum);


    char check_sum[100], delimiter_checksum_start[]="(",delimiter_checksum_end[]=")", length_checksum[2], delimiter_overall[]="*";
    length_checksum[0]=get_digits(checksum,check_sum) +'0'; /*returns the length of the checksum*/
    length_checksum[1]='\0';
    printf("%s\n",delimiter_checksum_start);
    strcat(message,delimiter_checksum_start); /*appends start delimiter for the checksum*/
    strcat(message,&length_checksum); /*appends the length*/
    strcat(message,delimiter_checksum_end); /*enddelimiter for the checksum*/
    strcat(message,check_sum);/*appends the checksum itself*/
    strcat(message,delimiter_overall);/*appends the overall delimiter for our messages *  */
    printf("%s\n",message);
    return 1;

}

