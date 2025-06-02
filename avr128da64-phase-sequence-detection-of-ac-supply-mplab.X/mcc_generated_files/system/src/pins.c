/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 1.1.0
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

#include "../pins.h"

static void (*IO_PC4_InterruptHandler)(void);
static void (*IO_PC5_InterruptHandler)(void);
static void (*IO_PC6_InterruptHandler)(void);
static void (*IO_PA0_InterruptHandler)(void);
static void (*IO_PA1_InterruptHandler)(void);
static void (*IO_PA2_InterruptHandler)(void);
static void (*IO_PA5_InterruptHandler)(void);
static void (*IO_PA4_InterruptHandler)(void);
static void (*IO_PA6_InterruptHandler)(void);
static void (*IO_PC1_InterruptHandler)(void);
static void (*IO_PC0_InterruptHandler)(void);
static void (*IO_PD1_InterruptHandler)(void);
static void (*IO_PE7_InterruptHandler)(void);
static void (*IO_PE3_InterruptHandler)(void);
static void (*AD5227_CS1_InterruptHandler)(void);
static void (*AD5227_CS3_InterruptHandler)(void);
static void (*WC_OE2_InterruptHandler)(void);
static void (*SW_InterruptHandler)(void);
static void (*WC_OE1_InterruptHandler)(void);
static void (*WC_OE3_InterruptHandler)(void);
static void (*AD9833_FSN1_InterruptHandler)(void);
static void (*AD9833_FSN3_InterruptHandler)(void);
static void (*AD5227_CS2_InterruptHandler)(void);
static void (*AD9833_FSN2_InterruptHandler)(void);

