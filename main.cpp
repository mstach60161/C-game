#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include "Ball.h"
#include "Player.h"
#include "Game.h"




int main(){
	Game game(5);
	game.gameLoop();
	return 0;
}