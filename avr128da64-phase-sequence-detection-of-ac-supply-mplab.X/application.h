#ifndef XC_APPLICATION_H
#define	XC_APPLICATION_H

/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include <xc.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include "mcc_generated_files/system/system.h"
#include "application_AD5227.h"
#include "application_AD9833.h"
#include "datastreamer.h"
#include "phaseFeatures.h"
#include <util/delay.h>

/******************************************************************************/
/*                                                                            */
/*                            USER DEFINED MACROS                             */
/*                                                                            */
/******************************************************************************/

/* ADC FACTORS */
#define ADC_STEPS_PER_VOLTAGE   (0.00322f)          // 10-bit ADC Step value = (3.3V/1024)
#define ADC_OFFSET_VALUE        (550)               // Practically generated signal offset

/* DATA STREAMER PARAMETERS */
#define START_OF_FRAME          (0x03)              // Data Streamer Start Of Frame (SOF)
#define END_OF_FRAME            (0xFC)              // Data Streamer End Of Frame (EOF)

/* APPLICATION BASED MACROS */
#define EMPTY_BUFFER            (0)

#define REGISTER_SIZE           (2)

#define FLAG_SET                (1)
#define FLAG_RESET              (0)

#define COUNTER_SET             (1)
#define COUNTER_RESET           (0)

#define CHANNEL_B               (0)
#define CHANNEL_G               (1)
#define CHANNEL_R               (2)
#define CHANNEL_COUNT           (3)

#define AMPL_DEC_LIMIT          (9)
#define AMPL_INC_LIMIT          (20)

#define PHASE_LOSS              (0)
#define NO_PHASE_LOSS           (1)

#define PHASE_R                 (1)
#define PHASE_B                 (0)

#define DS_BUFFER_SIZE          (12)

#define CYCLE_COUNT             (30)
#define PH_DETECT_CYCLE_COUNT   (31)

#define CALC_Vrms_CYCLE         (38)

#define NO_PHASE_REV            (0x00)
#define PHASE_REV               (0x01)

#define PHASE_SHIFT_MIN_TIME    (0.003)
#define PHASE_SHIFT_MAX_TIME    (0.008)

#define SWITCH_PRESSED          (SW_GetValue() == false)

/******************************************************************************/
/*                                                                            */
/*                          USER DEFINED STRUCTURES                           */
/*                                                                            */
/******************************************************************************/

/* DATA STREAMER FIELDS */
typedef struct{
	uint8_t start_of_frame;                // 1B
	uint16_t RsignalData;                  // 2B
	uint16_t YsignalData;                  // 2B
	uint16_t BsignalData;                  // 2B
	uint8_t phaseReversalFlag;             // 1B
	uint8_t phaseLossFlag[CHANNEL_COUNT];  // 3B
	uint8_t Opfreq;                        // 1B
	uint8_t end_of_frame;                  // 1B
}DataStreamer_st;

/* DATA STREAMER FRAME CREATION */
typedef union {
	uint8_t  DataStreamer_buffer[12]; 
    DataStreamer_st dataStreamer_st;	
}DataStreamerFrame_u;

/* SIGNAL STATES */
enum SIGNAL_STAGES { 
    RECOVER_S = 0,           
	RMV_R_S = 1,
	RMV_Y_S = 2,
    RMV_B_S,
	PHASE_RVRSL_S
};

/******************************************************************************/
/*                                                                            */
/*                          USER DEFINED VARIABLES                            */
/*                                                                            */
/******************************************************************************/
extern uint8_t freqSelection;
extern uint8_t RxData[2];
extern uint16_t numberofSamples;
extern uint16_t targetedSamples;
extern uint16_t ADC_Results_L[4];
extern float Vrms[3];
extern float frequencyValue;
extern float line_voltage[3];
extern volatile uint8_t phaseRSignalCounter;
extern volatile uint8_t phaseBSignalCounter;
extern volatile uint8_t timer2CounterValue;
extern volatile uint8_t  timer4OverflowFlag;
extern volatile uint32_t refreshCount;
extern volatile uint16_t timer4OvfCnt;
extern volatile uint8_t ZCD_Int_flag[3];
extern volatile uint8_t PhaseLossFlag[CHANNEL_COUNT];
extern DataStreamerFrame_u dataStreamerFrame_u;
extern WfclkSel_st wfclkSel_st;

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DECLARATION                       */
/*                                                                            */
/******************************************************************************/

/**
 * void application(void)
 * 
 * @brief API to run the application. It is scheduled to reproduce the simulated 3 phase signal,
 *        phase loss logic, phase reversal logic, refresh the emulator signal, and receive user
 *        command and execute the commands.
 * 
 * @param None.
 * @return None.
 */
void application(void);

/**
 * void threePhaseAmplitudeMax(void)
 * 
 * @brief API to increase the amplitude of the 3 phase signals (R G B).
 * 
 * @param None.
 * @return None.
 */
void threePhaseAmplitudeMax(void);

/**
 * void threePhaseAmplitudeMin(void)
 * 
 * @brief API to decrease the amplitude of the 3 phase signals (R G B).
 * 
 * @param None.
 * @return None.
 */
void threePhaseAmplitudeMin(void);

/**
 * void defaultSignalGeneration(void)
 * 
 * @brief API to generate default signals for 3 Phase Sequence Detection (PSD) input.
 * 
 * @param None.
 * @return None.
 */
void defaultSignalGeneration(void);

/**
 * void readSwToSelectFrequency(void)
 * 
 * @brief API to read switch press event to accept user input for selecting signal frequency (50/60 Hz).
 * 
 * @param None.
 * @return None.
 */
void readSwToSelectFrequency(void);

/**
 * void frequencySelectionCallBack(void)
 * 
 * @brief API to select the frequency of input signal for the PSD application.
 * 
 * @param userFreqSelection - user input for selecting the frequency
 * @return None.
 */
void frequencySelectionCallBack(uint8_t userFreqSelection);

/**
 * uint16_t waveformAproxPhasecalculation(float phase)
 * 
 * @brief API to calculate the phase value to be set in phase bit field of the AD9833 register.
 * 
 * @param phase - phase to be shifted.
 * @return phase value to be set in the control register.
 */
uint16_t waveformAproxPhasecalculation(float phase);

/**
 * uint32_t waveformAproxFreqcalculation(float frequency)
 * 
 * @brief API to calculate the frequency value to be set in frequency bit field of the AD9833 register.
 * 
 * @param frequency - frequency to be set.
 * @return frequency value to be set in the control register.
 */
uint32_t waveformAproxFreqcalculation(float frequency);

/**
 * void TMR4_UserInterruptHandler(void)
 * 
 * @brief User defined TMR4 interrupt handler.
 * 
 * @param None.
 * @return None.
 */
void TCA1_UserInterruptHandler(void);

/**
 * void ZCD1_UserInterruptHandler(void)
 * 
 * @brief User defined ZCD1 interrupt handler.
 * 
 * @param None.
 * @return None.
 */
void ZCD0_UserInterruptHandler(void);

/**
 * void ZCD2_UserInterruptHandler(void)
 * 
 * @brief User defined ZCD2 interrupt handler.
 * 
 * @param None.
 * @return None.
 */
void ZCD1_UserInterruptHandler(void);

#endif	/* XC_APPLICATION_H */