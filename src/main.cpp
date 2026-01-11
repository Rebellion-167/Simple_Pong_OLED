#include <Arduino.h>
#include "DisplayManager.h"
#include "InputManager.h"
#include "BallManager.h"
#include "PaddleManager.h"
#include "ScoreManager.h"
#include "StartScreen.h"
#include "CountdownManager.h"

void setup() {
  displayInit();
  inputInit();
  initBall();
  initPaddles();
  resetScores();
}

void loop() {
  handleInput();

  // Start Screen
  if(currentState == STATE_START) {
    drawStartScreen();

    if(btnMidPressed) {
      resetScores();
      initBall();
      initPaddles();
      startCountdown();
      currentState = STATE_COUNTDOWN;
      delay(200);
    }
    return;
  }

  if(currentState == STATE_COUNTDOWN) {
    updateCountdown();
    drawCountdown();

    if(countdownDone) {
      currentState = STATE_PLAYING;
    }
    return;
  }
  
  // Win Screen
  if(currentState == STATE_WIN) {
    display.clearDisplay();
    drawWinScreen();
    display.display();

    if(btnMidPressed) {
      currentState = STATE_START;
      delay(200);
    }
    return;
  }

  // Game Play
  display.clearDisplay();

  drawArena();
  drawScore();

  updateBall();
  updatePaddles();

  if(gameWon) {
    currentState = STATE_WIN;
    return;
  }

  drawBall();
  drawPaddles();

  display.display();
  delay(20);
}