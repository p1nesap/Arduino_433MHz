//Code by Mike McCauley (mikem@airspayce.com) Copyright (C) 2008 Mike McCauley
//with LCD sections by P1nesap on YouTube: https://youtu.be/Q2iECOsfCqA

#include <VirtualWire.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
void setup()
{
    Serial.begin(9600);	  // Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
}

void loop()
{
    const char *msg = "433 MHz contact.";

    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
    delay(5000);
    
  
    // 2nd message
    const char *msgb = "Still receiving...";

    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msgb, strlen(msgb));
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
    delay(5000);
    
}