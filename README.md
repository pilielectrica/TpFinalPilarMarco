# La Viborita — C++ Console Game

A classic Snake-style console game developed in **C++14** as a programming project.

The project focuses on core C++ and game-programming concepts such as object-oriented design, inheritance, real-time input, collision detection, game-state management, and a simple update loop without using a game engine.

## Gameplay

Control the snake around the board, collect food, and grow its body while increasing your score.

- Each collected food item adds **10 points**.
- The snake grows after collecting food.
- Food is relocated to a random position inside the board.
- The game ends if the snake collides with the border or with its own body.
- Reaching **2000 points** triggers the win condition.

## Controls

Use the **arrow keys** to control the snake:

- ↑ Up
- ↓ Down
- ← Left
- → Right

## Technical Features

- **C++14**
- Object-oriented architecture
- Class inheritance and virtual methods
- Real-time keyboard input
- Position and movement management
- Snake body tracking
- Collision detection
- Score and win/lose states
- Randomized food placement
- Console rendering and color
- Timing-based movement

## Code Structure

The game is divided into several classes:

- **`Juego`** — manages the main game loop, scoring, food collection, collision checks, and win/lose conditions.
- **`Pelota`** — base class containing position, direction, timing, movement, drawing, and color behavior.
- **`Viborita`** — derives from `Pelota` and implements snake-specific input, body tracking, drawing, and self-collision detection.
- **`Comida`** — derives from `Pelota` and represents the collectible food.
- **`Tablero`** — renders the console playfield.

The entry point in `main.cpp` initializes the random seed, creates the game object, and starts the main loop.

## Requirements

The original project is configured as a **Win32 console application** using:

- C++14
- MinGW
- `conio2`
- Windows console APIs

The original project configuration is included in `LaViboritaPM/LaViboritaPM.zpr`.

Because the implementation uses `windows.h`, `conio2.h`, `_kbhit()`, `_getch()`, and Windows console functions, it is intended to run on **Windows**.

## Building

The project was created with **ZinjaI** and contains Debug and Release Win32 configurations.

To build it in another C++ environment:

1. Use a compiler with **C++14** support.
2. Install the **conio2** headers and library and make them available to the compiler.
3. Link against the `conio` library.
4. Compile the `.cpp` files inside `LaViboritaPM/` together.

## About

This is an academic C++ project created while studying **Video Game Design and Programming**.

It is part of my programming portfolio and demonstrates experience working directly with C++ fundamentals and gameplay logic without relying on a game engine, alongside my work in game audio, technical audio, and game-development tools.
