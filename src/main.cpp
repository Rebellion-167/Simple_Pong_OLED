#include <Arduino.h>
#include "DisplayManager.h"
#include "InputManager.h"
#include "BallManager.h"
#include "PaddleManager.h"
#include "ScoreManager.h"

void setup() {
  displayInit();
  inputInit();
  initBall();
  initPaddles();
  resetScores();
}

void loop() {
  handleInput();

  display.clearDisplay();

  drawArena();
  drawScore();

  updateBall();
  updatePaddles();

  drawBall();
  drawPaddles();

  display.display();

  delay(20);
}