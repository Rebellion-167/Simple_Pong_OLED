#include <Arduino.h>
#include "DisplayManager.h"
#include "InputManager.h"

void setup() {
  displayInit();
  inputInit();
}

void loop() {
  handleInput();
  drawArena();
  delay(20);
}