#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Color PLAYER_COLOR = sf::Color::Green;
const float PLAYER_WIDTH = 80;
const float PLAYER_HEIGHT = 30;
const float PLAYER_SPEED = 8;

class Player : public sf::Drawable
{
public:
	Player(float _x, float _y);
	~Player() = default;

	void update();

	float left() {
		return this->shape.getPosition().x - shape.getSize().x / 2.f;
	}

	float right() {
		return this->shape.getPosition().x + shape.getSize().x / 2.f;
	}

	float top() {
		return this->shape.getPosition().y + shape.getSize().y / 2.f;
	}

	float bottom() {
		return this->shape.getPosition().y - shape.getSize().y / 2.f;
	}


private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const
	{
		target.draw(this->shape, state);
	}

	sf::RectangleShape shape;
	const float playerWidth = PLAYER_WIDTH;
	const float playerHeight = PLAYER_HEIGHT; 
	const float speed = PLAYER_SPEED;
};

