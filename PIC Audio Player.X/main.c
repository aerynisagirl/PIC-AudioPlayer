/***********************************************************************************
 *  PIC Audio Player - A simple single chip solution to playing small audio files  *
 *  Created by mikemadealarms on April 13, 2016 at 3:20 PM                         *
 * ------------------------------------------------------------------------------- *
 *  Last modification by mikemadealarms on April 17, 2016 at 12:25 PM              *
 *  Last modification made was: Added in the code used for audio playback          *
 ***********************************************************************************/

#include <xc.h>

#include "sound.h"

/***********************
 *  MCU Configuration  *
 ***********************/

//CONFIG1 Register
#pragma config FOSC = INTOSC   //Set the PIC MCU to use the internal oscillator as a clock source
#pragma config WDTE = OFF      //Disable the watch-dog timer as it is not necessary
#pragma config PWRTE = OFF     //Disable the power up timer as it is not necessary
#pragma config MCLRE = ON      //Enable the MCLRE function linked to PORTA3 on the PIC MCU
#pragma config CP = OFF        //Disable code protection as this is completely pointless for this application
#pragma config CPD = OFF       //Disable data protection as this is completely pointless for this application
#pragma config BOREN = ON      //Enable the brown out reset function on the PIC MCU
#pragma config CLKOUTEN = OFF  //Disable the clock out function linked to PORTA on the PIC MCU
#pragma config IESO = ON       //Enable the use of the internal/external clock switchover
#pragma config FCMEN = ON      //Enable the fail safe clock monitor module on the PIC MCU

//CONFIG2 Register
#pragma config WRT = OFF    //Disable the flash re-write protection as it is completely pointless for this application
#pragma config PLLEN = OFF  //Disable the internal 4x PLL multiplier as a high frequency clock is not needed
#pragma config STVREN = ON  //Enable the stack under/over flow reset function on the PIC MCU
#pragma config BORV = LO    //Set the point at which the brown out reset is triggered to the low trip point
#pragma config LVP = OFF    //Disable the low voltage programming feature as I have a high voltage programmer

/***************
 *  Variables  *
 ***************/

//Audio Control
unsigned char isAudioPlaying = 0x00;      //Controls whether or not the audio sample is playing
unsigned short currentSample = 0x0000;    //The current sample of the audio recording being outputted
unsigned char currentSampleValue = 0x00;  //The value of the current sample that is being outputted

/****************
 *  Processing  *
 ****************/

//Setup Function, initializes the MCU and prepares it for the various tasks it will perform
void setup() {
    //Configure Timing Related Modules
    OSCCON = 0x70;      //Set the internal oscillator to run at 8MHz and disable the internal 4x PLL
    OPTION_REG = 0x5F;  //Enable the use of the 20K ohm internal pull-up resistors and enable Timer0
    
    //Configure IO Related Modules and IO Ports
    TRISA = 0x3F;   //Set all of PORTA to inputs
    ANSELA = 0x00;  //Set all of PORTA to digital IO rather than analog inputs
    WPUA = 0x10;    //Enable the 20K ohm internal weak pull-up resistor on PORTA4
    LATA = 0x00;    //Clear LATA so none of PORTA is in the logic high state
    
    TRISC = 0x3F;   //Set all of PORTC to inputs, this disables output to PORTC5 which is used to drive the speaker for playback
    ANSELC = 0x00;  //Set all of PORTC to digital IO rather than analog inputs
    WPUC = 0x00;    //Disable the 20K ohm internal weak pull-up resistors on all of PORTC
    LATC = 0x00;    //Clear LATC so none of PORTC is in the logic high state
    
    //Configure PWM Related Registers
    CCPTMRS = 0x00;  //Set all the CCP modules to use Timer2 for running in PWM
    PR2 = 0x4F;      //Set the Timer2 comparator value to trigger the interrupt used by the CCP 1 module
    CCP1CON = 0x0C;  //Configure the CCP 1 module on the PIC MCU to run in single output active-high PWM mode
    T2CON = 0x04;    //Configure and enable Timer2 to run with no pre and post scaler
    
    //Configure Interrupt Related Registers
    INTCON = 0xA8;  //Configure interrupts to be triggered from Timer0 overflowing, and interrupt on change triggers from PORTA
    IOCAP = 0x00;   //Disable all positive edge interrupt on change triggers on PORTA
    IOCAN = 0x10;   //Enable the negative edge interrupt on change trigger on PORTA4 and disable it for the rest of PORTA
    IOCAF = 0x00;   //Clear all the interrupt on change flags for PORTA
    
    //Initialize Variables
    isAudioPlaying = 0x00;  //Clear the variable isAudioPlaying to prevent the audio sample from playing
    currentSample = 0x000;  //Clear the variable so the audio sample is played from the beginning.
}

