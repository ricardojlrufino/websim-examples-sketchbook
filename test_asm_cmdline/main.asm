;; PORTS DEF

.equ	PORTD,0x0b
.equ	DDRD,0x0a
.equ	PIND,0x09
.equ	PORTC,0x08
.equ	DDRC,0x07
.equ	PINC,0x06
.equ	PORTB,0x05
.equ	DDRB,0x04
.equ	PINB,0x03

.equ	LED_PINb,4  ;; Define LED PIN (as bit position)

.org 0x00
reset:
rjmp main;

; =========== MAIN =======
main:
LDI R16, 0b00111000     ; Setting (pin 11,12,13) of PORTB as output
STS DDRB, R16
LDI R17, 0x00
STS PORTB, R17    ; Writing 0 to PORTB
LDI R16, 0x00
STS TCCR1A, R16   ; Setting all bits of TCCR1A as 0
rjmp loop;

loop:
  LDI R16, 0xC2
  STS TCNT1H, R16   ; Writing 0xC2 into TCNT1H (8-bit)
  LDI R16, 0xF7
  STS TCNT1L, R16   ; Writing 0xF7 into TCNT1H (8-bit)
  LDI R16, 0x05
  STS TCCR1B, R16   ; Writing 0x05 into TCCR1B
L:LDS R0, TIFR1     ; Load the value of TIFR1 into R0
  SBRS R0, 0        ; Skip the next statement if overflow has occured. 
  RJMP L            ; Loop until overflow occurs.
  LDI R16, 0x00
  STS TCCR1B, R16   ; Stop the Timer/Counter1
  LDI R16, 0x01
  STS TIFR1, R16    ; Clear the overflow flag by writing 1 to it
  COM R17           ; Complement R17 register
  STS PORTB, R17    ; Toggle the LED output
  RET
  rjmp loop;