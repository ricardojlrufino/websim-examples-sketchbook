; Copyright (c) 2022, Ricardo JL Rufino
; ATMega328p
; Simple fast blinky 
; Install: apt-get install avr-binutils avr-gcc avr-libc avrdude
; Ref: http://www.avr-asm-tutorial.net/avr_en/micro_beginner/3_Led_Blinking/3_Led_Blinking.html


.nolist
.include "m328Pdef.inc.mod"
.list

.equ	PORTD,0x0b
.equ	DDRD,0x0a
.equ	PIND,0x09
.equ	PORTC,0x08
.equ	DDRC,0x07
.equ	PINC,0x06
.equ	PORTB,0x05
.equ	DDRB,0x04
.equ	PINB,0x03

.equ	LED_PINb,5  ;; Define LED PIN (as bit position)

.org 0x00
reset:
rjmp main;

; =========== MAIN =======
main:
  sbi DDRB,LED_PINb ; PBX as output, driver stage on, 2 clock cycles
  rjmp Loop;

Loop:
  cbi PORTB,LED_PINb ; LED on, 2 clock cycles
  ;;nop ; do nothing, 1 clock cycle
  ;;nop ; do nothing, 1 clock cycle
  sbi PORTB,LED_PINb ; LED off, 2 clock cycles
  rjmp Loop ; Jump relative back to label Loop, 2 clock cycles
