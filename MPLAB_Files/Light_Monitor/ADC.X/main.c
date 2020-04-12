#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"
#include <stdio.h>

void main(void) {
    int adc=0;
    int perc = 0;
    int numLamps = 0;
    float volt,temp;
    unsigned char buffer1[16];
//************Configuración del oscilador    32MHz
    OSCCONbits.IRCF=0b1110; //Interno 8MHz
    OSCCONbits.SCS=0b00;    //Configuración en CONFIG1
//****************************************
    ANSELA=0b00100000;  //RA5 como analógico
    //ANSELD=0;           //Puerto D como digital
    //ANSELE=0;           //Puerto E como digital
    TRISA=0b00100000;  //RA5 como entrada
//****************************************

    ADCON0bits.CHS=4;   //selección del canal
    ADCON1bits.ADNREF=0;    //Referencia neg= Vss
    ADCON1bits.ADPREF=0;    //Ref pos=VDD
    ADCON1bits.ADCS=0b111;  //Fuente de reloj oscilador int.
    ADCON1bits.ADFM=0b1;    //justificado a la derecha
    ADCON0bits.ADON=1;      //Activamos el ADC
//******************************
    Lcd_Init();     //inicializamos el lcd
    Lcd_Cmd(LCD_CLEAR);		//limpiamos lcd
    Lcd_Cmd(LCD_CURSOR_OFF);	//apagamos el cursor
    __delay_ms(100);		//esperamos 100ms
    while(1){
        ADCON0bits.GO=1;
        while(GO);
        adc=ADRESH;
        adc=adc<<8;
        adc=adc+ADRESL;
        perc = (adc*100.0)/(1024.0);
        volt=adc*5.0/1024.0;
        if(perc<=20)
        {
            numLamps = 4; // Las 4 lamparas encendidas
        }
        else if(perc<=40)
        {
            numLamps = 3; // Solo 3 lamparas encendidas 
        }
        else if(perc<=60)
        {
            numLamps = 2; // Dos lamparas encendidas
        }else if(perc<=80)
        {
            numLamps = 1; // Una lampara encendida
        }
        
        sprintf(buffer1,"Porcentaje %04d", perc);   //guardamos en el string Buffer1 la palabra Cuenta espacio y el valor de i
        Lcd_Out2(1, 1, buffer1);            //escribimos en el renglon uno espaco 1 la que contiene buffer1
        temp=volt*100;
        sprintf(buffer1,"# Lamps On %04d",numLamps);   //guardamos en el string Buffer1 la palabra Cuenta espacio y el valor de
        Lcd_Out2(2, 1, buffer1);            //escribimos en el renglon uno espaco 1 la que contiene buffer1
        __delay_ms(300);
        

    }

    return;
}
