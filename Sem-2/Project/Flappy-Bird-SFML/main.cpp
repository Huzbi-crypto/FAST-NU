// The Flappy Bird game made with SFML library
// Members:
// 1. Huzefa Saifuddin, 22K-5125
// 2. Areeb-ur-Rehman, 22K-6003
// 3. Danish Khan, 22K-5107
#include <SFML/Graphics.hpp>
#include "nGlobals.h"
#include "nGame.h"

// creating the main driver
int main() {
	// Creating an object of SFML's RenderWindow which will render the window of the game at the start
	sf::RenderWindow game_window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "The Flappy Bird Game");

	// Creating an object of nGame class which will run the game loop
	nGame flappy_game(game_window);
	flappy_game.startGameLoop();

	return 0;
}
