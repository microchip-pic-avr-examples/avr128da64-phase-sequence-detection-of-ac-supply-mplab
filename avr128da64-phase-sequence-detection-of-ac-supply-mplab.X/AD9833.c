/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include "application.h"
#include "application_AD9833.h"
#include "mcc_generated_files/system/system.h"

/******************************************************************************/
/*                                                                            */
/*                USER DEFINED LOCAL FUNCTION DECLARATION                     */
/*                                                                            */
/******************************************************************************/
static void AD9833_FSN1_set_level(uint8_t level);
static void AD9833_FSN2_set_level(uint8_t level);
static void AD9833_FSN3_set_level(uint8_t level);

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DEFINITIONS                       */
/*                                                                            */
/******************************************************************************/
void AD9833Select(uint8_t selAD9833)
{
	wfclkSel_st.AD9833_sel = selAD9833;
}

void AD9833SetRegisterValue(unsigned short regValue)
{
	unsigned char data[5] = {0x00};	
	
	data[0] = (unsigned char)((regValue & 0xFF00) >> 8);
	data[1] = (unsigned char)((regValue & 0x00FF) >> 0);
	AD9833_CS_LOW;	    
	SPI0_BufferWrite(data,2);
	AD9833_CS_HIGH;
}

void AD9833SetFrequency(unsigned short reg, uint32_t val)
{
	unsigned short freqHi = reg;
	unsigned short freqLo = reg;
	
	freqHi |= (val & 0xFFFC000) >> 14 ;
	freqLo |= (val & 0x3FFF);
	
    AD9833SetRegisterValue(AD9833_B28);
	AD9833SetRegisterValue(freqLo);
	AD9833SetRegisterValue(freqHi);
}

void AD9833SetPhase(unsigned short reg, unsigned short val)
{
	unsigned short phase = reg;
	phase = (phase | val);
	
    AD9833SetRegisterValue(phase);
}

void AD9833Reset(void)
{
    AD9833SetRegisterValue(AD9833_REG_CMD | AD9833_RESET);
}

void AD9833ClearReset(void)
{
	AD9833SetRegisterValue(AD9833_REG_CMD);
}


void AD9833Setup(uint16_t freq, uint16_t phase, uint16_t type)
{
	uint16_t val = 0;
	
	val = freq | phase | type;
	AD9833SetRegisterValue(val);
}

void AD9833_chipSelect(uint8_t selAD9833, uint8_t level)
{ 
    switch(selAD9833)
    {
        case 1:
        AD9833_FSN1_set_level(level);
        break;
        case 2:
        AD9833_FSN2_set_level(level);
        break;
        case 3:
        AD9833_FSN3_set_level(level);
        break;
    }	   
}

static void AD9833_FSN1_set_level(uint8_t level)
{
    if(level)
    {
        AD9833_FSN1_SetHigh();
    }
    else
    {
        AD9833_FSN1_SetLow();
    }
}

static void AD9833_FSN2_set_level(uint8_t level)
{
    if(level)
    {
        AD9833_FSN2_SetHigh();
    }
    else
    {
        AD9833_FSN2_SetLow();
    }
}

static void AD9833_FSN3_set_level(uint8_t level)
{
    if(level)
    {
        AD9833_FSN3_SetHigh();
    }
    else
    {
        AD9833_FSN3_SetLow();
    }
}