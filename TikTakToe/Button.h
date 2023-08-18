#pragma once
#include <SFML/Graphics.hpp>
enum button_state { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{
private:
	short unsigned buttonState;
	short unsigned id;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color text_idle_color;
	sf::Color text_hover_color;
	sf::Color text_active_color;

	sf::Color idle_color; //idle - bezczynny
	sf::Color hover_color; //hover - wahaæ siê 
	sf::Color active_color; //active - aktywny

	sf::Color outline_idle_color; //idle - bezczynny
	sf::Color outline_hover_color; //hover - wahaæ siê 
	sf::Color outline_active_color; //active - aktywny

public:
	//constructor and destructor
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned character_size,
		sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
		sf::Color idle_color, sf::Color hover_color, sf::Color active_color,
		sf::Color outline_idle_color = sf::Color::Transparent, sf::Color outline_hover_color = sf::Color::Transparent, sf::Color outline_active_color = sf::Color::Transparent,
		short unsigned id = 0);
	virtual ~Button();

	//Accessors
	const bool isPressed() const;
	const std::string getText() const;
	const short unsigned& getId() const;


	//MODIFIERS
	void setText(const std::string text);
	void setId(const short unsigned id);
	void setPostion(const float posX, const float posY);

	//Functions
	void update(const sf::Vector2i& mousePos);
	void render(sf::RenderTarget& target);
};
