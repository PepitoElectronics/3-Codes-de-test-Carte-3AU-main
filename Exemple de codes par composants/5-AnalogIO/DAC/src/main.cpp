#include <Arduino.h>

/**************************************************************************/
/*! 
    @file     trianglewave.pde
    @author   Adafruit Industries
    @license  BSD (see license.txt)

    This example will generate a triangle wave with the MCP4725 DAC.   
*/
/**************************************************************************/

#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

void setup(void) {
  Serial.begin(9600);
  Serial.println("Hello!");

  // For Adafruit MCP4725A1 the address is 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // For MCP4725A0 the address is 0x60 or 0x61
  // For MCP4725A2 the address is 0x64 or 0x65
  dac.begin(0x62);
    
  Serial.println("Generating a triangle wave");
}

void loop(void) {
    uint32_t counter;
    // Run through the full 12-bit scale for a triangle wave
    for (counter = 0; counter < 4095; counter++)
    {
      dac.setVoltage(counter, false);
    }
    for (counter = 4095; counter > 0; counter--)
    {
      dac.setVoltage(counter, false);
    }
}