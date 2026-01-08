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

  if(gameWon) {
    drawWinScreen();

    // Restarting on any button press
    if(btnUpPressed || btnDownPressed) {
      resetScores();
      initBall();
      initPaddles();
    }
    delay(200);
    return;
  }
  
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