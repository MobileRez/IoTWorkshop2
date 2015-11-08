#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int colorR = 255;
int colorG = 255;
int colorB = 255;

// Define the pin to which the temperature sensor is connected.
const int pinTemp = A0;

// Define the B-value of the thermistor.
// This value is a property of the thermistor used in the Grove - Temperature Sensor,
// and used to convert from the analog value it measures and a temperature value.
const int B = 3975;

void setup() {
    // Configure the serial communication line at 9600 baud (bits per second.)
    Serial.begin(9600);
    
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd.print("Current Temp:");

    delay(1000);
}

void loop() {
    // Get the (raw) value of the temperature sensor.
    int val = analogRead(pinTemp);

    // Determine the current resistance of the thermistor based on the sensor value.
    float resistance = (float)(1023-val)*10000/val;
    
    // Calculate the temperature based on the resistance value.
    float temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15;

    // Convert from Celcius to Farenheit
    temperature = temperature * 1.8 + 32;

    if (temperature < 17)
    {
      colorR = 100;
      colorG = 0;
      colorB = 255;
    }
    else if (temperature >= 18 && temperature <= 31)
    {
      colorR = 0;
      colorG = 0;
      colorB = 255;
    }
    else if (temperature >= 32 && temperature <= 41)
    {
      colorR = 0;
      colorG = 127;
      colorB = 255;
    }
    else if (temperature >= 42 && temperature <= 49)
    {
      colorR = 0;
      colorG = 255;
      colorB = 255;
    }
    else if (temperature >= 50 && temperature <= 57)
    {
      colorR = 0;
      colorG = 255;
      colorB = 127;
    }
    else if (temperature >= 58 && temperature <= 65)
    {
      colorR = 0;
      colorG = 255;
      colorB = 0;
    }
    
    else if (temperature >= 66 && temperature <= 74)
    {
      colorR = 127;
      colorG = 255;
      colorB = 0;
    }
    
    else if (temperature >= 75 && temperature <= 84)
    {
      colorR = 255;
      colorG = 255;
      colorB = 0;
    }
    
    else if (temperature >= 85 && temperature <= 99)
    {
      colorR = 255;
      colorG = 127;
      colorB = 0;
    }
    
    else if (temperature > 100)
    {
      colorR = 255;
      colorG = 0;
      colorB = 0;
    }

    lcd.setRGB(colorR, colorG, colorB);
    //Set cursor to row 1 & print the temperature to the LCD.
    lcd.setCursor(0, 1);
    lcd.print(temperature);

    delay(500);

}
