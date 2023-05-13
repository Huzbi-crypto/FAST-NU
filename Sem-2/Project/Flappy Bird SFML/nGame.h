// This is the header file for the Game class which handles the game loop and the game logic.
#pragma once
#include <SFML/Graphics.hpp> // Contains the RenderWindow class and the Texture class 
#include "nBird.h" // Contains the Bird class
#include <vector> // Contains the vector class which is used to store the pipes
#include "nPipe.h" // Contains the Pipe class
#include <random> // Contains the random_device class and the uniform_int_distribution class which are used to generate random numbers

class Game {
public:
    Game(sf::RenderWindow&);
    sf::RenderWindow& win;
    void startGameLoop();
private:
    sf::Texture bg_texture, ground_texture;
    sf::Sprite bg_sprite, ground_sprite1, ground_sprite2;
    Bird bird;
    bool is_enter_pressed, run_game, start_monitoring;
    const int move_speed = 270;
    void draw();
    void moveGround(sf::Time&);
    void doProcessing(sf::Time &dt);
    void checkCollisions();
    void restartGame();
    void checkScore();
    std::string toString(int);
    int pipe_counter, pipe_spawn_time, score;
    std::vector<Pipe> pipes;
    std::random_device rd;
    std::uniform_int_distribution<int> dist{ 250, 550};
    sf::Font font;
    sf::Text restart_text, score_text;
};
