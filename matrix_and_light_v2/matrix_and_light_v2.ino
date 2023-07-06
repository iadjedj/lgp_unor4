/*
  Display the output of a light sensor
  on the LED matrix using two smiley faces  
*/

#include "Arduino_LED_Matrix.h"
#include "Adafruit_VEML7700.h"

ArduinoLEDMatrix matrix;
Adafruit_VEML7700 veml = Adafruit_VEML7700();

const uint32_t happy[3] = {
		0x19,
		0x81980001,
		0x80f0000
};

const uint32_t unhappy[3] = {
		0x19,
		0x81980000,
		0xf0108000,
};


void setup() {
  matrix.begin();

  // Note that I'm using Wire1 since my sensor is plugged
  // on the Qwiic connector
  veml.begin(&Wire1);

  veml.setIntegrationTime(VEML7700_IT_50MS);
}

void loop() {
  int lux = veml.readLux();

  if (lux < 200)
    matrix.loadFrame(unhappy);
  else
    matrix.loadFrame(happy);

  delay(50);
}