<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Phase Sequence Detection of Three-Phase AC Supply


The AVR® DA family of microcontrollers are peripheral rich, high performance and low-power 8-bit microcontroller devices. The built-in Zero-Cross Detector (ZCD), high resolution Analog-to-Digital Converter (ADC), timer peripherals are essential for realizing phase sequence detection applications.

The application demonstrator showcases the phase sequence detection and phase loss detection on emulated three phase AC supply using AVR128DA64 microcontroller.

## Application Note  
Phase Sequence Detection of Three-Phase AC Supply demonstration and implementation is discussed in the <a href="https://microchip.com/DS00003607" rel="nofollow">Phase Sequence Detection of Three-Phase AC Supply Application Note.</a>

## Application Firmware

The demonstration is implemented with both AVR128DA64 and AVR128DA48 microcontrollers and it is available on microchip GitHub page-

* <a href="https://github.com/microchip-pic-avr-examples/avr128da48-phase-sequence-detection-of-ac-supply-mplab" rel="nofollow">AVR128DA48 Phase Sequence Detection application code example using MPLAB</a>
* <a href="https://github.com/microchip-pic-avr-examples/avr128da48-phase-sequence-detection-of-ac-supply-studio" rel="nofollow">AVR128DA48 Phase Sequence Detection application code example using Atmel Studio</a>
* <a href="https://github.com/microchip-pic-avr-examples/avr128da64-phase-sequence-detection-of-ac-supply-studio" rel="nofollow">AVR128DA64 Phase Sequence Detection application code example using Atmel studio</a>

## Software Tools Used 

This application uses MPLAB® X IDE compiler and graphical code generator to provide an easy and hassle-free user experience.

The following tools are used for this demo application:
Following are the tools which are used for this demo application:
* <a href="https://www.microchip.com/mplab/mplab-x-ide" rel="nofollow">MPLAB® X IDE</a> v6.25 or newer
* <a href="https://www.microchip.com/mplab/compilers" rel="nofollow">XC8 compiler</a> v3.00 or newer
* <a href="https://www.microchip.com/mplab/mplab-code-configurator" rel="nofollow">MPLAB® Code Configurator</a> v5.5.3 or newer
* <a href="https://packs.download.microchip.com" rel="nofollow">Microchip AVR-Dx Series Device Support</a> v2.7.321 or newer
* <a href="https://www.microchip.com/mplab/avr-support/data-visualizer" rel="nofollow">MPLAB® Data Visualizer</a> v1.4.1926 or newer
* ADC MCC Melody Driver 5.0.0
* SPI MCC Melody Driver 5.1.0
* TCA MCC Melody Driver 7.1.0
* USART MCC Melody Driver 10.2.1
* VREF MCC Melody Driver 4.1.0
* ZCD MCC Melody Driver 4.0.4

## Hardware Used

* <a href="https://www.microchip.com/en-us/product/avr128da64" rel="nofollow">AVR128DA64</a>
* <a href="https://www.microchip.com/developmenttools/ProductDetails/AC164162" rel="nofollow">Curiosity Nano base for click boards</a>
* <a href="https://www.mikroe.com/waveform-click" rel="nofollow">Waveform Clicks</a>
* SMA male cable
* <a href="http://ww1.microchip.com/downloads/en/DeviceDoc/STK600-AVR-Flash-MCU-Starter-Kit-Users-Guide-DS40001904D.pdf" rel="nofollow">STK600 Board</a>
* <a href="https://www.microchip.com/Developmenttools/ProductDetails/ATSTK600-SC14" rel="nofollow">Socket card</a> (STK600 TQFP64-2)
* Routing card (STK600-RC064AVR-108)
  
## Demonstration Setup

The following steps explains the procedure for setting up the hardware for three-phase sequence detection using AVR128DA64 microcontroller, and figure 1 shows the hardware setup used for the application demo.
* Insert AVR128DA64 microcontroller in the microcontroller slot of socket card.

  **Note:** For proper orientation while inserting the microcontroller, refer the marking on AVR128DA64 microcontroller.

Connects AVR device to the STK600 using an innovative routing (STK600-RC064AVR-108) and socket (STK600-TQFP64-2) card sandwich system, which routes the i/o pins from the device to the appropriate hardware.

