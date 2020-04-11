###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = PIC16F84A
COMPILER = "MPASM (Proteus)"
TARGET = Debug
SHELL = C:\Windows\system32\cmd.exe

## Tools general options
ASMFLAGS=/q+ /p16f84a
LDFLAGS=/x /p16f84a

## Processing Tools
ASM=MPASMWIN.exe
LD=mplink.exe
LIB=mplib.exe
#  C:/Users/migue/OneDrive/Escritorio/PIC16F84A_Clock/Proteus_Files/Clock/PIC16F84A/Debug/Debug.cof: TOOL=LD
#     C:/Users/migue/OneDrive/Escritorio/PIC16F84A_Clock/Proteus_Files/Clock/PIC16F84A/Debug/main.o: TOOL=ASM
#        C:/Users/migue/OneDrive/Escritorio/PIC16F84A_Clock/Proteus_Files/Clock/PIC16F84A/main.asm

# Build tree:
all:	Debug

Debug:	Debug.cof

Debug.cof:	main.o 
	$(LD) $(LDFLAGS) /o "./Debug.cof" 16f84a_g.lkr "main.o"

main.o:	../main.asm 
	$(ASM) /e"./main.err" /l"./main.lst" /o"main.o" $(ASMFLAGS)  "..\main.asm"

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf ./main.err
	rm -rf ./main.hex
	rm -rf ./main.lst

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.cof
	rm -rf main.o

