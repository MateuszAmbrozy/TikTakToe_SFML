#include "TicTacToe.h"

//TILEEE
	//constructor and destructor
Tile::Tile(int size, sf::Vector2f position)
{
	this->tile.setPosition(position);
	this->tile.setSize(sf::Vector2f(size, size));
	this->tile.setFillColor(sf::Color::White);
	this->tile.setOutlineColor(sf::Color::Black);
	this->tile.setOutlineThickness(1.f);

	//ICON TOUR SPRITE
	if (!this->textureO.loadFromFile("O.png"))
		std::cout << "ERROR\n";

	if (!this->textureX.loadFromFile("X.png"))
		std::cout << "ERROR\n";

	//KRZY¯YK

	this->X.setTexture(textureX);
	this->X.setScale(
		size / X.getLocalBounds().width,
		size / X.getLocalBounds().height
	);

	//KÓ£KO

	this->O.setTexture(textureO);
	this->O.setScale(
		size / O.getLocalBounds().width,
		size / O.getLocalBounds().width
	);
	this->O.setPosition(tile.getPosition());
	this->X.setPosition(tile.getPosition());
	this->state = 0;
}

Tile::~Tile()
{
}
//ACCESSORS
const int Tile::getState() const
{
	return this->state;
}
const bool Tile::getContains(sf::Vector2i mousePos) const
{
	if (tile.getGlobalBounds().contains(mousePos.x, mousePos.y))
		return true;
	else
		return false;
}
//MODIFIERS
void Tile::setState(int state)
{
	if (state == 0 || state == 1 || state == 2)
		this->state = state;
	else
		std::cout << "incorrect state\n";
}
//FUNCTIONS
void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->tile);
	if (this->state == 1)
		target.draw(this->X);
	else if (this->state == 2)
		target.draw(this->O);
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////TICTACTOE///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//CONSTRUCTOR AND DESTUCTOR
TicTacToe::TicTacToe(const int boardSize, const int dimension, const int numToWin)
{
	//button
	this->restartButton = new Button(
		570, 20,
		150, 50, 
		&this->font, "RESTART", 35,
		sf::Color(200, 200, 200, 100), sf::Color(250, 250, 250, 150), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
		
	this->boardSize = boardSize;
	this->remained = boardSize * boardSize;
	this->round = 1;
	this->tourNum = 3;
	this->numToWin = numToWin;
	this->computerDiagonalWin = false;
	this->playerDiagonalWin = false;





	//LOADING BOARD
	for (int i = 0; i < boardSize; i++)
	{
		std::vector<Tile*> dodawany_rzad;
		for (int j = 0; j < boardSize; j++)
		{
			dodawany_rzad.push_back(new Tile(dimension, sf::Vector2f(i * dimension, j * dimension)));
		}
		board.push_back(dodawany_rzad);
	}

	//END GAME
	this->background.setSize(sf::Vector2f(dimension * boardSize, dimension * boardSize));
	this->background.setFillColor(sf::Color(50, 50, 50, 150));
	if (!this->font.loadFromFile("Arialn.ttf"))
		std::cout << "ERROR::TICTACTOE::CONSTRUCTOR::Coult not loada the font\n";
	this->text.setFont(this->font);
	this->text.setString("test");
	this->text.setCharacterSize(50);
	this->text.setPosition(30.f, 50.f);
	this->text.setFillColor(sf::Color::Cyan);


}

TicTacToe::~TicTacToe()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			delete this->board[i][j];
			this->board[i][j] = nullptr;
			//this->board[i].clear();
		}
		//this->board.clear();
	}
}
//FUNCTINS

