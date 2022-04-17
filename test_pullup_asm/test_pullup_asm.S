#define __SFR_OFFSET 0x20
  
#include "avr/io.h"

.global test

; 
test:
  LDI R16, 0x0     ; Setting (pinS) of DDRD as INPUT
  STS DDRD, R16
  ; Now toggle pin 2 with SBI
  LDI R17, 0b00000110
  STS PORTD, R17
  RET
