// This is the main.cpp file:
#include <SFML/Graphics.hpp> // Contains the RenderWindow class and the VideoMode class
#include "nGlobals.h" // Contains the WIN_WIDTH and WIN_HEIGHT macros
#include "nGame.h" // Contains the Game class

int main() {
    sf::RenderWindow win(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Flappy Bird");
    Game game(win);
    game.startGameLoop();

    return 0;
}
