#include "Game.h"

Game::Game(): _cat(100), _text()
{
	_food = 10;
}

bool Game::LoadBackground()
{
	if (!_backgroundTexture.loadFromFile("Assets/background.png"))
	{
		std::cout << "Could not load background image" << std::endl;
		return false;
	}
	_background.setTexture(_backgroundTexture);
	//_background.scale(sf::Vector2f(1.6, 2.25));
	return true;
}

bool Game::PerformSetup()
{
	_isGameOver = false;
	_cat = Cat(100);
	_text = Text();
	_cursor = Cursor();
	return LoadBackground() && _cat.PerformSetup() && _text.PerformSetup() && _cursor.PerformSetup();
}

bool Game::RunGame()
{
	sf::RenderWindow window(sf::VideoMode(760, 600), "SFML-Discovery");
	sf::Clock clock;

	while (window.isOpen())
	{
		if (!_isGameOver) 
		{
			_time = clock.getElapsedTime();
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return false;
			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				if (!_isGameOver) 
				{
					if (_cat.CheckIfFed(sf::Mouse::getPosition(window))) {
						_isGameOver = _cat.Feed(_food);
						std::cout << "Clicked on cat" << std::endl;
					}
				}			
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (_isGameOver)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						return true;
					}
				}
			}

		}
		window.clear();
		window.draw(_background);
		if (_isGameOver)
		{
			_text.DrawEndGameText(&window, _time);
		}
		else
		{
			_cat.Draw(&window);
			_text.DrawInGameText(&window, _time, _cat.Hunger);
			_cursor.Draw(&window, sf::Mouse::getPosition(window));
		}		
		window.display();
	}
	return false;	
}