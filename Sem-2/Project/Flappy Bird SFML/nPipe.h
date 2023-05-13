// This is the header file for the Pipe class which handles the pipes' movement and animation.
#pragma once
#include <SFML/Graphics.hpp> // Contains the Sprite class

class Pipe {
public:
    Pipe(int);
    sf::Sprite sprite_up, sprite_down;
    static void loadTextures();
    void update(sf::Time&);
    float getRightBound();

private:
    static sf::Texture texture_down, texture_up;
    static int pipe_distance, move_speed;
};
