#include "Game.h"

//PRIVATE FUNCTION
void Game::initWindw()
{
	this->videoMode = sf::VideoMode(800, 650);
	this->window = new sf::RenderWindow(this->videoMode, "TIC TAC TOE"/*, sf::Style::Close | sf::Style::Titlebar*/);
	this->window->setFramerateLimit(60);

}

//CONSTRUCTOR AND DESTRUCTOR
Game::Game()
{

	std::cout << "Podaj wielkosc planszy: ";
	std::getline(std::cin, size);
	std::cout << std::endl << "Podaj ile w do wygranej: ";
	std::getline(std::cin, numToWin);

	this->initWindw();
	this->ticTacToe = new TicTacToe(std::stoi(size), (this->window->getSize().x - 150) / std::stoi(size), std::stoi(numToWin));
}

Game::~Game()
{
	delete this->ticTacToe;
	delete this->window;
}

//FUNCTIONS
void Game::run()
{
	while (this->window->isOpen())
	{
		this->pollEvents();
		this->update();
		this->render();
	}
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->ticTacToe->update(sf::Mouse::getPosition(*this->window));
}

void Game::render()
{
	this->window->clear();
	this->ticTacToe->render(*this->window);

	this->window->display();
}
