/***********************************************************************************
 *  PIC Audio Player - A simple single chip solution to playing small audio files  *
 *  Created by mikemadealarms on April 13, 2016 at 3:20 PM                         *
 * ------------------------------------------------------------------------------- *
 *  Last modification by mikemadealarms on April 16, 2016 at 9:12 AM               *
 *  Last modification made was: Made some minor changes to the setup function      *
 ***********************************************************************************/

#include <xc.h>

/***********************
 *  MCU Configuration  *
 ***********************/

//CONFIG1 Register
#pragma config FOSC = INTOSC   //Set the PIC MCU to use the internal oscillator as a clock source.
#pragma config WDTE = OFF      //Disable the watch-dog timer as it is not necessary.
#pragma config PWRTE = OFF     //Disable the power up timer as it is not necessary.
#pragma config MCLRE = ON      //Enable the MCLRE function linked to PORTA3 on the PIC MCU.
#pragma config CP = OFF        //Disable code protection as this is completely pointless for this application.
#pragma config CPD = OFF       //Disable data protection as this is completely pointless for this application.
#pragma config BOREN = ON      //Enable the brown out reset function on the PIC MCU.
#pragma config CLKOUTEN = OFF  //Disable the clock out function linked to PORTA on the PIC MCU.
#pragma config IESO = ON       //Enable the use of the internal/external clock switchover.
#pragma config FCMEN = ON      //Enable the fail safe clock monitor module on the PIC MCU.

//CONFIG2 Register
#pragma config WRT = OFF    //Disable the flash re-write protection as it is completely pointless for this application.
#pragma config PLLEN = OFF  //Disable the internal 4x PLL multiplier as a high frequency clock is not needed.
#pragma config STVREN = ON  //Enable the stack under/over flow reset function on the PIC MCU.
#pragma config BORV = LO    //Set the point at which the brown out reset is triggered to the low trip point.
#pragma config LVP = OFF    //Disable the low voltage programming feature as I have a high voltage programmer.

/****************
 *  Processing  *
 ****************/

//Setup Function, initializes the MCU and prepares it for the various tasks it will perform.
void setup() {
    //Configure Timing Related Modules
    OSCCON = 0x70;      //Set the internal oscillator to run at 8MHz and disable the internal 4x PLL.
    OPTION_REG = 0x5F;  //Enable the use of the 20K ohm internal pull-up resistors and enable Timer0.
    
    //Configure IO Related Modules and IO Ports
    TRISA = 0x39;   //Set PORTA1 and PORTA2 to outputs and leave the rest as inputs.
    ANSELA = 0x00;  //Set all of PORTA to digital IO rather than analog inputs.
    WPUA = 0x01;    //Enable the 20K ohm internal weak pull-up resistor on PORTA0.
    LATA = 0x00;    //Clear LATA so none of PORTA is in the logic high state.
    
    
}

//Main Function, called upon reset of the PIC MCU.
void main() {
    setup();  //Call setup function to initialize the PIC MCU.
    
    //Run in a continuous loop until the end of time (Or the PIC MCU is reset).
}

/****************
 *  Interrupts  *
 ****************/