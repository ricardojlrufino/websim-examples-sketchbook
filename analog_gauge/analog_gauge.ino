/* SSD1306 128x64 I2C OLED display, Arduino UNO and 10K Ohm pot on A0
 * Tony Goodhew  3rd July 2020
 * Tutorial45.com
 */

#include <Wire.h>              
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS  0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int sensorPin = A1;   // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(115200);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(1);             // Small
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(0,0);             // Top Left corner
  display.println("SSD1306 Project");
  display.setCursor(20,10);
  display.println("Volts - Turn Pot");
  display.setCursor(64,118);
  display.setCursor(0,57);
  display.println("  Raw Pot    Volts");
  display.display();
}
// Functions for right alignment of integers
int iAlign2(int s){  // Space in 100s and 10s
  if (s < 100) {display.print(" ");}
    if (s < 10) {display.print(" ");}    
}
int iAlign3(int s){  // Space in 1000s
  if (s < 1000) {display.print(" ");}
  iAlign2(s);
}
int bar(int yy,int v) {
  display.drawLine(0,yy,0,yy+14, SSD1306_WHITE);
  display.fillRect(1,yy+2,127,10,SSD1306_BLACK);
  display.fillRect(0,yy+2,v,10, SSD1306_WHITE);
  display.setCursor(102,yy+2);
  iAlign2(v);
  display.print(v);
  display.println("%");
  display.display();
}
// ++++++++++++Main Loop ++++++++++++++
void loop() {
  // Read pot and display values
  sensorValue = analogRead(sensorPin); // Read the value from the sensor
  float volts = (sensorValue * 5.0 / 1023.0);  // Calculate voltage
  int x = float(sensorValue * 100.0/1018);     // Calculate percentage
  bar(20,x);  // Redraw bar graph
  display.fillRect(0, 40, 127, 15, SSD1306_BLACK); // Clear line
  display.setCursor(5,40);
  display.setTextSize(2);
  iAlign3(sensorValue);  
  display.println(sensorValue);  // Raw pot value
  display.setCursor(78,40);
  display.print(volts);          // Equivalent voltage
  display.setTextSize(1);
}