//Main Function, called upon reset of the PIC MCU
void main() {
    setup();  //Call setup function to initialize the PIC MCU
    
    //Run in a continuous loop until the end of time (Or the PIC MCU is reset)
    while (1) {
        //Do absolutely nothing
    }
}

/****************
 *  Interrupts  *
 ****************/

//Interrupt Function, called upon the occurrence of an interrupt to the PIC MCU
void interrupt onInterrupt() {
    //Check to see if the interrupt was caused by Timer0 overflowing
    if (TMR0IF) {
        TMR0IF = 0x00;  //Clear the Timer0 overflow interrupt flag to prevent false interrupts in the future
        
        //Check to see if the audio sample is playing
        if (isAudioPlaying) {
            //Check to see if all of the samples in the audio recording have been played
            if (currentSample != TOTAL_SAMPLES) {
                //Fetch the next sample that is to be outputted to the speaker
                currentSampleValue = sound[currentSample];  //Update the register that contains the value of the current sample that will be outputted
                currentSample++;                            //Increment the counter that is used to keep track of which sample is to be played next by 1

                //Output the new value of the current sample to the PWM portion of the CCP1 module
                CCP1CONbits.DC1B = currentSampleValue;  //Write the 2 lowest significant bits of the current samples value to the register that contains the 2 lowest significant bits of the PWM duty cycle
                CCPR1L = currentSampleValue >> 2;       //Write the rest of the bits to the register containing the 6 highest significant bits that control the PWM duty cycle
            } else {
                //Stop the playback of the audio sample
                isAudioPlaying = 0x00;      //Clear the variable that controls whether the audio sample is playing so that the program knows the audio sample is not playing
                currentSample = 0x00;       //Clear the variable so that the audio sample is played from the beginning
                currentSampleValue = 0x00;  //Clear the variable that stores the PWM duty cycle so that it's on no duty cycle
                
                //Disable the audio driver
                TRISC5 = 0x01;  //Set PORTC5 to an input to disable the CCP1 module from outputting a PWM signal to the speaker used for playback
            }
        }
    }
    
    //Check to see if the interrupt was caused by PORTA4 triggering an interrupt from a falling edge
    if (IOCAF4) {
        IOCAF4 = 0x00;  //Clear the interrupt on change flag for PORTA4 to prevent false interrupts in the future
        
        //Check to see if the audio sample isn't already being played
        if (!isAudioPlaying) {
            //Prepare the CPU for playback of the audio sample
            isAudioPlaying = 0xFF;  //Write to the variable that controls whether the audio sample plays so that the audio sample will begin to play
            currentSample = 0x00;       //Clear the variable so that the audio sample is played from the beginning
            currentSampleValue = 0x00;  //Clear the variable that stores the PWM duty cycle so that it's on no duty cycle
            
            //Enable the audio driver
            TRISC5 = 0x00;  //Set PORTC5 to an output to enable the CCP1 module to output a PWM signal to PORTC5, this drives the speaker used for playback
        }
    }
}