bool TicTacToe::checkWin(int player) //player - 1-X, 2-0
{

	//kolumny
	for (int i = 0; i < this->boardSize; i++) {
		int count = 0;
		for (int j = 0; j < boardSize; j++) {
			if (board[i][j]->getState() == player) {
				count++;
				if (count == this->numToWin)
				{
					return true;
				}
			}
			else {
				count = 0;
			}

		}
	}
	//rzedy
	for (int i = 0; i < this->boardSize; i++) {
		int count = 0;
		for (int j = 0; j < boardSize; j++) {
			if (board[j][i]->getState() == player) {
				count++;
				if (count == this->numToWin)
				{
					return true;
				}
			}
			else {
				count = 0;
			}

		}
	}
	//przek¹tna g³ówna
	int count = 0;
	for (int i = 0; i < this->boardSize; i++)
	{

		if (board[i][i]->getState() == player)
		{
			count++;
			if (count == this->numToWin)
			{
				return true;
			}
		}
		else
		{
			count = 0;
		}
	}
	//druga przek¹tna
	count = 0;
	int row = this->boardSize;
	for (int i = 0; i < this->boardSize; i++)
	{
		row--;

		if (board[row][i]->getState() == player)
		{
			count++;
			if (count == this->numToWin)
			{
				return true;
			}
		}
		else
		{
			count = 0;
		}
	}
	return false;

}
bool TicTacToe::checkDiagonal(sf::Vector2i lastPosition, int player)
{
	int i = 1;
	int count1 = 1;
	int count2 = 1;

	bool checking1 = true, checking2 = true, checking3 = true, checking4 = true;
	while (i!=numToWin)
	{
		if (lastPosition.x + i < boardSize && lastPosition.y - i >= 0
			&& board[lastPosition.x + i][lastPosition.y - i]->getState() == player)
		{
			if (checking1)
				count1++;
		}
		else
			checking1 = false;

		if (lastPosition.x - i >= 0 && lastPosition.y + i < boardSize
			&& board[lastPosition.x - i][lastPosition.y + i]->getState() == player)
		{
			if (checking2)
				count1++;
		}
		else
			checking2 = false;

		if (count1>= numToWin)
			return true;
		i++;
	}
	i = 1;
	//2nd way diagonal
	while (i != this->numToWin)
	{
		if (lastPosition.x + i < boardSize && lastPosition.y + i < boardSize
			&& board[lastPosition.x + i][lastPosition.y + i]->getState() == player)
		{
			if (checking3)
				count2++;
		}
		else
			checking3 = false;

		if (lastPosition.x - i >= 0 && lastPosition.y - i >= 0
			&& board[lastPosition.x - i][lastPosition.y - i]->getState() == player)
		{
			if (checking4)
				count2++;
		}
		else
			checking4 = false;

		if (count2 >= numToWin)
			return true;
		i++;
	}
		return false;
		
	
}
bool TicTacToe::isTie()
{
	return remained == 0;
}


sf::Vector2i TicTacToe::minimax()
{

	int score = std::numeric_limits<int>::max();
	sf::Vector2i move;
	int level = 0;

	for (unsigned i = 0; i < boardSize; i++)
	{
		for (unsigned j = 0; j < boardSize; j++)
		{
			if (board[i][j]->getState() == 0)
			{
				board[i][j]->setState(2);
				remained--;

				int temp = maxSearch(level, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), i, j);
				std::cout << level << std::endl;
				if (temp < score)
				{
					score = temp;
					move.x = i;
					move.y = j;
				}

				board[i][j]->setState(0);
				remained++;
			}
		}
	}

	return move;
}

int TicTacToe::maxSearch( int level, int alpha, int beta, int i, int j)
{
	if (checkWin(1)) { return 10; }
	else if (checkDiagonal(sf::Vector2i(i, j), 1)) { return 10; }
	else if (checkDiagonal(sf::Vector2i(i, j), 2)) { return -10; }
	else if (checkWin(2)) { return -10; }
	else if (isTie()) { return 0; }

	int score = std::numeric_limits<int>::min();

	for (unsigned i = 0; i < boardSize; i++)
	{
		for (unsigned j = 0; j < boardSize; j++)
		{


			if (board[i][j]->getState() == 0)
			{
				board[i][j]->setState(1);

				remained--;

				if (level < this->tourNum)
				{
					score = std::max(score, minSearch(level + 1, alpha, beta, i, j) - level);
				}
				alpha = std::max(alpha, score);

				board[i][j]->setState(0);
				remained++;


			if (beta <= alpha) return alpha;

			}

		}
	}

	return score;
}

