# Flappy Bird with SFML

Many credits goes to: https://github.com/tuffleroot/flappy-bird-cpp-sfml

## Description

This is a simple Flappy Bird game made with C++ and SFML.

## How to play

Press `Space` to jump.

## How to build

### Linux

1. Install SFML
2. Clone this repository
3. Run `make` in the root directory of this repository
4. Run `./flappy-bird`

## Details

### Game

This is a game made with C++ and SFML. The game is a simple Flappy Bird clone. The game is made with SFML 2.5.1. The game is made on Visual Studio Code. Currently, this game is easily run on Linux due to the Makefile. The game is not tested on Windows or Mac. 

### Code
There are 3 main classes in this game: `Game`, `Bird`, and `Pipe`. The `Game` class is the main class of the game. It handles the game loop and the game logic. The `Bird` class is the class that handles the bird. The `Pipe` class is the class that handles the pipes. The `Game` class has a `Bird` object and a `Pipe` object. The `Bird` class has a `sf::RectangleShape` object. The `Pipe` class has 2 `sf::RectangleShape` objects. The `Game` class has objects that are used make the Game logic. The `Bird` class has objects that are used to make the bird. The `Pipe` class has objects that are used to make the pipes. 
