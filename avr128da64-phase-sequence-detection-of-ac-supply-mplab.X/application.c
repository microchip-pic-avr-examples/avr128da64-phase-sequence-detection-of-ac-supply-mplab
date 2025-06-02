/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "application.h"

/******************************************************************************/
/*                                                                            */
/*                             USER DEFINED VARIABLES                         */
/*                                                                            */
/******************************************************************************/
uint8_t freqSelection = DeFHz;
uint8_t RxData[2] = {EMPTY_BUFFER};
uint16_t numberofSamples = 0;
uint16_t targetedSamples = 35;
uint16_t ADC_Results_L[4] = {EMPTY_BUFFER};
float Vrms[3] = {0.00};
float frequencyValue = DEFAULT_FREQ_50Hz;
float line_voltage[3] = {EMPTY_BUFFER};
volatile uint8_t phaseRSignalCounter;
volatile uint8_t phaseBSignalCounter;
volatile uint8_t timer2CounterValue;
volatile uint8_t  timer4OverflowFlag = 0;
volatile uint32_t refreshCount       = 0;
volatile uint16_t timer4OvfCnt       = 0;
volatile uint8_t ZCD_Int_flag[3];
volatile uint8_t PhaseLossFlag[CHANNEL_COUNT];
DataStreamerFrame_u dataStreamerFrame_u;
WfclkSel_st wfclkSel_st;

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DEFINITIONS                       */
/*                                                                            */
/******************************************************************************/
void application(void)
{
    if(timer4OverflowFlag  == FLAG_SET)
    {
	   timer4OverflowFlag = FLAG_RESET;       
	   read3PhaseSignal();                      // Read three-phase signal using ADC 
       createDataStreamProtocolAndSend();       // Create data to data streamer protocol format and send to data visualizer via USART
       phaseLossDetectionStatus();              // Phase loss detection 
       phaseReversalDetection();                // Phase reversal detection   
       calculateVrms();                         // Calculate Vrms (***Note - timeOverflow counter is reseted in this function)
    }
    
    if (refreshCount >= REFRESH_COUNT)
	{
	   refreshCount = 0;
	   emulatorTaskProcess(RECOVER_S);               //refreshing simulated 3phase signal for stabilized signal on screen	
	}
	
	if(USART1_IsRxReady())
	{
		for (int i=0;i<=1;i++)                      //reading two bytes from the data visualizer
		{
			RxData[i] = USART1_Read();
		}
		refreshCount = 0;                      //reseting the refresh count when user is operating the system
		timer4OverflowFlag = 0;               //explicitly reseting to avoid case 7 when simulation command received
		emulatorTaskProcess(RxData[1]);                  
	}
}

void threePhaseAmplitudeMax(void)
{
	uint8_t i,j = 0;	
	for (i=1;i<=CHANNEL_COUNT;i++)              // Increase R Y B phase amplitude 
	{
		for (j=0;j<=AMPL_INC_LIMIT;j++)
		{
			AD5227Select(i);
			AD5227DigipotInc();
		}
	}
}

void threePhaseAmplitudeMin(void)
{
	uint8_t i,j = 0;	
	for (i=1;i<=CHANNEL_COUNT;i++)              // Decrease R Y B phase amplitude 
	{
		for (j=0;j<=AMPL_DEC_LIMIT;j++)
		{
			AD5227Select(i);
			AD5227DigipotDec();
		}
	}
}

uint32_t waveformAproxFreqcalculation(float frequency)
{
	uint32_t calculation = 0;
	
	calculation =(uint32_t)(frequency * ( WAVEFORM_CONSTANT / WAVEFORM_OSC_FREQ ));	
	return calculation;
}

uint16_t waveformAproxPhasecalculation(float phase)
{
	uint16_t calculation = 0;
	
	calculation = (uint16_t)(phase * BITS_PER_DEG);  	
	return calculation;
}

void defaultSignalGeneration(void)
{
	sineWaveGeneration(WfClickSG_1, frequencyValue, PHASE_SHIFT_0Deg);              // Default frequency generation 
	sineWaveGeneration(WfClickSG_2, frequencyValue, PHASE_SHIFT_120Deg);
	sineWaveGeneration(WfClickSG_3, frequencyValue, PHASE_SHIFT_240Deg);	
}

void readSwToSelectFrequency(void)
{
	uint8_t freq_toggle_flag = 0;
	
    while (timer4OvfCnt <= SWITCH_TIME_COUNT)                                   // Using timer1 and waiting for user to select the frequency
	{                                                                           // If user not select any frequency, default (50Hz) will be used
		if (SWITCH_PRESSED)                                                     // Read switch 
		{
			timer4OvfCnt     = COUNTER_RESET;
			freq_toggle_flag = ~freq_toggle_flag;
			frequencySelectionCallBack(freq_toggle_flag);
			_delay_ms(500);
		}
	}
}

void frequencySelectionCallBack(uint8_t userFreqSelection)
{
	if (userFreqSelection)
	{
		freqSelection   = F60Hz;	
		frequencyValue  = DEFAULT_FREQ_60Hz;
        targetedSamples = NUMBER_OF_SAMPLES_60Hz;
	}
	else
	{
		freqSelection   = F50Hz;
		frequencyValue  = DEFAULT_FREQ_50Hz;
        targetedSamples = NUMBER_OF_SAMPLES_50Hz;
	}
	createDataStreamProtocolAndSend();
}

void TCA1_UserInterruptHandler(void)
{
    timer4OverflowFlag = FLAG_SET;
    timer4OvfCnt++;
	refreshCount++;
    phaseRSignalCounter++;
    phaseBSignalCounter++;
}

void ZCD0_UserInterruptHandler(void)
{    
    TCA1_CounterSet(0);
    ZCD_Int_flag[PHASE_B]  = FLAG_SET;
	PhaseLossFlag[PHASE_B] = FLAG_SET;
    phaseRSignalCounter = COUNTER_RESET;
}

void ZCD1_UserInterruptHandler(void)
{
    if (ZCD_Int_flag[PHASE_B] == FLAG_SET)
    {
	    timer2CounterValue  = TCA1_CounterGet();
        ZCD_Int_flag[PHASE_B] = FLAG_RESET;
    }
    ZCD_Int_flag[PHASE_R] = FLAG_SET;
    PhaseLossFlag[CHANNEL_G] = FLAG_SET;
    phaseBSignalCounter = COUNTER_RESET;
}