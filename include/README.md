# Include Directory - Game Modules

This directory contains all the core game modules for the Arduino-based Pong game.
Each feature of the game is implemented as a seperate header file, following a modular, procedural design.

## File Overview

- `DisplayManager.h` : Handles all OLED display initialization and arena rendering. Draws game borders and center line.
- `InputManger.h` : Manages user input from physical buttons. Initializes button pins, reads button states and exposes simple boolean flags.
- `BallManager.h` : Controls ball behaviour and physics. Handles ball-paddle collison and ball reset logic after scoring.
- `PaddleManager.h` : Manages both paddles. Left paddle controlled by player input. Right paddle controlled by a simple CPU code.
- `ScoreManager.h` : Handles scoring and win conditions. Detects winning condition and renders scores on screen.
- `StartScreen.h` : Responsible for the game's start screen. 
- `CountdownManager.h` : Implements the countdown before serve.

