
/** \file timer_libs.c
* \brief This library include some functions that handle the PIC32 timer in a "user-friendly" way. Allow some other programmer, less knowledgeable of the PIC32 intricacies.
*  
*
* 
*
* \author Rafael Almeida & Samuel Simoes
*
* \date 03-11-2017
*/
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>

#define SYSCLK 80000000L /*!< System clock frequency, in Hz*/
#define PBUSCLK 40000000L /*!< Peripheral bus clock */


void (*tmr1_func)()=NULL;/*!<  it's a callback variable to a function that will execute when the interrupt handler 1 is called*/
void (*tmr2_func)()=NULL;/*!<  it's a callback variable to a function that will execute when the interrupt handler 2 is called*/
void (*tmr3_func)()=NULL;/*!<  it's a callback variable to a function that will execute when the interrupt handler 3 is called*/
void (*tmr4_func)()=NULL;/*!<  it's a callback variable to a function that will execute when the interrupt handler 4 is called*/
void (*tmr5_func)()=NULL;/*!<  it's a callback variable to a function that will execute when the interrupt handler 5 is called*/




void tmr_config(int timerx,double freq)
{
    int precalerB[8]= {1,2,4,8,16,32,64,256};
    int precalerA[4]= {1,8,64,256};
    int PRX;
    int count=0;
    int p_ind;
    if(freq < 1.2) exit(EXIT_FAILURE);
    if(timerx==2 ||timerx==3 || timerx==4 ||timerx==5 )
    {    
        do
        {
            PRX= (((PBUSCLK/2)/precalerB[count])/freq)-1;
            if(PRX <= 65535) p_ind=count;
            if(PRX >= 65535) count++;
        }while(PRX >= 65535);
    }else if(timerx==1)
    {
        do
        {
            PRX= (((PBUSCLK/2)/precalerA[count])/freq)-1;
            if(PRX <= 65535) p_ind=count;
            if(PRX >= 65535) count++;
        }while(PRX >= 65535);
    }else exit(EXIT_FAILURE);    
//-----------------------------------------------------
    switch (timerx)
    {
        case 1:
            T1CONbits.TCKPS = p_ind; //  prescaler 
            PR1 = PRX; // Fout = 20MHz / (p_ind * (PRX + 1)) = freq Hz 
            TMR1 = 0; // Reset timer T1 count register 
            break;  
        case 2:
            T2CONbits.TCKPS = p_ind; //  prescaler 
            PR2 = PRX; // Fout = 20MHz / (p_ind * (PRX + 1)) = freq Hz 
            TMR2 = 0; // Reset timer T2 count register 
            break;   
        case 3:
            T3CONbits.TCKPS = p_ind; //  prescaler 
            PR3 = PRX; // Fout = 20MHz / (p_ind * (PRX + 1)) = freq Hz 
            TMR3 = 0; // Reset timer T3 count register 
            break;   
        case 4:
            T4CONbits.TCKPS = p_ind; //  prescaler 
            PR4 = PRX; // Fout = 20MHz / (p_ind * (PRX + 1)) = freq Hz 
            TMR4 = 0; // Reset timer T4 count register 
            break;  
        case 5:
            T5CONbits.TCKPS = p_ind; //  prescaler 
            PR5 = PRX; // Fout = 20MHz / (p_ind * (PRX + 1)) = freq Hz 
            TMR5 = 0; // Reset timer T5 count register 
            break; 
        default:
            exit(EXIT_FAILURE);
    }


}

void tmr_wait(int timerx)
{
    switch (timerx)
    {
        case 1:
             while(IFS0bits.T1IF==0);
                        IFS0bits.T1IF=0;
         break;
        case 2:
             while(IFS0bits.T2IF==0);
                        IFS0bits.T2IF=0;
         break;
        case 3:
             while(IFS0bits.T3IF==0);
                        IFS0bits.T3IF=0;
         break;
        case 4:
             while(IFS0bits.T4IF==0);
                        IFS0bits.T4IF=0;
         break;
        case 5:
             while(IFS0bits.T5IF==0);
                        IFS0bits.T5IF=0;
         break;
         
        default:
            exit(EXIT_FAILURE);
    }    
}



