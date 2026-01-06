#ifndef BALL_MANAGER_H
#define BALL_MANAGER_H

#include <Arduino.h>
#include "DisplayManager.h"
#include "InputManager.h"

// Screen boundaries
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Ball properties
int ballX = SCREEN_WIDTH / 2;
int ballY = SCREEN_HEIGHT / 2;
int ballRadius = 2;

// Ball velocities
int ballVelX = 1;
int ballVelY = 1;

// Game State
bool gameOver = false;

// Initializing ball and game state
void initBall() {
    ballX = SCREEN_WIDTH / 2;
    ballY = SCREEN_HEIGHT / 2;
    ballVelX = 1;
    ballVelY = 1;
    gameOver = false;
}

// Updating ball position and detecting game over
void updateBall() {
    if (gameOver) return;

    ballX += ballVelX;
    ballY += ballVelY;

    // Bouncing from top and bottom walls
    if(ballY - ballRadius <= 0 || ballY + ballRadius >= SCREEN_HEIGHT - 1)
        ballVelY = -ballVelY;

    // Left paddle collision
    if (ballVelX < 0 && 
        ballX - ballRadius <= leftPaddleX + PADDLE_WIDTH &&
        ballY >= leftPaddleY &&
        ballY <= leftPaddleY + PADDLE_HEIGHT) {
            
            ballVelX = -ballVelX;

            int paddleCenter = leftPaddleY + PADDLE_HEIGHT / 2;
            ballVelY = (ballY - paddleCenter) / 4;

            ballX = leftPaddleX + PADDLE_WIDTH + ballRadius;
    }

    // Right paddle collision
    if (ballVelX > 0 &&
        ballX + ballRadius >= rightPaddleX &&
        ballY >= rightPaddleY && 
        ballY <= rightPaddleY + PADDLE_HEIGHT) {
            
            ballVelX = -ballVelX;

            int paddleCenter = rightPaddleY + PADDLE_HEIGHT / 2;
            ballVelY = (ballY - paddleCenter) / 4;

            ballX = rightPaddleX - ballRadius;
    }

    // Game over if ball hits vertical walls
    if(ballX - ballRadius <= 0 || ballX + ballRadius >= SCREEN_WIDTH - 1)
        gameOver = true;
}

// Drawing the ball on the display
void drawBall() {
    if(gameOver) return;
    display.fillCircle(ballX, ballY, ballRadius, SSD1306_WHITE);
}

#endif