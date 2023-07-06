/*
  Code with on purpose memory access mistake to test the
  error reporting capabilities of the Arduino UNO R4

  As I explained in the video, on a R4 WiFi the first test will
  crash the board but the R4 Minima only crash on the second one.
*/

char a[5];

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  Serial.println("Hello World!");

  // First test: Array error
  for (int i = 0; i < 200; i++) {
    a[i] = 1;
  }
  Serial.println("No Array error");

  // Second test: Invalid memory address
  int* pointer = NULL;
  for (int i = 0; i < 1000; i++) {
    pointer--;
    *pointer = i++;
  }
  Serial.println("I don't see the problem…");
}

void loop() {
  Serial.println("You can't see me");
  delay(5000);
}
