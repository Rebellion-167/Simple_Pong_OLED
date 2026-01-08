#ifndef SCORE_MANAGER_H
#define SCORE_MANAGER_H

#include <Arduino.h>
#include "DisplayManager.h"

// Scores
int leftScore  = 0;
int rightScore = 0;

// Resetting scores
void resetScores() {
    leftScore = 0;
    rightScore = 0;
}

// Drawing scores on screen
void drawScore() {
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor((SCREEN_WIDTH / 4) - 4, (SCREEN_HEIGHT / 2) - 8);
    display.print(leftScore);

    display.setCursor(((SCREEN_WIDTH * 3)/ 4) - 4, (SCREEN_HEIGHT / 2) - 8);
    display.print(rightScore);
}

#endif