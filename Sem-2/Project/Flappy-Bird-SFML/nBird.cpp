#include "nBird.h"
#include "nGlobals.h"

nBird::nBird() : gravity(10), flap_speed(250), anim_counter(0), texture_switcher(1), should_fly(false)
{
	bird_textures[0].loadFromFile("assets/birddown.png");
	bird_textures[1].loadFromFile("assets/birdup.png");

	bird_sprite.setTexture(bird_textures[0]);
	bird_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
}

void nBird::setShouldFly(bool should_fly)
{
	this->should_fly = should_fly;
}

void nBird::flapBirdAction(sf::Time& dt)
{
	falling_velocity_posY = -flap_speed * dt.asSeconds();
}

void nBird::resetPosition()
{
	bird_sprite.setPosition(100, 50);
	falling_velocity_posY = 0;
}

void nBird::updateFallingPosition(sf::Time& dt)
{
	if (bird_sprite.getGlobalBounds().top < 548 && should_fly) {
		if (anim_counter == 5) {
			bird_sprite.setTexture(bird_textures[texture_switcher]);
			if (texture_switcher) texture_switcher = 0;
			else texture_switcher = 1;
			anim_counter = 0;
		}
		anim_counter++;

		falling_velocity_posY += gravity * dt.asSeconds();
		bird_sprite.move(0, falling_velocity_posY);

		if (bird_sprite.getGlobalBounds().top < 0) {
			bird_sprite.setPosition(100, 0);
		}
	}
}

float nBird::getRightBound()
{
	return bird_sprite.getGlobalBounds().left + bird_sprite.getGlobalBounds().width;
}