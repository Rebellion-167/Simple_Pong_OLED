#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Configurations
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT  64
#define OLED_RESET     -1
#define OLED_ADDR    0x3C

// Paddle configuration
#define PADDLE_WIDTH    3
#define PADDLE_HEIGHT  16

// Display Object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Paddle position
int leftPaddleY  = (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2;
int rightPaddleY = (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2;

// Initializing OLED
void displayInit() {
    Wire.begin();

    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        while(1); // Halting execution if display not found
    }

    display.clearDisplay();
    display.display();
}


// Drawing Pong Arena
void drawArena() {
    // display.clearDisplay();

    // Top and Bottom borders
    display.drawFastHLine(0, 0, SCREEN_WIDTH, SSD1306_WHITE);
    display.drawFastHLine(0, SCREEN_HEIGHT - 1, SCREEN_WIDTH, SSD1306_WHITE);

    // Left and Right borders
    display.drawFastVLine(0, 0, SCREEN_HEIGHT, SSD1306_WHITE);
    display.drawFastVLine(SCREEN_WIDTH - 1, 0, SCREEN_HEIGHT, SSD1306_WHITE);

    // Centre line
    display.drawFastVLine(SCREEN_WIDTH / 2, 0, SCREEN_HEIGHT, SSD1306_WHITE);

    // Left Paddle
    display.fillRect(5, leftPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, SSD1306_WHITE);

    // Right Paddle
    display.fillRect(SCREEN_WIDTH - 10, rightPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT, SSD1306_WHITE);

    // display.display();
}

#endif