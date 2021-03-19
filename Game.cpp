#include "Game.h"

int Game::gameStart(sf::Color color, sf::RenderWindow& window)
{
	sf::Font MyFont;
	MyFont.loadFromFile("C:\\arial.ttf");
	window.clear(color);
	sf::Event event;
	while (true) {
		window.clear(color);
		printText("Play - space", { 100, 200 }, sf::Color::Black, window);
		printText("Exit - e", { 100, 300 }, sf::Color::Black, window);
		window.pollEvent(event);

		if (event.type == sf::Event::Closed) {
			window.close();
			return 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			break;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
			window.close();
			return 0;
		}

		window.display();
	}
	return 1;
}

void Game::gameLoop()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 600), "Catch the balls");
	window.setFramerateLimit(60);
	sf::Event event;

	if (gameStart(sf::Color::Red, window) == 0) {
		window.close();
		exit(0);
	}
	Player newPlayer(400, 500);
	std::vector<Ball> balls;

	int score = 0;
	int lives = this->lives;
	int loopNumber = 0;

	while (window.isOpen()) {

		window.clear(sf::Color::Black);
		window.pollEvent(event);

		if (event.type == sf::Event::Closed) {
			window.close();
			break;
		}

		newPlayer.update();
		if (std::rand() % 100 < 40 and loopNumber % (60 - loopNumber / 180) == 0) {
			Ball newBall = spawnBall();
			balls.push_back(newBall);
		}


		for (Ball& ball : balls) {
			ball.update();

			if ((isIntersection(newPlayer, ball))) {
				std::cout << 1 << std::endl;
				score++;
				ball.destroy();
			}

			if (ball.top() > 600) {
				ball.destroy();
				lives--;
			}
		}

		auto iterator = remove_if(begin(balls), end(balls), [](Ball& ball) {return ball.isDestroyed(); });
		balls.erase(iterator, end(balls));



		for (Ball& ball : balls) {
			if (ball.isDestroyed() == false)
				window.draw(ball);

		}
		window.draw(newPlayer);

		std::string stringScore = "Score: " + std::to_string(score);
		printText(stringScore, { 0,0 }, sf::Color::Red, window);

		std::string stringLives = "Lives: " + std::to_string(lives);
		printText(stringLives, { 0,40 }, sf::Color::Red, window);



		window.display();

		loopNumber++;

		if (lives == 0) {
			balls.clear();

			if (gameOver("Game Over | Your score: " + std::to_string(score), window) == 0) {
				window.close();
				break;
			}

			loopNumber = 0;
			lives = 3;
			score = 0;
			srand(time(NULL));
		}
	}
}

int Game::gameOver(std::string text, sf::RenderWindow& window)
{
	sf::Font MyFont;
	MyFont.loadFromFile("C:\\arial.ttf");
	window.clear(sf::Color::Red);
	sf::Event event;
	while (true) {
		window.clear(sf::Color::Red);
		printText(text, { 100, 100 }, sf::Color::Black, window);
		printText("Play again - space", { 100, 200 }, sf::Color::Black, window);
		printText("Exit - e", { 100, 300 }, sf::Color::Black, window);
		window.pollEvent(event);

		if (event.type == sf::Event::Closed) {
			window.close();
			return 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			break;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
			window.close();
			return 0;
		}

		window.display();
	}
	return 1;
}

void Game::printText(std::string text, sf::Vector2f position, sf::Color color, sf::RenderWindow& window)
{
	sf::Font MyFont;
	MyFont.loadFromFile("C:\\arial.ttf");
	sf::Text textObject;
	textObject.setFont(MyFont);
	textObject.setString(text);
	textObject.setCharacterSize(48);
	textObject.setFillColor(color);
	textObject.setStyle(sf::Text::Bold);
	textObject.move(position);
	window.draw(textObject);
}

Ball Game::spawnBall()
{
	int x = std::rand() % 700 + 100;
	int y = std::rand() % 150 + 50;


	Ball newBall(x, y);
	return newBall;
}
