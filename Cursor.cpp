#include "Cursor.h"

Cursor::Cursor()
{
}

bool Cursor::PerformSetup()
{
	if (!_cursorTexture.loadFromFile("Assets/fish.png"))
	{
		std::cout << "Could not load fish image" << std::endl;
		return false;
	}		
	_cursorSprite.setTexture(_cursorTexture);
	_cursorSprite.scale(sf::Vector2f(0.2, 0.2));
	return true;
}

void Cursor::Draw(sf::RenderWindow* window, sf::Vector2i mousePos)
{
	_cursorSprite.setPosition(sf::Vector2f(mousePos.x, mousePos.y));
	window->draw(_cursorSprite);
}
