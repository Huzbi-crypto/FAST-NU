#pragma once
#include <SFML/Graphics.hpp>

class nPipe
{
private:
	static sf::Texture pipe_up_face_texture, pipe_down_face_texture;
	static int pipes_distance_between, pipe_movement_speed;
public:
	sf::Sprite pipe_face_down_sprite, pipe_face_up_sprite;
	nPipe(int pipe_face_up_posY);

	static void loadPipeTextures();
	void updatePipesMovement(sf::Time& dt);
	float getRightBound();
};

