#pragma once
#include <iostream>
#include "Button.h"
#include <SFML/Graphics.hpp>

class Tile
{
private:
	sf::RectangleShape tile;
	int state; //0-empty, 1 - X, 2 - O
	sf::Texture textureO, textureX;
	sf::Sprite X;
	sf::Sprite O;


public:
	//constructor and destructor
	Tile(int size, sf::Vector2f position);
	~Tile();

	//ACCESSORS
	const int getState() const;
	const bool getContains(sf::Vector2i mousePos) const;
	//MODIFIERS
	void setState(int state);

	//FUNCTIONS
	void render(sf::RenderTarget& target);

};

class TicTacToe
{
private:
	int boardSize;
	unsigned remained;
	int numToWin;
	bool round; //0 - O, X-1 (x-player, 0-ai)
	int tourNum; //count whick tour it is
	bool computerDiagonalWin;
	bool playerDiagonalWin;
	Button* restartButton;


	std::vector<std::vector<Tile*>> board;
	//end game
	sf::RectangleShape background;
	sf::Text text;
	sf::Font font;

public:
	TicTacToe(const int boardSize, const int dimension, const int numToWin);
	~TicTacToe();

	//FUNCTIONS
	bool checkWin(int player);
	bool checkDiagonal(sf::Vector2i lastPosition, int player);
	bool isTie();

	//AI
	sf::Vector2i minimax();
	int maxSearch(int level, int alpha, int beta, int i, int j);
	int minSearch(int level, int alpha, int beta, int i, int j);

	void update(sf::Vector2i mousePos);
	void render(sf::RenderTarget& target);
};

