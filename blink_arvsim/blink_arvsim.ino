
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);    
  Serial.begin("115200");
}

int delayMS = 500;

// the loop function runs over and over again forever
void loop() {
  Serial.println("ON");
  digitalWrite(13, HIGH);   
  digitalWrite(12, LOW);
  delay(delayMS);       
  Serial.println("OFF"); 
  digitalWrite(13, LOW);    
  digitalWrite(12, HIGH);
  delay(delayMS);     
}
