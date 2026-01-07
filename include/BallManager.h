#ifndef BALL_MANAGER_H
#define BALL_MANAGER_H

#include <Arduino.h>
#include "DisplayManager.h"
#include "PaddleManager.h"

// Ball properties
#define BALL_RADIUS 2

// Ball position and velocity
int ballX;
int ballY;
int ballVelX;
int ballVelY;

// Game state
bool gameOver = false;

// Initialize ball at center
void initBall() {
    ballX = SCREEN_WIDTH / 2;
    ballY = SCREEN_HEIGHT / 2;
    ballVelX = 2;
    ballVelY = 1;
    gameOver = false;
}

//Handling ball-paddle collisions
void handlePaddleCollision() {
    // Left paddle
    if(ballVelX < 0) {
        if(ballX - BALL_RADIUS <= leftPaddleX + PADDLE_WIDTH &&
           ballX - BALL_RADIUS >= leftPaddleX && 
           ballY >= leftPaddleY && 
           ballY <= leftPaddleY + PADDLE_HEIGHT) {
            ballVelX = -ballVelX;

            // Changing Y velocity based on hit position
            int paddleCenter = leftPaddleY + PADDLE_HEIGHT / 2;
            int hitOffset = ballY - paddleCenter;
            ballVelY = hitOffset / 4;
        }
    }

    // Right Paddle
    if(ballVelX > 0) {
        if(ballX + BALL_RADIUS >= rightPaddleX && 
           ballX + BALL_RADIUS <= rightPaddleX + PADDLE_WIDTH &&
           ballY >= rightPaddleY &&
           ballY <= rightPaddleY + PADDLE_HEIGHT) {
            ballVelX = -ballVelX;

            int paddleCenter = rightPaddleY + PADDLE_HEIGHT / 2;
            int hitOffset = ballY - paddleCenter;
            ballVelY = hitOffset / 4;
        } 
    }
}
// Updating ball position and handle collisions on wall
void updateBall() {
    if(gameOver) return;

    ballX += ballVelX;
    ballY += ballVelY;

    // Top and bottom wall collision
    if(ballY <= BALL_RADIUS || ballY >= SCREEN_HEIGHT - BALL_RADIUS) {
        ballVelY = -ballVelY;
    }

    // Paddle collisions
    handlePaddleCollision();
    
    // Left and right wall -> Game Over
    if(ballX <= BALL_RADIUS || ballX >= SCREEN_WIDTH - BALL_RADIUS) {
        gameOver = true;
    }
}

// Drawing the ball as a circle
void drawBall() {
    if(gameOver) return;

    display.fillCircle(ballX, ballY, BALL_RADIUS, SSD1306_WHITE);
}

#endif