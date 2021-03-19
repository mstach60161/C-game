#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Ball.h"
#include "Player.h"

class Game
{
public:
	Game(int lives) {
		this->lives = lives;
	}

	int gameStart(sf::Color color, sf::RenderWindow& window);

	void gameLoop();

	int gameOver(std::string text, sf::RenderWindow& window);

	void printText(std::string text, sf::Vector2f position, sf::Color color, sf::RenderWindow& window);

private:
	int lives;

	Ball spawnBall();

	template<class T1, class T2> bool isIntersection(T1& obj1, T2& obj2);
};

template<class T1, class T2>
inline bool Game::isIntersection(T1& obj1, T2& obj2)
{
	if (obj1.left() > obj2.right() or obj2.left() > obj1.right())
		return false;

	if (obj1.top() < obj2.bottom() or obj2.top() < obj1.top())
		return false;

	return true;
}