void PIN_MANAGER_Initialize()
{

  /* OUT Registers Initialization */
    PORTA.OUT = 0x0;
    PORTB.OUT = 0x0;
    PORTC.OUT = 0x1;
    PORTD.OUT = 0x0;
    PORTE.OUT = 0x0;
    PORTF.OUT = 0x0;
    PORTG.OUT = 0x0;

  /* DIR Registers Initialization */
    PORTA.DIR = 0x57;
    PORTB.DIR = 0x0;
    PORTC.DIR = 0x71;
    PORTD.DIR = 0x0;
    PORTE.DIR = 0x0;
    PORTF.DIR = 0x0;
    PORTG.DIR = 0x0;

  /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x0;
    PORTA.PIN1CTRL = 0x0;
    PORTA.PIN2CTRL = 0x0;
    PORTA.PIN3CTRL = 0x0;
    PORTA.PIN4CTRL = 0x0;
    PORTA.PIN5CTRL = 0x0;
    PORTA.PIN6CTRL = 0x0;
    PORTA.PIN7CTRL = 0x0;
    PORTB.PIN0CTRL = 0x0;
    PORTB.PIN1CTRL = 0x0;
    PORTB.PIN2CTRL = 0x0;
    PORTB.PIN3CTRL = 0x0;
    PORTB.PIN4CTRL = 0x0;
    PORTB.PIN5CTRL = 0x0;
    PORTB.PIN6CTRL = 0x0;
    PORTB.PIN7CTRL = 0x0;
    PORTC.PIN0CTRL = 0x0;
    PORTC.PIN1CTRL = 0x0;
    PORTC.PIN2CTRL = 0x0;
    PORTC.PIN3CTRL = 0x0;
    PORTC.PIN4CTRL = 0x0;
    PORTC.PIN5CTRL = 0x0;
    PORTC.PIN6CTRL = 0x0;
    PORTC.PIN7CTRL = 0x8;
    PORTD.PIN0CTRL = 0x0;
    PORTD.PIN1CTRL = 0x4;
    PORTD.PIN2CTRL = 0x0;
    PORTD.PIN3CTRL = 0x0;
    PORTD.PIN4CTRL = 0x0;
    PORTD.PIN5CTRL = 0x0;
    PORTD.PIN6CTRL = 0x0;
    PORTD.PIN7CTRL = 0x0;
    PORTE.PIN0CTRL = 0x0;
    PORTE.PIN1CTRL = 0x0;
    PORTE.PIN2CTRL = 0x0;
    PORTE.PIN3CTRL = 0x4;
    PORTE.PIN4CTRL = 0x0;
    PORTE.PIN5CTRL = 0x0;
    PORTE.PIN6CTRL = 0x0;
    PORTE.PIN7CTRL = 0x4;
    PORTF.PIN0CTRL = 0x0;
    PORTF.PIN1CTRL = 0x0;
    PORTF.PIN2CTRL = 0x0;
    PORTF.PIN3CTRL = 0x0;
    PORTF.PIN4CTRL = 0x0;
    PORTF.PIN5CTRL = 0x0;
    PORTF.PIN6CTRL = 0x0;
    PORTF.PIN7CTRL = 0x0;
    PORTG.PIN0CTRL = 0x0;
    PORTG.PIN1CTRL = 0x0;
    PORTG.PIN2CTRL = 0x0;
    PORTG.PIN3CTRL = 0x0;
    PORTG.PIN4CTRL = 0x0;
    PORTG.PIN5CTRL = 0x0;
    PORTG.PIN6CTRL = 0x0;
    PORTG.PIN7CTRL = 0x0;

  /* PORTMUX Initialization */
    PORTMUX.ACROUTEA = 0x0;
    PORTMUX.CCLROUTEA = 0x0;
    PORTMUX.EVSYSROUTEA = 0x0;
    PORTMUX.SPIROUTEA = 0x0;
    PORTMUX.TCAROUTEA = 0x8;
    PORTMUX.TCBROUTEA = 0x0;
    PORTMUX.TCDROUTEA = 0x0;
    PORTMUX.TWIROUTEA = 0x0;
    PORTMUX.USARTROUTEA = 0x0;
    PORTMUX.USARTROUTEB = 0x0;
    PORTMUX.ZCDROUTEA = 0x0;

  // register default ISC callback functions at runtime; use these methods to register a custom function
    IO_PC4_SetInterruptHandler(IO_PC4_DefaultInterruptHandler);
    IO_PC5_SetInterruptHandler(IO_PC5_DefaultInterruptHandler);
    IO_PC6_SetInterruptHandler(IO_PC6_DefaultInterruptHandler);
    IO_PA0_SetInterruptHandler(IO_PA0_DefaultInterruptHandler);
    IO_PA1_SetInterruptHandler(IO_PA1_DefaultInterruptHandler);
    IO_PA2_SetInterruptHandler(IO_PA2_DefaultInterruptHandler);
    IO_PA5_SetInterruptHandler(IO_PA5_DefaultInterruptHandler);
    IO_PA4_SetInterruptHandler(IO_PA4_DefaultInterruptHandler);
    IO_PA6_SetInterruptHandler(IO_PA6_DefaultInterruptHandler);
    IO_PC1_SetInterruptHandler(IO_PC1_DefaultInterruptHandler);
    IO_PC0_SetInterruptHandler(IO_PC0_DefaultInterruptHandler);
    IO_PD1_SetInterruptHandler(IO_PD1_DefaultInterruptHandler);
    IO_PE7_SetInterruptHandler(IO_PE7_DefaultInterruptHandler);
    IO_PE3_SetInterruptHandler(IO_PE3_DefaultInterruptHandler);
    AD5227_CS1_SetInterruptHandler(AD5227_CS1_DefaultInterruptHandler);
    AD5227_CS3_SetInterruptHandler(AD5227_CS3_DefaultInterruptHandler);
    WC_OE2_SetInterruptHandler(WC_OE2_DefaultInterruptHandler);
    SW_SetInterruptHandler(SW_DefaultInterruptHandler);
    WC_OE1_SetInterruptHandler(WC_OE1_DefaultInterruptHandler);
    WC_OE3_SetInterruptHandler(WC_OE3_DefaultInterruptHandler);
    AD9833_FSN1_SetInterruptHandler(AD9833_FSN1_DefaultInterruptHandler);
    AD9833_FSN3_SetInterruptHandler(AD9833_FSN3_DefaultInterruptHandler);
    AD5227_CS2_SetInterruptHandler(AD5227_CS2_DefaultInterruptHandler);
    AD9833_FSN2_SetInterruptHandler(AD9833_FSN2_DefaultInterruptHandler);
}

/**
  Allows selecting an interrupt handler for IO_PC4 at application runtime
*/
void IO_PC4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PC4_InterruptHandler = interruptHandler;
}

