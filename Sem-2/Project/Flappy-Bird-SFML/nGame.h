#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "nBird.h"
#include "nPipe.h"

class nGame
{
public:
	// making a parameterized constructor that takes the reference of game's window as argument to run the game loop in it
	nGame(sf::RenderWindow& game_window);
	sf::RenderWindow& game_window;
	int ground_posY = 578; // a y position for doing several things

	// making the method for the game loop which will contain the playthrough
	void startGameLoop();

private:
	sf::Texture bg_texture, ground_texture;
	sf::Sprite bg_sprite, ground_sprite1, ground_sprite2;
	sf::Clock clock;
	sf::Font font;
	sf::Text restart_text, score_text;
	nBird flappy_bird;
	std::vector<nPipe> pipes;
	std::random_device rd;
	std::uniform_int_distribution<int> dist{ 250,550 };
	std::string toString(int);
	bool is_enter_pressed, is_game_paused, is_monitoring_start;
	const int movement_speed = 270;
	int pipe_counter, pipe_spawn_time, score;

	void draw_texture();
	void moveGround(sf::Time& dt);
	void doProcessing(sf::Time& dt);
	void checkCollisions();
	void restartGame();
	void checkScore();
};

