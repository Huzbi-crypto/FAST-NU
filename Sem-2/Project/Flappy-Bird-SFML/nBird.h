#pragma once
#include <SFML/Graphics.hpp>

class nBird
{
private:
	sf::Texture bird_textures[2];
	const int gravity;
	const int flap_speed;
	float falling_velocity_posY;
	int anim_counter, texture_switcher;
	bool should_fly;
public:
	sf::Sprite bird_sprite;
	nBird();

	void setShouldFly(bool should_fly);
	void flapBirdAction(sf::Time& dt);
	void resetPosition();
	void updateFallingPosition(sf::Time& dt);
	float getRightBound();
};

