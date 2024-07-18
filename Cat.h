#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#ifndef CAT_H
#define CAT_H

class Cat
{
private:
	sf::Texture _catTexture;
	sf::Sprite _catSprite;
	sf::SoundBuffer _meowSoundBuffer;
	sf::Sound _meowSound;

public:
	int Hunger;

	Cat(int);
	bool PerformSetup();
	bool CheckIfFed(sf::Vector2i);
	bool Feed(int);
	void Draw(sf::RenderWindow*);
};

#endif