int TicTacToe::minSearch(int level, int alpha, int beta, int i, int j)
{
	if (checkWin(1)) { return 10; }
	else if (checkDiagonal(sf::Vector2i(i, j), 1)) { return 10; }
	else if (checkDiagonal(sf::Vector2i(i, j), 2)) { return -10; }
	else if (checkWin(2)) { return -10; }
	else if (isTie()) { return 0; }

	int score = std::numeric_limits<int>::max();


	for (unsigned i = 0; i < boardSize; i++)
	{
		for (unsigned j = 0; j < boardSize; j++)
		{


			if (board[i][j]->getState() == 0)
			{
				board[i][j]->setState(2);
				remained--;
				if (level < this->tourNum)
				{
					score = std::min(score, maxSearch(level + 1, alpha, beta, i, j) + level);
				}
				beta = std::min(beta, score);

				board[i][j]->setState(0);
				remained++;


				if (beta <= alpha) return beta;

			}

		}
	}

	return score;
}

void TicTacToe::update(sf::Vector2i mousePos)
{
	//BUTTON
	this->restartButton->update(mousePos);

	if (this->restartButton->isPressed())
	{
		
		round = 1;
		this->tourNum = 3;
		this->remained = this->boardSize * this->boardSize;
		this->computerDiagonalWin = false;
		this->playerDiagonalWin = false;

		for (int i = 0; i < this->boardSize; i++)
			for (int j = 0; j < this->boardSize; j++)
			{
				this->board[i][j]->setState(0);
			}
		
	}

	if (round == 1 && !this->checkWin(2) && !this->isTie() && !computerDiagonalWin)
	{
		for (int i = 0; i < this->board.size(); i++)
			for (int j = 0; j < this->board[i].size(); j++)
			{
				if (board[i][j]->getContains(mousePos)
					&& sf::Mouse::isButtonPressed(sf::Mouse::Left)
					&& this->board[i][j]->getState() == 0)
				{
					this->board[i][j]->setState(1);
					std::cout << "PLayer move: " << i << " " << j << std::endl;
					this->round = 0;
					remained--;
					if (tourNum < 9)
						tourNum++;
					if (this->checkDiagonal(sf::Vector2i(i, j), 1))
						this->playerDiagonalWin = true;
				}
			}
	}
	else if (round == 0 && !this->checkWin(1) && !this->isTie() && !this->playerDiagonalWin)
	{
		std::cout << "THINKING...\n";
		sf::Vector2i aimove = minimax();
		board[aimove.x][aimove.y]->setState(2);
		std::cout << aimove.x << " " << aimove.y << std::endl;
		remained--;
		if (tourNum < 9)
			tourNum++;
		this->round = 1;
		if (this->checkDiagonal(sf::Vector2i(aimove.x, aimove.y), 2))
			this->computerDiagonalWin = true;
	}

	else if (this->checkWin(1) || this->checkWin(2) || this->isTie() || this->playerDiagonalWin || this->computerDiagonalWin)
	{
		if (this->checkWin(1) || this->playerDiagonalWin)
			this->text.setString("Wygrales, gratulacje\n\n");
		if (this->checkWin(2) || this->computerDiagonalWin)
			this->text.setString("Sztuczna inteligencja wygrala\n\n");
		if (this->isTie())
			this->text.setString("REMIS!\n\n");
	}
}

void TicTacToe::render(sf::RenderTarget& target)
{
	for (auto& x : this->board)
		for (auto& y : x)
			y->render(target);
	if (this->checkWin(1) || this->checkWin(2) || this->isTie() || this->playerDiagonalWin || this->computerDiagonalWin)
	{
		target.draw(this->background);
		target.draw(this->text);
	}
	this->restartButton->render(target);
}


