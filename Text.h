#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef TEXT_H
#define TEXT_H

class Text
{
private:
	sf::Font _font;

	void SetUpText(sf::Text *, sf::Vector2f);
public:
	sf::Text HungerText;
	sf::Text TimeText;
	sf::Text GoalText;
	sf::Text EndGameWonText;
	sf::Text EndGameTimeText;
	sf::Text EndGameSpaceText;

	Text();
	bool PerformSetup();
	void DrawInGameText(sf::RenderWindow*, sf::Time, int);
	void DrawEndGameText(sf::RenderWindow*, sf::Time);
};

#endif
