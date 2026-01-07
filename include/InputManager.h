#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <Arduino.h>

// Button pin definitions
#define BTN_UP     2
#define BTN_DOWN   3
#define BTN_START  4

// Button state flags
bool btnUpPressed = false;
bool btnDownPressed = false;
bool btnMidPressed = false;

// Initializing button pins
void inputInit() {
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_START, INPUT_PULLUP);
}

// Handling button input and updating paddle positions
void handleInput() {
    btnUpPressed = (digitalRead(BTN_UP) == LOW);
    btnDownPressed = (digitalRead(BTN_DOWN) == LOW);
    btnMidPressed = (digitalRead(BTN_START) == LOW);
}

#endif
