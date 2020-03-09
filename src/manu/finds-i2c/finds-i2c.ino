#include <Wire.h>


#define ADDR0 5 // D5
#define ADDR1 6 // D6
#define ADDR2 7 // D7
#define ADDR3 8 // D8
#define ADDR4 9 // D9
#define ENABLE 10 // D10
#define INT1 14 // A0
#define INT2 15 // A1
#define INT3 16 // A2
#define INT4 17 // A3
#define RESET  12 // A6 - fuck bodge wire time
#define ENABLE 11 // A7 - fuck bodge wire time


void setup()
{
    pinMode(RESET, OUTPUT);
    pinMode(ENABLE, OUTPUT);
    pinMode(ADDR0, OUTPUT);
    pinMode(ADDR1, OUTPUT);
    pinMode(ADDR2, OUTPUT);
    pinMode(ADDR3, OUTPUT);
    pinMode(ADDR4, OUTPUT);
    pinMode(INT1, INPUT);
    pinMode(INT2, INPUT);
    pinMode(INT3, INPUT);
    pinMode(INT4, INPUT);
    Wire.begin();
    delay(100);
    Serial.begin(115200);
    Serial.println('I2C Scan');
    reset();
    delay(100);
}

void reset() 
{
    digitalWrite(RESET,0);
    delay(50);
    digitalWrite(RESET,1);
}

void phex(byte address)
{
    if (address < 16) Serial.print("0");
    Serial.print(address, HEX);
}

void loop()
{
    byte error, address;

    for (address = 1; address < 127; address++)
    {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        phex(address);

        Serial.print(" ");
        Serial.println(error, HEX);
    }

    delay(5000); // wait 5 seconds for next scan
}
