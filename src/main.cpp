#include <Arduino.h>
#include "DisplayManager.h"
#include "InputManager.h"
#include "BallManager.h"

void setup() {
  displayInit();
  inputInit();
  initBall();
}

void loop() {
  display.clearDisplay();

  handleInput();
  updateBall();

  drawArena();
  drawBall();

  display.display();
  delay(20);
}