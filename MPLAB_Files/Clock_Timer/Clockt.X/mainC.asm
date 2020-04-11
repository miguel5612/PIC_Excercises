LIST P = 16F84A
#include "p16f84A.inc"
__CONFIG _FOSC_XT & _WDTE_OFF & _PWRTE_ON & _CP_OFF
;*******************************************************************************
; INICIO DEL PROGRAMA
;*******************************************************************************
    ORG 0X00
    GOTO START
;*******************************************************************************
; DEFINICION DE VARIABLES 
;*******************************************************************************
 Unidad equ 0x0C
 Decena equ 0x0D
 Centena equ 0x0E
 ; Contadores
 Contador equ 0x0F
 Contador1 equ 0x10
 Contador2 equ 0x11 
 ; Banderas
 MuestroU equ 2
 MuestroD equ 1
 MuestroC equ 0
;*******************************************************************************
; INICIO DEL PROGRAMA
;*******************************************************************************
; Tabla de conversion BCD a 7 Segmentos
ORG 0X05
BCD7SEG
    addwf PCL, 1
    DT 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0xFF, 0x6F
START
    BSF STATUS, RP0
    CLRF TRISA
    CLRF TRISB
    BCF STATUS, RP0
    CLRF PORTA
    CLRF Unidad
    CLRF Decena
    CLRF Centena
    GOTO ActualizarDisplay
    ;**************************************************************
    ; CHEQUEO DE PULSADORES
    ;**************************************************************
    Ciclo
	INCF Unidad, 1
	MOVLW d'10'
	SUBWF Unidad, 0
	BTFSS STATUS, Z
	GOTO ActualizarDisplay
	CLRF Unidad
	INCF Decena, 1
	MOVLW d'10'
	SUBWF Decena, 0
	BTFSS STATUS, Z
	GOTO ActualizarDisplay
	CLRF Decena
	INCF Centena, 1
	MOVLW d'10'
	SUBWF Centena, 0
	BTFSS STATUS, Z
	GOTO ActualizarDisplay
	CLRF Centena
    ; ***********************************************************
    ; MULTIPLEXO LOS DISPLAY
    ;************************************************************
    ActualizarDisplay
	MOVLW d'20'
	MOVWF Contador
	
    Refrescar
	MOVFW Unidad
	CALL BCD7SEG
	BCF PORTA, MuestroC
	MOVWF PORTB
	BSF PORTA, MuestroU
	CALL Esperar_5ms
	MOVFW Decena
	CALL BCD7SEG
	BCF PORTA, MuestroU
	MOVWF PORTB
	BSF PORTA, MuestroD
	CALL Esperar_5ms
	MOVFW Centena
	CALL BCD7SEG
	BCF PORTA, MuestroD
	MOVWF PORTB
	BSF PORTA, MuestroC
	CALL Esperar_5ms
	DECFSZ Contador, 1
	GOTO Ciclo
	GOTO Refrescar
    ;***************************************************************
    ; Function de esperar 5 mS
    ;***************************************************************
    Esperar_5ms
	MOVLW 0xFF
	MOVWF Contador1
    Repeticion1
	MOVLW 0x05
	MOVWF Contador2
    Repeticion2
	DECFSZ Contador2, 1
	GOTO Repeticion2
	DECFSZ Contador1, 1
	GOTO Repeticion1
	return
END