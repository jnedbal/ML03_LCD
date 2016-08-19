/* Code for Arduino DUE
 * This code tests the LCD display connected to the microlabduino.
 * It requires the shield to be installed, The LCD shield with 
 * Arduino/Genuino Micro and LCD installed and 12 V power attached.
 * The communication is done via a par<zallel 8-bit port, two address
 * bits and a chip select signal. It consists of one way
 * communication from the Arduino DUE to Arduino/Genuino Micro.
 * 
 */

/********************/
/*  Load libraries  */
/********************/

// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>

// Library to communicate with the RTC
#include <RTClib.h>
 
//                    ........|...AA..|.....CDDDDDDDD. 
#define LCDchar     0b00000000000001000000000000000000
#define LCDcontrol  0b00000000000000000000000000000000
#define LCDCS       0b00000000000000000000001000000000
#define LCDclear    0b00000000000011000000000111111110
#define NOP __asm__ __volatile__ ("nop\n\t")

// Definitions for LCD daughter board communication
#define resetLCD      1
#define startI2Ccomm  2
#define stopI2Ccomm   3
#define initializeDAC 11
#define brightnessMSB 12
#define brightnessLSB 13
#define contrastMSB   14
#define contrastLSB   15

// Define Arduino DUE pins
#define __I2C_EN      22
#define __LED         13


unsigned long LCDdataBuffer;
unsigned long LCDoldBuffer;

/********************/
/* Define constants */
/********************/

/* Constants for LCD */
// lookup table for HEX numbers
const byte HEXASCII[16] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 59, 70};


/********************/
/*  Define objects  */
/********************/

// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
RTC_DS1307 rtc;

void setup() {
  // put your setup code here, to run once:
  initPins();
  // initialize the RTC
  initRTC();
  Serial.begin(115200);
  delay(4000);
  setDef();
}

// Function to initialize the pins required for communication with the LCD
void initPins()
{
  initLCDpins();
  pinMode(__LED, OUTPUT);     // LED
  digitalWrite(__I2C_EN, HIGH); // I2C bus voltage translator disabled
  pinMode(__I2C_EN, OUTPUT);    // I2C bus voltage translator (active LOW)
}

void loop()
{
  //for (unsigned long i = 0; i < 128; i=i+1)
  
//  for (unsigned long i = 0; i < 200; i=i+1)
//  {
//    
//  }
  //for (unsigned long i = 60; i < 191; i=i+4)
  for (unsigned long i = 60; i < 191; i=i+4)
  {

    //sendLCDcommand(i | 0b10000000, LCDchar);  // character
    //delay(200);
    //sendLCDcommand((i % 40)+20, LCDchar);               // position
    //delay(200);
    Serial.print("MSB:");
    Serial.print((i & 0xF0) | brightnessMSB);
    sendLCDcommand((i & 0xF0) | brightnessMSB, LCDcontrol);
    
    delay(200);
    Serial.print(", LSB:");
    Serial.println(((i & 0x0F) << 4) | brightnessLSB);
    sendLCDcommand(((i & 0x0F) << 4) | brightnessLSB, LCDcontrol);
    
    delayMicroseconds(1000);
    sendLCDcommand(HEXASCII[i/100] | 0b10000000, LCDchar);  // character
    delayMicroseconds(100);
    sendLCDcommand(32, LCDchar);               // position
    delayMicroseconds(100);
    sendLCDcommand(HEXASCII[i%100/10] | 0b10000000, LCDchar);  // character
    delayMicroseconds(100);
    sendLCDcommand(33, LCDchar);               // position
    delayMicroseconds(100);
    sendLCDcommand(HEXASCII[i%10] | 0b10000000, LCDchar);  // character
    delayMicroseconds(1000);
    sendLCDcommand(34, LCDchar);               // position
    delayMicroseconds(1000);
    delay(200);
    if (i==60)
    {
      delay(10000);
    }
  }
  delay(10000);
  for (unsigned long i = 50; i < 70; i=i+2)
  {

    //sendLCDcommand(i | 0b10000000, LCDchar);  // character
    //delay(200);
    //sendLCDcommand((i % 40)+20, LCDchar);               // position
    //delay(200);
    Serial.print("MSB:");
    Serial.print((i & 0xF0) | contrastMSB);
    sendLCDcommand((i & 0xF0) | contrastMSB, LCDcontrol);
    
    delay(200);
    Serial.print(", LSB:");
    Serial.println(((i & 0x0F) << 4) | contrastLSB);
    sendLCDcommand(((i & 0x0F) << 4) | contrastLSB, LCDcontrol);
    
    delayMicroseconds(1000);
    sendLCDcommand(HEXASCII[i/100] | 0b10000000, LCDchar);  // character
    delayMicroseconds(100);
    sendLCDcommand(52, LCDchar);               // position
    delayMicroseconds(100);
    sendLCDcommand(HEXASCII[i%100/10] | 0b10000000, LCDchar);  // character
    delayMicroseconds(100);
    sendLCDcommand(53, LCDchar);               // position
    delayMicroseconds(100);
    sendLCDcommand(HEXASCII[i%10] | 0b10000000, LCDchar);  // character
    delayMicroseconds(1000);
    sendLCDcommand(54, LCDchar);               // position
    delayMicroseconds(1000);
    delay(200);

  }
  delay(10000);
}
