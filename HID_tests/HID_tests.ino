#include <Keyboard.h>

void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();

  delay(2000);
}

void loop() {
  if (digitalRead(0) == LOW) {
    Keyboard.print("Like, ");
    delay(500);
  }
    if (digitalRead(1) == LOW) {
    Keyboard.print("Share, ");
    delay(500);
  }
    if (digitalRead(2) == LOW) {
    Keyboard.print("Subscribe!");
    delay(500);
  }
}