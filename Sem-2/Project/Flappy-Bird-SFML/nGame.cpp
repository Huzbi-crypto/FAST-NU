#include <sstream>
#include "nGame.h"
#include "nGlobals.h"

nGame::nGame(sf::RenderWindow& game_window) : game_window(game_window), is_enter_pressed(false), is_game_paused(true), pipe_spawn_time(70), pipe_counter(71), score(0), is_monitoring_start(false)
{
	game_window.setFramerateLimit(60);
	// creating sprite for the background
	bg_texture.loadFromFile("assets/bg.png");
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
	bg_sprite.setPosition(0.f, -280.f);

	// creating sprite for the ground
	ground_texture.loadFromFile("assets/ground.png");
	ground_sprite1.setTexture(ground_texture);
	ground_sprite2.setTexture(ground_texture);
	ground_sprite1.setScale(SCALE_FACTOR, SCALE_FACTOR);
	ground_sprite2.setScale(SCALE_FACTOR, SCALE_FACTOR);
	ground_sprite1.setPosition(0.f, ground_posY);
	ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().width, ground_posY);

	font.loadFromFile("assets/flappybird.ttf");
	restart_text.setFont(font);
	restart_text.setCharacterSize(40);
	restart_text.setFillColor(sf::Color::Black);
	restart_text.setPosition(155, 650);
	restart_text.setString("Restart Game!!");

	score_text.setFont(font);
	score_text.setCharacterSize(24);
	score_text.setFillColor(sf::Color::Black);
	score_text.setPosition(15, 15);
	score_text.setString("Score: 0");

	nPipe::loadPipeTextures();
}

void nGame::startGameLoop()
{
	// create a game loop that will open the window
	while (game_window.isOpen())
	{
		sf::Time dt = clock.restart();
		// create an event which will check every event in each loop to check whether the window has been closed
		sf::Event current_event;
		// the loop which will check
		while (game_window.pollEvent(current_event)) {
			if (current_event.type == sf::Event::Closed) {
				game_window.close();
		}
			if (current_event.type == sf::Event::KeyPressed && is_game_paused) {
				if (current_event.key.code == sf::Keyboard::Enter && !is_enter_pressed) {
					is_enter_pressed = true;
					flappy_bird.setShouldFly(true);
				}
				if (current_event.key.code == sf::Keyboard::Space && is_enter_pressed) {
					flappy_bird.flapBirdAction(dt);
				}
			}
			if (current_event.type == sf::Event::MouseButtonPressed && current_event.mouseButton.button == sf::Mouse::Left && !is_game_paused) {
				if (restart_text.getGlobalBounds().contains(current_event.mouseButton.x, current_event.mouseButton.y)) {
					restartGame();
				}
			}
		}

		game_window.clear(sf::Color::Black); // clear the screen with any previous memory, etc.

		doProcessing(dt);
		draw_texture();
		
		game_window.display(); // use the display method to display the window of the game
	}
}

void nGame::doProcessing(sf::Time& dt)
{
	if (is_enter_pressed) {
		moveGround(dt);

		if (pipe_counter > pipe_spawn_time) {
			pipes.push_back(nPipe(dist(rd)));
			pipe_counter = 0;
		}
		pipe_counter++;

		for (int i = 0; i < pipes.size(); i++) {
			pipes[i].updatePipesMovement(dt);

			if (pipes[i].getRightBound() < 0) {
				pipes.erase(pipes.begin() + i);
			}
		}

		checkCollisions();
		checkScore();
	}
	flappy_bird.updateFallingPosition(dt);
}

void nGame::checkCollisions()
{
	if (pipes.size() > 0) {
		if (pipes[0].pipe_face_down_sprite.getGlobalBounds().intersects(flappy_bird.bird_sprite.getGlobalBounds()) ||
			pipes[0].pipe_face_up_sprite.getGlobalBounds().intersects(flappy_bird.bird_sprite.getGlobalBounds()) ||
			flappy_bird.bird_sprite.getGlobalBounds().top >= 540) {
			is_enter_pressed = false;
			is_game_paused = false;
		}
	}
}

void nGame::checkScore()
{
	if (!is_monitoring_start) {
		if (flappy_bird.bird_sprite.getGlobalBounds().left > pipes[0].pipe_face_down_sprite.getGlobalBounds().left &&
			flappy_bird.getRightBound() < pipes[0].getRightBound())
		 {
			is_monitoring_start = true;
		}
	}
	else
	{
		if (flappy_bird.bird_sprite.getGlobalBounds().left > pipes[0].getRightBound())
		{
			score++;
			score_text.setString("Score: " + toString(score));
			is_monitoring_start = false;
		}
	}
}

std::string nGame::toString(int score)
{
	std::stringstream int_to_str;
	int_to_str << score;
	return int_to_str.str();
}

void nGame::restartGame()
{
	flappy_bird.resetPosition();
	flappy_bird.setShouldFly(false);
	is_game_paused = true;
	is_enter_pressed = false;
	pipe_counter = 71;
	pipes.clear();
	score = 0;
	score_text.setString("Score: 0");
}

void nGame::draw_texture() {
	game_window.draw(bg_sprite);
	
	for (nPipe& pipe : pipes) {
		game_window.draw(pipe.pipe_face_down_sprite);
		game_window.draw(pipe.pipe_face_up_sprite);
	}
	
	game_window.draw(ground_sprite1);
	game_window.draw(ground_sprite2);

	game_window.draw(flappy_bird.bird_sprite);

	game_window.draw(score_text);

	if (!is_game_paused) {
		game_window.draw(restart_text);
	}
}

void nGame::moveGround(sf::Time& dt)
{
	// set the movement speed for the ground sprites
	ground_sprite1.move(-movement_speed * dt.asSeconds(), 0.f);
	ground_sprite2.move(-movement_speed * dt.asSeconds(), 0.f);

	// making conditions so that when one ground sprite goes out of screen it returns to the other ground sprite's location
	if (ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width < 0) {
		ground_sprite1.setPosition(ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width, ground_posY);
	}
	if (ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width < 0) {
		ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width, ground_posY);
	}
}