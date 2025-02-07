//including necessary libraries
#include <Arduino.h>
#include <Wire.h>
#include <radio.h>
#include <TEA5767.h>

#define FIX_BAND RADIO_BAND_FM //fixing fm as band

//default station is 91.10
#define FIX_STATION 9110

//object radio from TEA5767 class
TEA5767 radio;

uint8_t test1;
byte test2;


void setup() {
  //open serial port
  Serial.begin(57600);
  Serial.println("Radio...");
  delay(200);

  // Initialize the Radio 
  radio.init();

  // Enable information to the Serial port
  radio.debugEnable();

  // HERE: adjust the frequency to a local sender
  radio.setBandFrequency(FIX_BAND, FIX_STATION); // hr3 nearby Frankfurt in Germany
  radio.setVolume(2);
  radio.setMono(false);

}

/// show the current chip data every 3 seconds.
void loop() {
  char s[12];
  radio.formatFrequency(s, sizeof(s));
  Serial.print("Station:"); 
  Serial.println(s);
  
  Serial.print("Radio:"); 
  radio.debugRadioInfo();
  
  Serial.print("Audio:"); 
  radio.debugAudioInfo();

  delay(3000);
} // loop