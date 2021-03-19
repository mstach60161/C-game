#include "Ball.h"

Ball::Ball(float _x, float _y)
{
	shape.setPosition(_x, _y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(BALL_COLOR);
	shape.setOrigin(this->ballRadius, this->ballRadius);
}

Ball::Ball(const Ball & ball)
{
	shape.setPosition(ball.shape.getPosition().x, ball.shape.getPosition().y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(BALL_COLOR);
	shape.setOrigin(this->ballRadius, this->ballRadius);
}

Ball& Ball::operator=(const Ball& other)
{
	this->destroyed = other.destroyed;
	this->shape = other.shape;

	return *this;
}
