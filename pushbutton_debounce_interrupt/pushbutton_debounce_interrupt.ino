
// Reference: https://wokwi.com/projects/318885209198035539

// Switch usage tutorial with debounce and interrupt by DiskDoctor
// credit to Michael Margolis 'Arduino Cookbook' for debounce routine
// starred comments '*' are required for using debounce on a button
// preferred method for switch is to set button to HIGH with internal pull-up resistor
// preferred method is to use interrupt for switch so it may be pressed any time
// 'Wild' prefix for non-debounced usage as comparison, not needed in program

// note: interrupts on digital pins restricted: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
// digital interrupts available...uno:2,3  mega:2,3,18,19

// notice debounced button only triggers ONCE but non-debounced maybe multiple or unreliable state
// GREEN is good with debounce. Notice single message and short LED
// RED is unstable without debounce. Notice multiple messages and longer LED from multiples can lead to instability
// each button uses distinct interrupt

// internal pullup resistors used for buttons so no 5v necessary only GND
// 220 Ohm resistors used for LEDs, including pin 13 that has onboard LED but NO internal resistor


#define inputPin 2 // which input pin is connected to button *
const int debounceDelay = 10; // milliseconds to wait until button input stable *
#define inputWildpin 3 // which input ping is connect to button NOT debounced

#define LED 12  // The pin the button-LED is connected to
#define LEDWild 13 // The pin used for second non-debounced connected LED


void setup() {
  // put your setup code here, to run once
  Serial.begin(115200); // initializes serial monitor for troubleshooting and learning
  Serial.println("Hi !");
  delay(100);
  
  pinMode(inputPin, INPUT_PULLUP); // make button pin mode input *
  digitalWrite(inputPin, HIGH);
  pinMode(LED, OUTPUT); // Declare the button-LED as an output
  
  
  pinMode(inputWildpin, INPUT_PULLUP); // make second button pin mode input
  digitalWrite(inputWildpin, HIGH);
  pinMode(LEDWild, OUTPUT); // Declare the button-LED as an output- second comparison LED


  attachInterrupt(digitalPinToInterrupt(inputWildpin), buttonPushed2, FALLING); // assign interrupt to button, procedure to be run and set state to LOW when pushed
  attachInterrupt(digitalPinToInterrupt(inputPin), buttonPushed, FALLING); // assign interrupt to button, procedure to be run and set state to LOW when pushed *

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("[loop] while waiting for button"); // normal program goes here
  delay(1000); // pause to read serial monitor output
}

void buttonPushed() {   // detect and debounce button push using assigned interrupt *
  if (debounce(inputPin)) { // calls debounce procedure *
    Serial.println("Debounce Button Pushed"); // shows button pushed on serial monitor
    digitalWrite(LED, HIGH); // Turn the button-LED on for feedback
    Serial.println("  something done when button is pushed"); // normal program code for action when button pressed
    Serial.println(""); // blank line for neatness
    delay(1000); // delay to read serial monitor and see LED
    digitalWrite(LED, LOW); // Turn the button-LED back off
  }
}

void buttonPushed2() {  // detect second button push using assigned interrupt
  Serial.print('x');delay(50);
  if (digitalRead(inputPin)) { // does NOT call debounce procedure
    Serial.println("@@ Non-debounced Button Pushed @@"); // shows button pushed on serial monitor
    digitalWrite(LEDWild, HIGH); // Turn the button-LED on for feedback
    Serial.println("  something done when non-debounced button is pushed"); // normal program code for action when button pressed
    Serial.println(""); // blank line for neatness
    delay(1000); // delay to read serial monitor and see LED
    digitalWrite(LEDWild, LOW); // Turn the button-LED back off
  }
}

// ***************************************
// **            Debounce pin           **
// **    Entire procedure required      **
// **     outside of setup or loop      **
// **           usually at end          **
// ***************************************
// debounce returns true if the switch in the given pin is closed and stable
boolean debounce(int pin)
{
  boolean state;
  boolean previousState;
  previousState = digitalRead(pin); // store switch state
  for (int counter = 0; counter < debounceDelay; counter++)
  {
    delay(1); // wait for 1 millisecond
    state = digitalRead(pin); // read the pin
    if ( state != previousState)
    {
      counter = 0; // reset the counter if the state changes
      previousState = state; // and save the current state
    }
  }
  // here when the switch state has been stable longer than the debounce period
  return state;
}