void IO_PC4_DefaultInterruptHandler(void)
{
    // add your IO_PC4 interrupt custom code
    // or set custom function using IO_PC4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PC5 at application runtime
*/
void IO_PC5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PC5_InterruptHandler = interruptHandler;
}

void IO_PC5_DefaultInterruptHandler(void)
{
    // add your IO_PC5 interrupt custom code
    // or set custom function using IO_PC5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PC6 at application runtime
*/
void IO_PC6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PC6_InterruptHandler = interruptHandler;
}

void IO_PC6_DefaultInterruptHandler(void)
{
    // add your IO_PC6 interrupt custom code
    // or set custom function using IO_PC6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PA0 at application runtime
*/
void IO_PA0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PA0_InterruptHandler = interruptHandler;
}

void IO_PA0_DefaultInterruptHandler(void)
{
    // add your IO_PA0 interrupt custom code
    // or set custom function using IO_PA0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PA1 at application runtime
*/
void IO_PA1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PA1_InterruptHandler = interruptHandler;
}

void IO_PA1_DefaultInterruptHandler(void)
{
    // add your IO_PA1 interrupt custom code
    // or set custom function using IO_PA1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PA2 at application runtime
*/
void IO_PA2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PA2_InterruptHandler = interruptHandler;
}

void IO_PA2_DefaultInterruptHandler(void)
{
    // add your IO_PA2 interrupt custom code
    // or set custom function using IO_PA2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PA5 at application runtime
*/
void IO_PA5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PA5_InterruptHandler = interruptHandler;
}

void IO_PA5_DefaultInterruptHandler(void)
{
    // add your IO_PA5 interrupt custom code
    // or set custom function using IO_PA5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PA4 at application runtime
*/
void IO_PA4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PA4_InterruptHandler = interruptHandler;
}

void IO_PA4_DefaultInterruptHandler(void)
{
    // add your IO_PA4 interrupt custom code
    // or set custom function using IO_PA4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PA6 at application runtime
*/
void IO_PA6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PA6_InterruptHandler = interruptHandler;
}

void IO_PA6_DefaultInterruptHandler(void)
{
    // add your IO_PA6 interrupt custom code
    // or set custom function using IO_PA6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PC1 at application runtime
*/
void IO_PC1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PC1_InterruptHandler = interruptHandler;
}

void IO_PC1_DefaultInterruptHandler(void)
{
    // add your IO_PC1 interrupt custom code
    // or set custom function using IO_PC1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PC0 at application runtime
*/
void IO_PC0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PC0_InterruptHandler = interruptHandler;
}

void IO_PC0_DefaultInterruptHandler(void)
{
    // add your IO_PC0 interrupt custom code
    // or set custom function using IO_PC0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PD1 at application runtime
*/
void IO_PD1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PD1_InterruptHandler = interruptHandler;
}

void IO_PD1_DefaultInterruptHandler(void)
{
    // add your IO_PD1 interrupt custom code
    // or set custom function using IO_PD1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PE7 at application runtime
*/
void IO_PE7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PE7_InterruptHandler = interruptHandler;
}

void IO_PE7_DefaultInterruptHandler(void)
{
    // add your IO_PE7 interrupt custom code
    // or set custom function using IO_PE7_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PE3 at application runtime
*/
void IO_PE3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PE3_InterruptHandler = interruptHandler;
}

void IO_PE3_DefaultInterruptHandler(void)
{
    // add your IO_PE3 interrupt custom code
    // or set custom function using IO_PE3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AD5227_CS1 at application runtime
*/
void AD5227_CS1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AD5227_CS1_InterruptHandler = interruptHandler;
}

void AD5227_CS1_DefaultInterruptHandler(void)
{
    // add your AD5227_CS1 interrupt custom code
    // or set custom function using AD5227_CS1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AD5227_CS3 at application runtime
*/
void AD5227_CS3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AD5227_CS3_InterruptHandler = interruptHandler;
}

void AD5227_CS3_DefaultInterruptHandler(void)
{
    // add your AD5227_CS3 interrupt custom code
    // or set custom function using AD5227_CS3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for WC_OE2 at application runtime
*/
void WC_OE2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    WC_OE2_InterruptHandler = interruptHandler;
}

