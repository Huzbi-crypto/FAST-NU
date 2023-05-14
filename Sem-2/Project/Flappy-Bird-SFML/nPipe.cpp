#include "nPipe.h"
#include "nGlobals.h"

nPipe::nPipe(int pipe_face_up_posY)
{
	pipe_face_down_sprite.setTexture(pipe_up_face_texture);
	pipe_face_up_sprite.setTexture(pipe_down_face_texture);

	pipe_face_down_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
	pipe_face_up_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);

	pipe_face_down_sprite.setPosition(WIN_WIDTH, pipe_face_up_posY);
	pipe_face_up_sprite.setPosition(WIN_WIDTH, pipe_face_up_posY - pipes_distance_between - pipe_face_up_sprite.getGlobalBounds().height);
}

void nPipe::loadPipeTextures()
{
	pipe_up_face_texture.loadFromFile("assets/pipe.png");
	pipe_down_face_texture.loadFromFile("assets/pipedown.png");
}

void nPipe::updatePipesMovement(sf::Time& dt)
{
	pipe_face_down_sprite.move(-pipe_movement_speed * dt.asSeconds(), 0.f);
	pipe_face_up_sprite.move(-pipe_movement_speed * dt.asSeconds(), 0.f);
}

float nPipe::getRightBound()
{
	return pipe_face_down_sprite.getGlobalBounds().left + pipe_face_down_sprite.getGlobalBounds().width;
}


sf::Texture nPipe::pipe_up_face_texture, nPipe::pipe_down_face_texture;
int nPipe::pipes_distance_between = 100, nPipe::pipe_movement_speed = 400;