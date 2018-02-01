// Copyright (C) 2008 Mike McCauley
//with additional sections for LCD by Appliance Paul on Youtube: https://youtu.be/Q2iECOsfCqA


#include <VirtualWire.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup()
{
    Serial.begin(9600);	// Debugging only
     lcd.begin(16,2);
    Serial.println("setup");

    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec

    vw_rx_start();       // Start the receiver PLL running
}

void loop()
{
    lcd.setCursor(0, 0);
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      lcd.print((char *)buf); //was char *
      delay(5000); //was 5000
      lcd.clear();
    }
   else if (!vw_get_message(buf, &buflen))
   {
     lcd.print("Out of range.");
     delay(5000);
     lcd.clear();
   }
}


/*
      int i;

        digitalWrite(13, true); // Flash a light to show received good message
	// Message with a good checksum received, dump it.
	Serial.print("Got: ");
	
	for (i = 0; i < buflen; i++)
	{
	    Serial.print(buf[i], HEX);
	    Serial.print(" ");
	}
	Serial.println("");
        digitalWrite(13, false);
*/
