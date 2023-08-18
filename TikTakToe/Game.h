#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "TicTacToe.h"
class Game
{
private:
	//VARIABLES
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	TicTacToe* ticTacToe;
	bool play;

	std::string size;
	std::string numToWin;
	//PRIVATE FUNCTIONS
	void initWindw();

public:
	//CONSTRUCTOR AND DESTRUCTOR
	Game();
	~Game();

	//FUNCTIONS
	void run();
	void pollEvents();
	void update();
	void render();

};

