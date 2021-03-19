#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Color BALL_COLOR = sf::Color::Blue;
const float BALL_RADIUS = 10;
const float BALL_SPEED = 3;

class Ball : public sf::Drawable
{
public:
	Ball(float _x, float _y);

	~Ball() = default;

	Ball(const Ball& ball);

	void draw(sf::RenderTarget& target, sf::RenderStates state) const
	{
		target.draw(this->shape, state);
	}

	void update()
	{
		shape.move(0, this->speed);
	}

	void destroy() {
		destroyed = true;
	}

	bool isDestroyed() {
		return destroyed;
	}

	float left() {
		return this->shape.getPosition().x - ballRadius;
	}

	float right() {
		return this->shape.getPosition().x + ballRadius;
	}

	float top() {
		return this->shape.getPosition().y + ballRadius;
	}

	float bottom() {
		return this->shape.getPosition().y - ballRadius;
	}
	Ball& operator=(const Ball& other);

private:
	sf::CircleShape shape;
	const float ballRadius = BALL_RADIUS;
	float speed = BALL_SPEED;
	bool destroyed = false;
};

