// This is the implementation file for the Pipe class which handles the pipes' movement and animation.
#include "nPipe.h" // Contains the Pipe class
#include "nGlobals.h" // Contains the WIN_WIDTH and WIN_HEIGHT macros

Pipe::Pipe(int y_pos) {
    sprite_down.setTexture(texture_down);
    sprite_up.setTexture(texture_up);

    sprite_down.setScale(SCALE_FACTOR, SCALE_FACTOR);
    sprite_up.setScale(SCALE_FACTOR, SCALE_FACTOR);

    sprite_down.setPosition(WIN_WIDTH, y_pos - pipe_distance - sprite_up.getGlobalBounds().height);
    sprite_up.setPosition(WIN_WIDTH, y_pos);
}

void Pipe::update(sf::Time &dt) {
    sprite_up.move(-move_speed * dt.asSeconds(), 0.f);
    sprite_down.move(-move_speed * dt.asSeconds(), 0.f);
}

void Pipe::loadTextures() {
    texture_down.loadFromFile("assets/pipedown.png");
    texture_up.loadFromFile("assets/pipe.png");
}

float Pipe::getRightBound() {
    return sprite_down.getGlobalBounds().left + sprite_down.getGlobalBounds().width;
}

sf::Texture Pipe::texture_down, Pipe::texture_up;

int Pipe::pipe_distance = 170, Pipe::move_speed = 400;
