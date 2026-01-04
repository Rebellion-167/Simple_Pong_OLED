#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <Arduino.h>
#include "DisplayManager.h"

// Button pin definitions
#define BTN_UP     2
#define BTN_DOWN   3
#define BTN_START  4

// Paddle movement speed
#define PADDLE_SPEED  2

// Initializing button pins
void inputInit() {
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_START, INPUT_PULLUP);
}

// Handling button input and updating paddle positions
void handleInput() {
    // Moving paddle up
    if(digitalRead(BTN_UP) == LOW) 
        leftPaddleY -= PADDLE_SPEED;

    // Moving paddle down
    if(digitalRead(BTN_DOWN) == LOW)
        leftPaddleY += PADDLE_SPEED;

    // Boundary limits
    if(leftPaddleY < 1) leftPaddleY = 1;

    if(leftPaddleY > SCREEN_HEIGHT - PADDLE_HEIGHT - 1)
        leftPaddleY = SCREEN_HEIGHT - PADDLE_HEIGHT - 1;

}
#endif
