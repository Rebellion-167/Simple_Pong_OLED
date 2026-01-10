#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "DisplayManager.h"

// Creating an enum to store the different states
enum GameState {
    STATE_START,
    STATE_PLAYING,
    STATE_WIN
};

// Creating an enum object to track the current state
GameState currentState = STATE_START;

// Flash control
unsigned long lastFlashTime = 0;
bool showStartText = true;

#define FLASH_INTERVAL 500 // milliseconds

// Function to display the start screen
void drawStartScreen() {
    //Handling flash timing
    if(millis() - lastFlashTime > FLASH_INTERVAL) {
        lastFlashTime = millis();
        showStartText = !showStartText;
    }

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(18, 16);
    display.print("NanoPONG");

    if(showStartText) {
        display.setTextSize(1);
        display.setCursor(12, 42);
        display.print("Press START Button");
    }

    display.display();
}

#endif