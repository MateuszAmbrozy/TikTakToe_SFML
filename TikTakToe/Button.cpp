#include "Button.h"
Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned character_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color idle_color, sf::Color hover_color, sf::Color active_color,
	sf::Color outline_idle_color, sf::Color outline_hover_color, sf::Color outline_active_color,
	short unsigned id)
{
	this->id = id;
	this->buttonState = BTN_IDLE;

	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setPosition(x, y);
	this->shape.setFillColor(idle_color);
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(outline_idle_color);

	this->font = font;

	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(text_idle_color);
	this->text.setCharacterSize(character_size);
	this->text.setPosition
	(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y
	);

	this->text_idle_color = text_idle_color;
	this->text_hover_color = text_hover_color;
	this->text_active_color = text_active_color;

	this->idle_color = idle_color;
	this->hover_color = hover_color;
	this->active_color = active_color;

	this->outline_idle_color = outline_idle_color;
	this->outline_hover_color = outline_hover_color;
	this->outline_active_color = outline_active_color;
	this->shape.setFillColor(this->idle_color);
}
Button::~Button()
{
}
//Accessors
const bool Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;


	return false;
}
const std::string Button::getText() const
{
	return this->text.getString();
}
const short unsigned& Button::getId() const
{
	return this->id;
}



//MODIFIERS
void Button::setText(const std::string text)
{
	this->text.setString(text);
}
void Button::setId(const short unsigned id)
{
	this->id = id;
}

void Button::setPostion(const float posX, const float posY)
{
	this->shape.setPosition(posX, posY);
	this->text.setPosition
	(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y
	);
}

//Functions
void Button::update(const sf::Vector2i& mousePos)
{
	/*Update the booleand for hover and pressed*/

	//Idle
	this->buttonState = BTN_IDLE;

	//Hover
	if (this->shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
	{
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//Pressed
			this->buttonState = BTN_ACTIVE;
		}
	}
	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idle_color);
		this->text.setFillColor(this->text_idle_color);

		this->shape.setOutlineColor(this->outline_idle_color);

		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hover_color);
		this->text.setFillColor(this->text_hover_color);

		this->shape.setOutlineColor(this->outline_hover_color);
		break;
	case BTN_ACTIVE:
		this->shape.setFillColor(this->active_color);
		this->text.setFillColor(this->text_active_color);

		this->shape.setOutlineColor(this->outline_active_color);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::Blue);
		this->shape.setOutlineColor(sf::Color::Green);
		break;
	}
}
void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}