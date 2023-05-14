# Flappy Bird Game with SFML

## Description

This is a simple Flappy Bird game made with SFML. The game is written in C++ and the graphics are made with SFML. The game is made for educational purposes only.

## How to play

The game is simple. To start the game, you have to press enter. To make the bird jump, you have to press space. The goal is to get as far as possible without hitting the pipes. If you hit a pipe, the game is over. To restart the game after you lose, click on restart and the game will start again.

## How to build

### Windows

1. Download the [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) library.
2. Extract the downloaded file.
3. Go to this [link](https://www.sfml-dev.org/tutorials/2.5/start-vc.php) and follow the instructions to set up SFML with Visual Studio.
4. Clone this repository.
5. Open the project in Visual Studio.
6. Go to Project -> Properties -> C/C++ -> General -> Additional Include Directories and add the path to the include folder in the SFML folder.
7. Go to Project -> Properties -> Linker -> General -> Additional Library Directories and add the path to the lib folder in the SFML folder.
8. Go to Project -> Properties -> Linker -> Input -> Additional Dependencies and add the following SFML libraries: sfml-graphics.lib, sfml-window.lib, sfml-system.lib, sfml-audio.lib.
9. Build the project.

### Linux

Currently, this game has not been tested on Linux. However, it should work if you know how to compile multiple files with SFML.

## Details

### Bird

The class `nBird` has been set up which handles the animation for the bird such as flapping its wings and falling down. The bird is drawn as a rectangle with a texture. The texture is changed depending on the animation. The bird is also moved depending on the animation. The bird is moved up when the space key is pressed and it is moved down when the space key is not pressed. The bird is also moved down when the game is over.

### Pipes

The class `nPipe` has been set up which handles the pipes. The pipes are drawn as rectangles. The pipes are moved to the left. When the pipes go out of the screen, they are moved to the right. The pipes stop generating when the game is over.

### Collision

The collision is handled by the function `checkCollision` which checks if the bird has hit a pipe. If the bird has hit a pipe, the game is over. It also checks if the bird has hit the ground. If the bird has hit the ground, the game is over.

### Score

The score is handled by the function `checkScore` which checks if the bird has passed a pipe. If the bird has passed a pipe, the score is increased by one. The score is displayed on the screen. The score gets reset when the game is over.

### Game

The `nGame` class handles the game. It handles the game loop and the game states. The game states are the game and the game over screen. The game state is changed when the game is over. The game state is changed to the game over screen. The game state is changed back to the game when the "Restart Game!!" is clicked.