void WC_OE2_DefaultInterruptHandler(void)
{
    // add your WC_OE2 interrupt custom code
    // or set custom function using WC_OE2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for SW at application runtime
*/
void SW_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    SW_InterruptHandler = interruptHandler;
}

void SW_DefaultInterruptHandler(void)
{
    // add your SW interrupt custom code
    // or set custom function using SW_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for WC_OE1 at application runtime
*/
void WC_OE1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    WC_OE1_InterruptHandler = interruptHandler;
}

void WC_OE1_DefaultInterruptHandler(void)
{
    // add your WC_OE1 interrupt custom code
    // or set custom function using WC_OE1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for WC_OE3 at application runtime
*/
void WC_OE3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    WC_OE3_InterruptHandler = interruptHandler;
}

void WC_OE3_DefaultInterruptHandler(void)
{
    // add your WC_OE3 interrupt custom code
    // or set custom function using WC_OE3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AD9833_FSN1 at application runtime
*/
void AD9833_FSN1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AD9833_FSN1_InterruptHandler = interruptHandler;
}

void AD9833_FSN1_DefaultInterruptHandler(void)
{
    // add your AD9833_FSN1 interrupt custom code
    // or set custom function using AD9833_FSN1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AD9833_FSN3 at application runtime
*/
void AD9833_FSN3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AD9833_FSN3_InterruptHandler = interruptHandler;
}

void AD9833_FSN3_DefaultInterruptHandler(void)
{
    // add your AD9833_FSN3 interrupt custom code
    // or set custom function using AD9833_FSN3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AD5227_CS2 at application runtime
*/
void AD5227_CS2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AD5227_CS2_InterruptHandler = interruptHandler;
}

void AD5227_CS2_DefaultInterruptHandler(void)
{
    // add your AD5227_CS2 interrupt custom code
    // or set custom function using AD5227_CS2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AD9833_FSN2 at application runtime
*/
void AD9833_FSN2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AD9833_FSN2_InterruptHandler = interruptHandler;
}

void AD9833_FSN2_DefaultInterruptHandler(void)
{
    // add your AD9833_FSN2 interrupt custom code
    // or set custom function using AD9833_FSN2_SetInterruptHandler()
}
ISR(PORTA_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTA.INTFLAGS & PORT_INT0_bm)
    {
       IO_PA0_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT1_bm)
    {
       IO_PA1_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT2_bm)
    {
       IO_PA2_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT5_bm)
    {
       IO_PA5_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT4_bm)
    {
       IO_PA4_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT6_bm)
    {
       IO_PA6_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT7_bm)
    {
       AD5227_CS1_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTA.INTFLAGS = 0xff;
}

ISR(PORTB_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTB.INTFLAGS & PORT_INT4_bm)
    {
       AD5227_CS3_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT5_bm)
    {
       WC_OE2_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTB.INTFLAGS = 0xff;
}

ISR(PORTC_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTC.INTFLAGS & PORT_INT4_bm)
    {
       IO_PC4_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT5_bm)
    {
       IO_PC5_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT6_bm)
    {
       IO_PC6_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT1_bm)
    {
       IO_PC1_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT0_bm)
    {
       IO_PC0_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT7_bm)
    {
       SW_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTC.INTFLAGS = 0xff;
}

ISR(PORTD_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTD.INTFLAGS & PORT_INT1_bm)
    {
       IO_PD1_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT0_bm)
    {
       WC_OE1_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT2_bm)
    {
       WC_OE3_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT7_bm)
    {
       AD9833_FSN1_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTD.INTFLAGS = 0xff;
}

ISR(PORTE_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTE.INTFLAGS & PORT_INT7_bm)
    {
       IO_PE7_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT3_bm)
    {
       IO_PE3_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT1_bm)
    {
       AD9833_FSN3_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT2_bm)
    {
       AD5227_CS2_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTE.INTFLAGS = 0xff;
}

ISR(PORTF_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTF.INTFLAGS & PORT_INT3_bm)
    {
       AD9833_FSN2_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTF.INTFLAGS = 0xff;
}

ISR(PORTG_PORT_vect)
{ 
    /* Clear interrupt flags */
    VPORTG.INTFLAGS = 0xff;
}

/**
 End of File
*/