void tmr_intrpt_config(int timerx, int priority, void (*tmr_function)(void))
{
   
     INTEnableSystemMultiVectoredInt();
     void __attribute__( (interrupt(IPL2AUTO), vector(_TIMER_1_VECTOR))) tmr1_isr(void);
     void __attribute__( (interrupt(IPL2AUTO), vector(_TIMER_2_VECTOR))) tmr2_isr(void);
     void __attribute__( (interrupt(IPL2AUTO), vector(_TIMER_3_VECTOR))) tmr3_isr(void);
     void __attribute__( (interrupt(IPL2AUTO), vector(_TIMER_4_VECTOR))) tmr4_isr(void);
     void __attribute__( (interrupt(IPL2AUTO), vector(_TIMER_5_VECTOR))) tmr5_isr(void);
     
     switch (timerx)
    {
        case 1:
            tmr1_func=tmr_function;
            IFS0bits.T1IF = 0; // Reset timer T1 interrupt flag
            IPC1bits.T1IP = priority; // Interrupt priority (must be in range [1..6]) 
            IEC0bits.T1IE = 1; // Enable timer T1 interrupts 
            break;
        case 2:
            tmr2_func=tmr_function;
            IFS0bits.T2IF = 0; // Reset timer T2 interrupt flag
            IPC2bits.T2IP = priority; // Interrupt priority (must be in range [1..6]) 
            IEC0bits.T2IE = 1; // Enable timer T2 interrupts 
            break;
        case 3:
            tmr3_func=tmr_function;
            IFS0bits.T3IF = 0; // Reset timer T1 interrupt flag
            IPC3bits.T3IP = priority; // Interrupt priority (must be in range [1..6]) 
            IEC0bits.T3IE = 1; // Enable timer T1 interrupts 
            break;
        case 4:
            tmr4_func=tmr_function;
            IFS0bits.T4IF = 0; // Reset timer T1 interrupt flag
            IPC4bits.T4IP = priority; // Interrupt priority (must be in range [1..6]) 
            IEC0bits.T4IE = 1; // Enable timer T1 interrupts 
            break;
        case 5:
            tmr5_func=tmr_function;
            IFS0bits.T5IF = 0; // Reset timer T1 interrupt flag
            IPC5bits.T5IP = priority; // Interrupt priority (must be in range [1..6]) 
            IEC0bits.T5IE = 1; // Enable timer T1 interrupts 
            break;
        default:
            exit(EXIT_FAILURE);
     }
}
/** \brief *tmr1_isr the function that will execute when the interrupt handler 1 is called 
 * the function reset the flag
 * \author Rafael Almeida & Samuel Simoes
 * \date 03-11-2017  
 */
void tmr1_isr(void)
{
    if(tmr1_func != NULL)
    {
        tmr1_func();
        IFS0bits.T1IF = 0; // Reset timer T1 interrupt flag
    }
}
/** \brief *tmr2_isr the function that will execute when the interrupt handler 2 is called.
 * The function reset the flag
 * \return EXIT_FAILURE in case of the argument's conditions are not respected
 * \author Rafael Almeida & Samuel Simoes
 * \date 03-11-2017  
 */
void tmr2_isr(void)
{
    if(tmr2_func != NULL)
    {
        tmr2_func();
        IFS0bits.T2IF = 0; // Reset timer T2 interrupt flag
    }
}
/**\brief *tmr3_isr the function that will execute when the interrupt handler 3 is called.
 * The function reset the flag
 * \author Rafael Almeida & Samuel Simoes
 * \date 03-11-2017  
 */
void tmr3_isr(void)
{
    if(tmr3_func != NULL)
    {
        tmr3_func();
        IFS0bits.T3IF = 0; // Reset timer T3 interrupt flag
    }
}
/** \brief *tmr4_isr the function that will execute when the interrupt handler 4 is called
 * the function reset the flag
 * \author Rafael Almeida & Samuel Simoes
 * \date 03-11-2017  
 */
void tmr4_isr(void)
{
    if(tmr4_func != NULL)
    {
        tmr4_func();
        IFS0bits.T4IF = 0; // Reset timer T4 interrupt flag
    }
}
/** \brief tmr5_isr the function that will execute when the interrupt handler 5 is called
 * the function reset the flag
 * 
 * \author Rafael Almeida & Samuel Simoes
 * \date 03-11-2017  
 */

void tmr5_isr(void)
{
    if(tmr5_func != NULL)
    {
        tmr5_func();
        IFS0bits.T5IF = 0; // Reset timer T5 interrupt flag
    }
}


void tmr_reset_flag(int timerx)
{
         switch (timerx)
    {
        case 1:
              IFS0bits.T1IF = 0; // Reset timer T1 interrupt flag
         break;
        case 2:
              IFS0bits.T2IF = 0; // Reset timer T2 interrupt flag
         break;
        case 3:
              IFS0bits.T3IF = 0; // Reset timer T3 interrupt flag
         break;
        case 4:
              IFS0bits.T4IF = 0; // Reset timer T4 interrupt flag
         break;
        case 5:
              IFS0bits.T5IF = 0; // Reset timer T5 interrupt flag
         break;
         default:
            exit(EXIT_FAILURE);
     }
}

void tmr_OnOff(int timerx, int signal)
{
    switch (timerx)
    {
        case 1:
            T1CONbits.TON = signal; // Enable timer T1 (must be the last command of the // timer configuration sequence)
        break;  
        case 2:
            T2CONbits.TON = signal; // Enable timer T2 (must be the last command of the // timer configuration sequence)
        break;   
        case 3:
            T3CONbits.TON = signal; // Enable timer T3 (must be the last command of the // timer configuration sequence)
        break;   
        case 4:   
            T4CONbits.TON = signal; // Enable timer T4 (must be the last command of the // timer configuration sequence)
        break;  
        case 5:
            T5CONbits.TON = signal; // Enable timer T5 (must be the last command of the // timer configuration sequence)
        break; 
        default:
            exit(EXIT_FAILURE);
    }
}

