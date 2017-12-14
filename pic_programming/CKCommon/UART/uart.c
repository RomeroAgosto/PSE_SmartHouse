/* 
 * File:   uart.c
 * Author: Paulo Pedreiras
 *
 * Created on Oct 25, 2017
 * MPLAB X IDE v3.50 + XC32 v1.42
 *
 * Target: Digilent chipKIT MAx32 board 
 * 
 * Overview:
 *          Set of functions to handle the UART       
 
 * Notes: Partially based on the bootloader code from Microchip
 * 
 * Revisions:
 *     2017-10-25: initial release
 */


#include <xc.h>
#include <stdlib.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include <string.h>
#include <stdio.h>
#include "uart.h"

/********************************************************************
* Function: 	UartInit()
* Precondition: 
* Input: 		PB Clock and baudrate
* Returns:      UART_SUCCESS if Ok.
*               UARTX_XXX error codes in case of failure (see uart.h)
* Side Effects:	Takes control of U1A TX and RX pins
* Overview:     Initializes UART.
*		
* Note:		 	Only supports 40MHz PBCLOCK, UART1A and 
*               {9600/115200},8,n,1 configuration
* 
********************************************************************/	
int UartInit(UINT64 pbclock, UINT32 br)
{
   if(pbclock != 40000000L) 
       return UART_PBCLOCK_NOT_SUP; // Todo: add support to common pbclock values.
       
   // In the following are used the table values provided in the datasheet
   //PIC32MX Family Reference Manual, DS61107E-pages 21-14 and following
 	switch(br) {
        case 115200:
            U1ABRG=21; 
            U1AMODEbits.BRGH = 0;
            break;
            
        case 9600:
            U1ABRG=259; /*Baudrate generator*/
            U1AMODEbits.BRGH = 0;
            break;
        default:
            return UART_BR_NOT_SUP; // Baudrate not supported
    }
    
    // Common configuration settings
    U1AMODEbits.SIDL=0; // Continue operation in idle mode 
    U1AMODEbits.IREN=0; //Disable Irda
    U1AMODEbits.UEN=0;  //Only use TX and RX pints. No HW flow control 
    U1AMODEbits.WAKE=0;  //Wake -up on start bit disabled
    U1AMODEbits.LPBACK=0;  //No loopback  
    U1AMODEbits.ABAUD=0;  //No autobaud
    U1AMODEbits.RXINV=0;  //Idle logic value is 1
    U1AMODEbits.PDSEL=0;  //8 bit data, no parity
    U1AMODEbits.STSEL=0;  //1 stop bit
    U1STAbits.ADM_EN = 0; // No automatic address detection
    U1STAbits.UTXISEL = 0; // Interrupt when TX buffer has at least 1 empty position
    U1STAbits.UTXINV = 0; // Idle logic value is 1
    
    // Configuration done. Enable.   
    U1AMODEbits.ON = 1;  
    U1STAbits.UTXEN = 1;
    U1STAbits.URXEN = 1;
    
    return UART_SUCCESS;
    
}	


/********************************************************************
* Function: 	UartClose()
* Precondition: 
* Input: 		None
* Output:		None.
* Side Effects:	None.
* Overview:     Closes UART connection.
* Note:		 	No function currently
********************************************************************/	
void UartClose(void)
{
	//TODO: do some closing operation if required.	
}	


/********************************************************************
* Function: 	GetChar()
* Precondition: UART initialized
* Input: 		None
* Output:		True: If there is some data.
* Side Effects:	None.
* Overview:     Gets the data from UART RX FIFO.
* Note:		 	None.
********************************************************************/
int GetChar(UINT8 *byte)
{
	char dummy;
    
	if(U1STAbits.OERR ||U1STAbits.FERR || U1STAbits.PERR) // receive errors?
	{
		dummy = U1RXREG; 			// dummy read to clear FERR/PERR
		U1STAbits.OERR = 0;			// clear OERR to keep receiving
	}

	if(U1STAbits.URXDA)
	{
		*byte = U1ARXREG;		        // get data from UART RX FIFO
		return TRUE;
	}
	
	return FALSE;

}


/********************************************************************
* Function: 	PutChar()
* Precondition: 
* Input: 		None
* Output:		None
* Side Effects:	None.
* Overview:     Puts the data into UART tx reg for transmission.
* Note:		 	None.
********************************************************************/
void PutChar(UINT8 txChar)
{
    while(U1STAbits.UTXBF); // wait for TX buffer to be empty
    U1ATXREG = txChar;
}


/**
 *      @brief  sends a message from the pic to the pc 
 *      @param  *messages is the message to send
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */


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
    int i=0; /*has to be encoded like this -> when a overflow occurs is the message the same in the end then*/
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
    printf("%s\n",message);
    return 1;

}


// Function replacements to redirect stdin/stdout to USART1

// These functions are called by printf(), scanf(), ...
void _mon_putc(char c) {
    while (U1STAbits.UTXBF); // Wait till buffer available (TX Buffer Full)
    U1TXREG = c; // Put char in Tx buffer
    return;
}

int _mon_getc(int canblock) {

    // Reset Overrun Eror Flag - if set UART does not receive any chars
    if (U1STAbits.OERR)
        U1STAbits.OERR;

    if (canblock == 0) {
        if (U1STAbits.URXDA)
            return (int) U1RXREG;
    }
    else {
        while (!U1STAbits.URXDA);
        return (int) U1RXREG;
    }
    return -1;
}
/***************************************End Of File*************************************/