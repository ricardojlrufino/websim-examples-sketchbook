/*
  Yún HTTP Client

 This example for the YunShield/Yún shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to the Arduino
 website and download a version of the logo as ASCII text.

 created by Tom igoe
 May 2013

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/HttpClient

 */

// DAR UM APLHADA EM 1=I2C ARDUINO <> RASPBERRY: https://www.youtube.com/watch?v=AExLS6UzquI

#include <Bridge.h>
#include <HttpClient.h>
#include <Wire.h>

BridgeClass myBridge(Wire);

void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  Wire.begin(8);                // join I2C bus with address #8
  myBridge.begin();
  
  digitalWrite(13, HIGH);

  Serial.begin(9600);

 
}

void loop() {
  // Initialize the client library
  HttpClient client;

  // Make a HTTP request:
  client.get("http://www.arduino.cc/asciilogo.txt");

  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  Serial.flush();

  delay(5000);
}
