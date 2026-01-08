#ifndef SCORE_MANAGER_H
#define SCORE_MANAGER_H

#include <Arduino.h>
#include "DisplayManager.h"

#define WIN_SCORE 5

// Scores
int leftScore  = 0;
int rightScore = 0;
bool gameWon   = false;

// Resetting scores
void resetScores() {
    leftScore  = 0;
    rightScore = 0;
    gameWon    = false;
}

// Checking winning condition
void checkWin() {
    if(leftScore >= WIN_SCORE || rightScore >= WIN_SCORE) {
        gameWon = true;
    }
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

// Displaying the win screen
void drawWinScreen() {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(22, 20);
    if(leftScore >= WIN_SCORE) {
        display.print("YOU WIN!");
    } else {
        display.print("AI WINS!");
    }

    display.setTextSize(1);
    display.setCursor(27, 40);
    display.print("Press button");

    display.display();
}

#endif