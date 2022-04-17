//#define SET(x,y) (x|=(1<<y))
//#define CLR(x,y) (x&=(~(1<<y)))
//#define CHK(x,y) (x & (1<<y))
//#define TOG(x,y) (x^=(1<<y))

//#define _BV(bit) (1 << (bit))

//#define sbi(port,bit) (port)|=(1<<(bit))
//#define cbi(port,bit) (port)&=~(1<<(bit))


#define D13 B00100000

#define PIN13 5

uint8_t *ports[] = {
    &PORTD,
    &PORTD,
    &PORTD,
    &PORTD,
    &PORTD,
    &PORTD,
    &PORTD,
    &PORTB,
    &PORTB,
    &PORTB,
    &PORTB,
    &PORTB,
    &PORTB,
    &PORTB
};

uint8_t bits[] = {
    PORTD,
    PORTD,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5
};


#define PORT_OF_13 PORTB
#define BIT_OF_13 5

#define SET_BIT(port,bitn) (port|=(1<<bitn))

#define DIGITAL_HIGH(pin) ( *(ports[pin]) |= ( 1<<bits[pin]) )

#define ON(pin) ( PORT_OF_##pin |= ( 1<< BIT_OF_##pin ) )
#define OFF(pin) ( PORT_OF_##pin = ~( 1<< BIT_OF_##pin ) )

void setup() {
    
    Serial.begin(115200);
    Serial.println("Starting");
    // initialize digital pin 8 as an output.
    
    DDRB = DDRB | D13; // The Port B Data Direction Register - read/write
    

    PORTB = 0xff;
    // this is safer as it sets pin 8(PB0) as outputs
    
    // without changing the value of pins PB6 &PB7, which are Oscillator pins
    
}

// the loop function runs over and over again forever

void loop() {
    
    // PORTB = D13;   // sets digital pin 8(PB0) HIGH
    // SET_BIT(PORTB, PIN13);

    ON(13);

    //PORTB |= D13;
    //PORTB |= _BV(5);

    prntBits(PORTB);
    
    delay(1000);    // wait for a second
    
    OFF(13);
    //PORTB &= ~D13;
    //PORTB &= ~(_BV(5));

    prntBits(PORTB);
    delay(1000);// wait for a second


    // PORTB |= bit(5); // sets digital pin 8(PB0) LOW
    
}

void prntBits(byte b)
{
  for(int i = 7; i >= 0; i--)
    Serial.print(bitRead(b,i));
  Serial.println();  
}
