
// https://laboratoriorobotica.es/semaforo-arduino-con-pulsador/
// -------------------------------------------------------------
//  Proyecto:   PB2 - Semáforo Arduino con Pulsador
//  Autor:      LabRob (Jose Delgado)
//  Fecha:      Octubre 2019
//  Explicacion:
//              Enceder secuencialmente un led rojo, led
//              amarillo y led verde conforme presionemos
//              un pulsador.              
// -------------------------------------------------------------
// Modificações para incluir novo botão, UP e DOWN
// Os botõestambém estão ligados como input normal..

 
// ================================================
// Declaraciones, Constantes, Variables ...
// ================================================
const int led_rojo_PIN = 11;       
const int led_amarillo_PIN = 12;  
const int led_verde_PIN = 13;     
 
const int btn_right = 3;
const int btn_down = 2;       
 
int led_encendido = 0;            // 0 Led Encendido --> Ninguno
                                  // 1 Led Encendido --> Rojo
                                  // 2 Led Encendido --> Amarillo
                                  // 3 Led Encendido --> Verde



// TODO: ESSE CODIGO PRECISA DE TRADUÇÃO OU MELHORIA DOS COMENTARIOS....
// ================================================
// ================================================
// ================================================
 
// ================================================
// Modulo Inicializacion y Configuracion
// ================================================
void setup()
{
  pinMode(led_rojo_PIN , OUTPUT);     // Definimos el PIN del Led Rojo como SALIDA
  pinMode(led_amarillo_PIN , OUTPUT); // Definimos el PIN del Led Amarillo como SALIDA
  pinMode(led_verde_PIN , OUTPUT);    // Definimos el PIN del Led Verde como SALIDA
 
  digitalWrite(led_rojo_PIN, LOW);    // Inicialmente apagamos todos los leds
  digitalWrite(led_amarillo_PIN, LOW);
  digitalWrite(led_verde_PIN, LOW);
   
  pinMode(btn_right, INPUT);       // Definimos el PIN del Pulsador como ENTRADA
  pinMode(btn_down, INPUT);       // Definimos el PIN del Pulsador como ENTRADA
}
 
// ================================================
// Loop
// ================================================                 
void loop()
{

  int up = digitalRead(btn_right);
  int down = digitalRead(btn_down);

  if (up == HIGH || down == HIGH) {


    if(up == HIGH){
        // Hemos llegado aqui porque se ha presionado el Pulsador
        // Asignamos el Led que le toca encenderse de forma secuencial y cíclica
        // Si el Led encendido es el Verde (3) pasamos a encender el Rojo (1)
        if (led_encendido == 1){
          led_encendido = 3;
        }
        else{
          led_encendido = led_encendido - 1;
        }
    }

    if(down == HIGH){
        if (led_encendido == 3){
          led_encendido = 1;
        }
        else{
          led_encendido = led_encendido + 1;
        }
    }
   
    // Encendemos el Led Rojo y apagamos el Amarillo y el Verde
    if (led_encendido == 1) {
      digitalWrite(led_rojo_PIN, HIGH);  
      digitalWrite(led_amarillo_PIN, LOW);
      digitalWrite(led_verde_PIN, LOW);   
    }
   
    // Encendemos el Led Amarillo y apagamos el Rojo y el Verde
    if (led_encendido == 2) {
      digitalWrite(led_rojo_PIN, LOW);   
      digitalWrite(led_amarillo_PIN, HIGH);
      digitalWrite(led_verde_PIN, LOW);  
    }
   
    // Encendemos el Led Verde y apagamos el Rojo y el Amarillo
    if (led_encendido == 3) {
      digitalWrite(led_rojo_PIN, LOW);   
      digitalWrite(led_amarillo_PIN, LOW);
      digitalWrite(led_verde_PIN, HIGH);  
    }

    delay(200); // Avoid more clicks
    
  };
  
  
}
