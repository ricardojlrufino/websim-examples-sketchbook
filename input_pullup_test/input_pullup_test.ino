#define D2 PD2
#define D13 PB5

void setup() {

  DDRB = 1; // as INPUT

  PORTB |= _BV(D13); // set HIGH (enable internal pull up)

  delay(100); 

  if(PINB & (1 << D2)) {  // if pin 2 high 
    Serial.println("SUCCESS");
  }else{
    Serial.println("FAIL");  
  }

}

void loop() {}





//int main(void)
//{
// 
// DDRD = 0;
//
// PORTD |= _BV(PD2);
//
// if(PIND & (1 << PD2)) {  // if pin 2 high
//   //Serial.print("SUCCESS");
// }else{
//   //Serial.print("FAIL");  
// }
//
//}
