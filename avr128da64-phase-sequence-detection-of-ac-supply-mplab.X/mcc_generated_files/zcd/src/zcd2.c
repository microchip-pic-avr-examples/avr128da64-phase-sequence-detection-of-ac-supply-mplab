/**
 * ZCD2 Generated Driver File
 *
 * @file zcd2.c
 * 
 * @ingroup zcd2 
 * 
 * @brief This file contains the API implementation for the ZCD2 module.
 * 
 * @version ZCD2 Driver Version 1.0.0
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/


#include "../zcd2.h"

int8_t ZCD2_Initialize(void)
{   
    //INTMODE Interrupt on rising input signal; 
    ZCD2.INTCTRL = 0x1;

    //ENABLE enabled; INVERT disabled; RUNSTDBY disabled; OUTEN disabled; 
    ZCD2.CTRLA = 0x1;
    
    return 0;
}

ISR(ZCD2_ZCD_vect)
{
    /* Insert your ZCD interrupt handling code here */

    /* The interrupt flag has to be cleared manually */
    ZCD2.STATUS = ZCD_CROSSIF_bm;
}
