
// Tutotial: https://www.makerzine.com.br/educacao/semaforo-com-arduino/

#define VERMELHO 11
#define AMARELO 12
#define VERDE 13

#define TEMPO 500 // Tempo de delay em ms

void setup() {
  pinMode(VERMELHO, OUTPUT);   
  pinMode(AMARELO, OUTPUT);   
  pinMode(VERDE, OUTPUT);    
}

void loop() {
  digitalWrite(VERMELHO, HIGH);  
  delay(TEMPO);      
  digitalWrite(VERMELHO, LOW);   
  digitalWrite(AMARELO, HIGH);  
  delay(TEMPO);      
  digitalWrite(AMARELO, LOW);   
  digitalWrite(VERDE, HIGH); 
  delay(TEMPO);               
  digitalWrite(VERDE, LOW);  
}
