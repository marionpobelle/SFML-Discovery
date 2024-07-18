#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef CURSOR_H
#define CURSOR_H

class Cursor
{
private:
	sf::Texture _cursorTexture;
	sf::Sprite _cursorSprite;

public:
	Cursor();
	bool PerformSetup();
	void Draw(sf::RenderWindow*, sf::Vector2i mousePos);
};

#endif