* Insert three waveform clicks in the three mikroBUS slots available on Curiosity nano base board.
* Connect SMA output of the waveform clicks to the respective microcontroller I/O pins using SMA connectors. Refer Application Note Appendix section for more information about the specific microcontroller I/O pins to be used.
* Detach waveform click 2 OEN pin from mikroBUS slot2 PWM2 pin.
* Detach waveform click 3 CS pin from mikroBUS slot3 CS3 pin.
* Connect PWM2 pin of mikroBUS slot2 to pin PB5, and CS3 pin of mikroBUS slot3 to pin PB4.
* Connect the curiosity nano board to a host computer (PC) using the standard micro B USB cable.
* Using female-female jumper wire, connect PC 7 pin (PORT C) of the STK600 board to SW0 pin (Switches) of the STK600 board.
* Using female-female jumper wire, connect VTG and Gnd pins of the STK600 board to VCC and GND pins of the curiosity nano adapter board, respectively.
* Connect UART 1 pins PC0 and PC1 (Tx and Rx) from STK600 board to PC through USB-UART convertor. 
* Connect USB Type B cable for powering the STK600 board.
* Press SW0 button on STK600 board for selecting appropriate frequency (50Hz/60Hz) for the emulated three-phase AC signal.  

<p align="center">
  <img width=750 height=auto src="images/DemoSetup.png"></a>
  <br>Figure 1: Demonstration Hardware Setup<br>
</p>

## Data Visualizer Configuration
The data visualizer tool is used as a graphical user interface while demonstrating the application by displaying the emulated three phase supply waveforms, output status and for receiving the user inputs.
Pre-configured data streamer file and custom dashboard file is available with the firmware package. The below steps given for data visualizer configuration uses these files to get the setup ready.

Here is the list of Data Visualizer modules used for Demonstration –
* Serial Port (Baud Rate – 230400)
* Graph 
* Custom Dashboard (Custom Dashboard file is given for the demonstration) 
  * Element Label
  * Element Signal
  * Radio Group
* Data Streamer (Data Streamer file is given for the demonstration)  

Refer Data Visualizer User Guide for more information about <a href="https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/UserGuides/MPLAB_DATA_VISUALIZER_1_4_1926.pdf" rel="nofollow"> Data Visualizer.</a> 

The demo uses an emulated three-phase AC supply to showcase the essential features of the application. To emulate the AC power supply three waveform clicks are used in the application.


## Custom Dashboard: User Inputs and Output Indicators  

The Data Visualizer custom dashboard is customized for this application, user input and output elements are listed below:     

### User inputs

-	Recover three-phase supply from faults
-	Insert phase loss fault on L1 phase
-	Insert phase loss fault on L2 phase
-	Insert phase loss fault on L3 phase
-	Insert phase reversal (PR) fault

### Application Output Indicators

-	Three phase Waveforms (using Graphs)
-	Phase reversal (using status indicator)
-	Phase loss status (using status indicator)
-	Operating Freq (using sequence output)
The figure below shows the Data Visualizer custom dashboard and input, output elements.

<p align="center">
  <img width=auto height=auto src="images/inputOutput.png">
  <br>Figure 2: User Inputs & Output Status <br>
</p>


## Demo Operation

1. Configure the serial port for communication with the Curiosity Nano board.
2. Configure the data streamer for interfacing dashboard window with the serial port by clicking on IMPORT tab. The data streamer configuration (data-streamer-config.txt) file is available in the example firmware folder.
3. Configure the graph window for displaying the emulated three phase supply AC waveforms, generated by the Waveform Clicks.
4. Configure the custom dashboard window to display the output and to receive user inputs by clicking on load option on dashboard window. The custom dashboard (custom-dashboard-config) design file is available in the example firmware folder.
5. There are elements on the custom dashboard as inputs and status showing the phase states as outputs.
6. Connect the hardware and prepare the demo setup as per the instructions provided in the Demonstration setup section. 
7. Click Serial Port Connect button.
8. Using push button (SW0) on the Curiosity Nano board, select the appropriate frequency for the three-phase signal. The selected frequency is displayed on the custom dashboard window.
9. Zoom in or zoom out the graph on custom dashboard by clicking the +/- magnifier symbol on the left side of the graph window.
10. Insert phase loss fault by clicking the L1 radio button on dashboard, which disables the L1 signal out of three-phase signal to emulate phase loss input.
11. Insert phase loss fault by clicking the L2 radio button on dashboard, which disables the L2 signal out of three-phase signal to emulate phase loss input.
12. Insert phase loss fault by clicking the L3 radio button on dashboard, which disables the L3 signal out of three-phase signal to emulate phase loss input.
13. Insert phase reversal by clicking the PR radio button on dashboard, which changes the sequence of the three-phase signal.
14. The status indicators have two states: Red - phase reversal, phase loss Green - No phase reversal, No phase loss.

Figure 2 shows the Data Visualizer Dashboard for Phase Sequence Detection of Three-phase AC Supply. 

<p align="center">
  <img width=750 height=auto src="images/customDashboard.png">
  <br>Figure 3: Data Visualizer Custom Dashboard<br>
</p>

