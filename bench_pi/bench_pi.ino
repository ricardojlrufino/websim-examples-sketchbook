// Double precision speed test using Pi calculation.
// by Koepel, Public Domain
// 14 jan 2022, Version 1

// ONLINE> https://wokwi.com/projects/320755799379935827

#if defined(ARDUINO_ARCH_RP2040)
#if defined(ARDUINO_ARCH_MBED)
#define _SERIAL Serial1
char extraMessage[] = "Raspberry Pi Pico + Mbed, \"arduino-core\"";
#else
#define _SERIAL Serial1
char extraMessage[] = "Raspberry Pi Pico, \"arduino-community\"";
#endif
#elif defined(ARDUINO_ARCH_ESP32)
#define _SERIAL Serial
char extraMessage[] = "ESP32";
#else
#define _SERIAL Serial
char extraMessage[] = "unknown board";
#endif

const long n = 100000L;     // start with 1000L, maybe 100000L on a fast computer

void setup()
{
  _SERIAL.begin( 115200);
  _SERIAL.print( "Speedtest with Pi (");
  _SERIAL.print( extraMessage);
  _SERIAL.println( ").");
  _SERIAL.print( "sizeof(float) = ");
  _SERIAL.print( sizeof(float));
  _SERIAL.print( ", sizeof(double) = ");
  _SERIAL.println( sizeof(double));
  _SERIAL.print( "Iterations    : ");
  _SERIAL.println( n);

  unsigned long timeStamp1 = millis();

  // Francois Viete formula
  double s = 0.0;
  double t = 1.0;
  for( long i=0; i<n; i++)
  {
    float r = s + 2.0;
    s = sqrt(r);
    t *= s / 2.0;
  }

  unsigned long timeStamp2 = millis();

  unsigned long elapsedMillis = timeStamp2 - timeStamp1;
  _SERIAL.print( "Time          : ");
  _SERIAL.print( double(elapsedMillis) / 1000.0);
  _SERIAL.println( " seconds (the time that it would take in the real world)");
  _SERIAL.print( "M_PI constant : ");
  _SERIAL.println( M_PI, 20);
  _SERIAL.print( "Calculated Pi : ");
  _SERIAL.println( 2.0 / t, 20);
}

void loop() 
{
  delay(1000);
}
