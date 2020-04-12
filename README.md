# PIC16F84A_Clock
## Problem
a clock should be designed using 3 7-segment displays (The group chooses whether it is anode or cathode common), to present the time from 0:00 to 9:59 each clock number is a 7-segment display, each LED will be the output of the PIC16F84A Microcontroller.
![Ex1](https://github.com/miguel5612/PIC_Excercises/blob/master/Img/Clock.PNG)
# PIC16F877A_Doors_Temporized
## Problem:
1. Using the PIC16F877 or **PIC16F84A** the control of opening of the laboratory doors is made, this element sends the command so that 3 motors are moved that make part of the 3 doors of the laboratory in sense towards left and right that fulfill the operation of opening and closing, the opening is synchronized with a clock that makes the control of the following form:
* Starting the clock at 0:00 does not open any door.
Starting the clock at 0:00 no door is opened. 
* At 0:59 the first door is opened so the first motor is turned to the left.
* At 1:59 the first door closes, the first motor moves to the left and the second motor moves to the right, opening the second door.
* In 2:59 the second door closes, the second engine moves to the left and the third engine moves to the right, opening the third door.
* In 3:59 all doors close.
* Please note that the run time of the movement of each motor for opening is 22 seconds and for closing is 26 seconds, giving time for the employees to leave easily and for the decontamination to be done.
* An emergency stop must be made in case of a catastrophe. To do this, the doors are closed with a push-button to avoid possible exposure.
* The cycle should be repeated until 7:59, repeating the whole process again.
* Use a 16x2 LCD screen on which the following will be displayed:
    * Open and close each of the doors.
    * Next door to be opened.
    * Next door to be closed.
    * Lumen level in the laboratory
![Ex2](https://github.com/miguel5612/PIC_Excercises/blob/master/Img/Doors_Main.PNG)
# PIC16F877A_Light_Monitor
## Problem
Using the PIC16F877 you will monitor the amount of light that is presented
in the lab, so the following should be done:
* Using a photoresist or similar element to sense the amount of lumenz that exists in the laboratory 
* Perform an average of minimum and maximum amount of light (you can use a percentage scale from 0% to 100%) that may exist in the laboratory, if the amount of light falls below 40%, a light bulb must be turned on to level the amount of light and pass 80% of lumen.
![Ex3](https://github.com/miguel5612/PIC_Excercises/blob/master/Img/Lamps.PNG)
## Software used:
* MPLAB X IDE v5.2.0
* Proteus 8 profesional
## Authors
* **Miguel A. Califa U.** - [*GitHub*](https://github.com/miguel5612) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0000050477)
