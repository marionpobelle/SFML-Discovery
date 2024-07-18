#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cat.h"
#include "Text.h"
#include "Cursor.h"

#ifndef GAME_H
#define GAME_H

class Game
{

private:
	bool _isGameOver;
	int _food;
	sf::Texture _backgroundTexture;
	sf::Sprite _background;
	sf::Time _time;
	Cat _cat;
	Text _text;
	Cursor _cursor;

	bool LoadBackground();

public:
	Game();
	bool PerformSetup();
	bool RunGame();
};

#endif