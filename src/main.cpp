#include <Arduino.h>
#include "DisplayManager.h"
#include "InputManager.h"
#include "BallManager.h"
#include "PaddleManager.h"

void setup() {
  displayInit();
  inputInit();
  initBall();
  initPaddles();
}

void loop() {
  handleInput();

  display.clearDisplay();

  drawArena();

  updateBall();
  updatePaddles();

  drawBall();
  drawPaddles();

  display.display();

  delay(20);
}