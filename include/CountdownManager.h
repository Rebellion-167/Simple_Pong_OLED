#ifndef COUNTDOWN_MANAGER_H
#define COUNTDOWN_MANAGER_H

#include <Arduino.h>
#include "DisplayManager.h"

int countdownValue = 3;
unsigned long lastCountTime = 0;
bool countdownDone = false;

// Function to start the countdown
void startCountdown() {
    countdownValue = 3;
    countdownDone = false;
    lastCountTime = millis();
}

// Function to keep updating the countdown
void updateCountdown() {
    if(millis() - lastCountTime >= 1000) {
        lastCountTime = millis();
        countdownValue--;

        if(countdownValue < 0) {
            countdownDone = true;
        }
    }
}

// Function to draw the countdown on the screen
void drawCountdown() {
    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);

    if(countdownValue > 0) {
        display.setTextSize(3);
        display.setCursor(56, 20);
        display.print(countdownValue);
    } else {
        display.setTextSize(2);
        display.setCursor(48,22);
        display.print("GO");
    }

    display.display();
}

#endif