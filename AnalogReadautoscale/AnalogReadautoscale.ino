/*
  My version of the basic "Analog Read Serial" Arduino example
  adding analogReadResolution() to change the ADC resolution
  and demonstrating its use as a getter.
*/

float scaling_factor;

void setup() {
  Serial.begin(9600);

  while (!Serial) {}

  analogReadResolution(14);
  // You can also use analogReadResolution() to get the current resolution  
  scaling_factor = 5000 / (pow(2, analogReadResolution()) - 1);
}

void loop() {
  int sensorValue = analogRead(A0);
  float volts = sensorValue * scaling_factor;

  Serial.print(sensorValue);
  Serial.print(" (raw) / ");
  Serial.print(volts);
  Serial.println("mV");

  delay(100);
}
