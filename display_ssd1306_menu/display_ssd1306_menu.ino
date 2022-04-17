
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS  0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int selected = 0;
int entered = -1;

void setup() {
  pinMode(2, INPUT_PULLUP);
  digitalWrite(2, HIGH);
  pinMode(3, INPUT_PULLUP);
  digitalWrite(3, HIGH);
  
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  pinMode(13, OUTPUT);

  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.display();

  // Debug button states ....
  Serial.println("Starting...");
  digitalWrite(13, HIGH);
  Serial.print("[up] "); Serial.println(digitalRead(3));
  Serial.print("[down] "); Serial.println(digitalRead(2));
  delay(500); 
  
}



void loop() {
  // put your main code here, to run repeatedly:
  displaymenu();
}


void displaymenu(void) {

  int up = digitalRead(3);
  int down = digitalRead(2);
  int enter = digitalRead(4);
  int back = digitalRead(5);

  // NOTA: ESSA LOGICA TEM UM BUG
  // ELE PERMITE SUBIR E DIMINUIR A POSIÇÃO DO MENU ALEM DO QUE DEVERIA
  // OTIMO EXEMPLO PARA PRATICAR....

  if (up == LOW) {
    if(selected > 0) selected = selected - 1;
    Serial.println("[up]");
    delay(200);
  };
  if (down == LOW) {
    selected = selected + 1;
    Serial.println("[down]");
    delay(200);
  };
  if (enter == LOW) {
    entered = selected;
  };
  if (back == LOW) {
    entered = -1;
  };

  const int MENU_SIZE = 6;
  const char *options[MENU_SIZE] = {
    " Menu 1",
    " Menu 2",
    " Menu 3",
    " Menu 4 ",
    " Menu 5 ",
    " Menu 6 "
  };

  if (entered == -1) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Dsn menu test"));
    display.println("");
    for (int i = 0; i < MENU_SIZE; i++) {
      if (i == selected) {
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
        display.println(options[i]);
      } else if (i != selected) {
        display.setTextColor(SSD1306_WHITE);
        display.println(options[i]);
      }
    }
  } else if (entered == 0) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Dsn menu test"));
    display.println("Menu option 1");
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    display.println("Dsn Menu system");
  } else if (entered == 1) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Dsn menu test"));
    display.println("Menu option 2");
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    display.println("Dsn Menu system :)");
  }
  else if (entered == 2) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Dsn menu test"));
    display.println("Menu option 3");
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    display.println("Dsn Menu system:)");
  } else if (entered == 3) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Dsn menu test"));
    display.println("Menu option 4");
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    display.println("Dsn Menu system:)");
  } else if (entered == 4) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Dsn menu test"));
    display.println("Menu option 5");
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    display.println("Dsn Menu system:)");
  } else if (entered == 5) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Dsn menu test"));
    display.println("Menu option 6");
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    display.println("Dsn Menu system:)");
  } 

  display.display();
}
