/*
 * File:   main.c
 * Author: migue
 *
 * Created on April 11, 2020, 10:43 AM
 */


#include <xc.h>
//#include "system.h"
//#include "timer.h"

void main(void) {
    TRISB = 0X00; // Todo el puerto B como salida
    PORTB = 0X00; // Todas las salidas a estado logico bajo
    TRISD = 0XFF; // Todo puerto D como entrada
    PORTD = 0X00; // En cero todas las entradas del puerto B
    
    //timer 500mS
    
    while(1)
    {
        // Si debo abrir la puerta 1 por que son las 00:59
        if(PORTDbits.RD0==1 && PORTDbits.RD1==0 && PORTDbits.RD2==0 && PORTDbits.RD3==0)
        {
            PORTBbits.RB0 = 0; // Giro derecha
            PORTBbits.RB1 = 1; // Giro a la izquierda
            // timer 22 segundos
            PORTBbits.RB1 = 0; // Apago
        }
        // En el caso que deba abrir la puerta 2 y cerrar la 1 a la 1:50
        if(PORTDbits.RD0==0 && PORTDbits.RD1==1 && PORTDbits.RD2==0 && PORTDbits.RD3==0)
        {
            PORTBbits.RB0 = 1; // Giro derecha
            PORTBbits.RB1 = 0; // Giro a la izquierda
            PORTBbits.RB2 = 0; // Giro a la izquierda
            PORTBbits.RB3 = 1; // Giro a la izquierda
            // timer 22 segundos
            PORTBbits.RB3 = 0; // Apago
            // timer 26 segundos
            PORTBbits.RB0 = 0; // Apago
        }
        // En el caso que deba abrir la puerta 3 y cerrar la 2 a las 2:50
        if(PORTDbits.RD0==0 && PORTDbits.RD1==0 && PORTDbits.RD2==1 && PORTDbits.RD3==0)
        {
            PORTBbits.RB2 = 1; // Giro derecha
            PORTBbits.RB3 = 0; // Giro a la izquierda
            PORTBbits.RB4 = 0; // Giro a la izquierda
            PORTBbits.RB5 = 1; // Giro a la izquierda
            // timer 22 segundos
            PORTBbits.RB5 = 0; // Apago
            // timer 26 segundos
            PORTBbits.RB2 = 0; // Apago
        }
        // En el caso que deba abrir la puerta 3 y cerrar la 2 a las 3:50
        if(PORTDbits.RD0==0 && PORTDbits.RD1==0 && PORTDbits.RD2==0 && PORTDbits.RD3==1)
        {
            PORTBbits.RB4 = 1; // Giro a la izquierda
            PORTBbits.RB5 = 0; // Giro a la izquierda
            // timer 22 segundos
            // timer 26 segundos
            PORTBbits.RB4 = 0; // Apago
        }
    }
    return;
}
