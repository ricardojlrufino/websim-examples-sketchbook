void setup() {
  Serial.begin(115200);
  
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);

  delay(100); 

  if(digitalRead(2) == HIGH) Serial.println("SUCCESS");
  else Serial.println("FAIL");
}

void loop() {

}
