/*
  A very rough code using the LED matrix to display
  the output of a light sensor
*/

#include "Arduino_LED_Matrix.h"
#include "Adafruit_VEML7700.h"

ArduinoLEDMatrix matrix;
Adafruit_VEML7700 veml = Adafruit_VEML7700();

uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setup() {
  matrix.begin();

  // Note that I'm using Wire1 since my sensor is plugged
  // on the Qwiic connector
  veml.begin(&Wire1);

  veml.setIntegrationTime(VEML7700_IT_50MS);
}

void loop() {
  int nb_col = map(veml.readLux(), 100, 1000, 1, 12);

  for (int j = 0; j < 12; j++) {
    int state = (j < nb_col) ? 1 : 0;
    
    for (int i = 0; i < 8; i++) {
      frame[i][j] = state;
    }
  }

  matrix.renderBitmap(frame, 8, 12);
  delay(50);
}
