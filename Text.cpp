#include "Text.h"

Text::Text()
{
	EndGameWonText.setString("The cat is full !");
	EndGameSpaceText.setString("Press SPACE to feed another cat.");
	GoalText.setString("Feed the cat !");
}

bool Text::PerformSetup()
{
	if (!_font.loadFromFile("Assets/Arial.ttf"))
	{
		std::cout << "Could not load font file" << std::endl;
		return false;
	}
	SetUpText(&HungerText, sf::Vector2f(10, 10));
	SetUpText(&TimeText, sf::Vector2f(10, 60));
	SetUpText(&GoalText, sf::Vector2f(10, 110));
	SetUpText(&EndGameWonText, sf::Vector2f(10, 10));
	SetUpText(&EndGameTimeText, sf::Vector2f(10, 60));
	SetUpText(&EndGameSpaceText, sf::Vector2f(10, 110));
	return true;
}

void Text::SetUpText(sf::Text* text, sf::Vector2f position)
{
	text->setFont(_font);
	text->setCharacterSize(30);
	text->setFillColor(sf::Color::Black);
	text->setStyle(sf::Text::Bold);
	text->setPosition(position);
}

void Text::DrawInGameText(sf::RenderWindow* window, sf::Time time, int hunger)
{
	HungerText.setString("Hunger : " + std::to_string(hunger));
	TimeText.setString("Time: " + std::to_string((int)time.asSeconds()) + "s");
	window->draw(HungerText);
	window->draw(TimeText);
	window->draw(GoalText);
}

void Text::DrawEndGameText(sf::RenderWindow* window, sf::Time time)
{
	EndGameTimeText.setString("Time: " + std::to_string((int)time.asSeconds()) + "s");
	window->draw(EndGameWonText);
	window->draw(EndGameTimeText);
	window->draw(EndGameSpaceText);
}