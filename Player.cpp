#include "Player.h"

Player::Player(float _x, float _y)
{
	shape.setPosition(_x, _y);
	shape.setSize({ this->playerWidth, this->playerHeight });
	shape.setFillColor(PLAYER_COLOR);
	shape.setOrigin(playerWidth / 2.f, playerHeight / 2.f);
	
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) and this->left() > 0) {
		shape.move(-speed, 0);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) and this->right() < 800) {
		shape.move(speed, 0);
	}
}
