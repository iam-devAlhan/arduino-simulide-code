#include <SPI.h>

// Pins for the Shift Register
const int latchPin = 10; // Connect to RCLK (Pin 12 on chip)
const int clockPin = 13; // Connect to SRCLK (Pin 11 on chip)
const int dataPin = 11;  // Connect to SER (Pin 14 on chip)

void setup() {
  // Set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  // Start SPI communication
  SPI.begin();
  
  // Initialize the LCD (This is like waking it up)
  delay(50); 
  sendToLCD(0x03, 0); // Reset command
  delay(5);
  sendToLCD(0x03, 0); 
  sendToLCD(0x03, 0);
  sendToLCD(0x02, 0); // Set to 4-bit mode
  
  sendToLCD(0x28, 0); // 2 lines, 5x8 font
  sendToLCD(0x0C, 0); // Display ON, Cursor OFF
  sendToLCD(0x01, 0); // Clear Screen
  delay(5);
  
  // Print our message!
  writeString("22F-BSCS-88");
}

void loop() {
  // Nothing needed here for a static message
}

// --- HELPER FUNCTIONS (The Magic) ---

void sendToLCD(byte value, bool isData) {
  // We split the byte into two 4-bit chunks (High and Low)
  byte highNibble = value >> 4;
  byte lowNibble = value & 0x0F;
  
  sendNibble(highNibble, isData);
  sendNibble(lowNibble, isData);
}

void sendNibble(byte nibble, bool isData) {
  // Mapping: Q0=RS, Q1=E, Q2=D4, Q3=D5, Q4=D6, Q5=D7
  byte data = (nibble << 2) | (isData ? 0x01 : 0x00);
  
  // Step 1: Send data with Enable HIGH
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data | 0x02); 
  digitalWrite(latchPin, HIGH);
  
  // Step 2: Pulse Enable LOW to "Enter" the data
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data & ~0x02); 
  digitalWrite(latchPin, HIGH);
  delayMicroseconds(100);
}

void writeString(const char* s) {
  while (*s) {
    sendToLCD(*s++, 1);
  }
}
