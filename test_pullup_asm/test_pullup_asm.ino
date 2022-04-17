// Tutorial: https://create.arduino.cc/projecthub/yeshvanth_muniraj/arduino-blink-example-in-assembly-using-timer-counter1-e2a327

extern "C" {
  // function prototypes
  void test();

}

void setup() {

  while(!Serial){};
  Serial.begin(115200);
  
  test();

  
  if(PIND & (1 << PD1)) {  // if pin 2 high 
    Serial.println("SUCCESS");
  }else{
    Serial.println("FAIL");  
  }

  
}

void loop() {
  
}
