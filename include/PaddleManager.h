#ifndef PADDLE_MANAGER_H
#define PADDLE_MANAGER_H

#include <Arduino.h>
#include "DisplayManager.h"
#include "InputManager.h"
#include "BallManager.h"

// Paddle sizes
#define PADDLE_WIDTH   3
#define PADDLE_HEIGHT 16

// Paddle speeds
#define PADDLE_SPEED    2
#define AI_PADDLE_SPEED 1

// Paddle X positions
const int leftPaddleX = 4;
const int rightPaddleX = SCREEN_WIDTH - 4 - PADDLE_WIDTH;

// Paddle Y positions
int leftPaddleY;
int rightPaddleY;

// Initialize paddles
void initPaddles() {
    leftPaddleY = (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2;
    rightPaddleY = (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2;
}

// Player-controlled left paddle
void updateLeftPaddle() {
    if(btnUpPressed) {
        leftPaddleY -= PADDLE_SPEED;
    }
    if(btnDownPressed) {
        leftPaddleY += PADDLE_SPEED;
    }

    if(leftPaddleY < 0) {
        leftPaddleY = 0;
    }

    if(leftPaddleY > SCREEN_HEIGHT - PADDLE_HEIGHT) {
        leftPaddleY = SCREEN_HEIGHT - PADDLE_HEIGHT;
    }
}

// AI-controlled right paddle
void updateRightPaddle() {
    int paddleCenter = rightPaddleY + PADDLE_HEIGHT / 2;

    if(ballY < paddleCenter - 2) {
        rightPaddleY -= AI_PADDLE_SPEED;
    }
    else if(ballY > paddleCenter + 2) {
        rightPaddleY += AI_PADDLE_SPEED;
    }

    if(rightPaddleY < 0) {
        rightPaddleY = 0;
    }

    if(rightPaddleY > SCREEN_HEIGHT - PADDLE_HEIGHT) {
        rightPaddleY = SCREEN_HEIGHT - PADDLE_HEIGHT;
    }
}

// Updating both paddles
void updatePaddles() {
    updateLeftPaddle();
    updateRightPaddle();
}

// Draw both paddles
void drawPaddles() {
    display.fillRect(leftPaddleX, leftPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, SSD1306_WHITE);
    display.fillRect(rightPaddleX, rightPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, SSD1306_WHITE);
}

#endif