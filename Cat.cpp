#include "Cat.h"

Cat::Cat(int hunger)
{
	Hunger = hunger;
}

bool Cat::PerformSetup()
{
	srand(time(NULL));
	int randomIndex = rand() % 3 + 1;
	switch (randomIndex) {
	case 1:
		if (!_catTexture.loadFromFile("Assets/cat1.png"))
		{
			std::cout << "Could not load cat image" << std::endl;
			return false;
		}
		break;
	case 2:
		if (!_catTexture.loadFromFile("Assets/cat2.png"))
		{
			std::cout << "Could not load cat image" << std::endl;
			return false;
		}
		break;
	case 3:
		if (!_catTexture.loadFromFile("Assets/cat3.png"))
		{
			std::cout << "Could not load cat image" << std::endl;
			return false;
		}
		break;
	default:
		if (!_catTexture.loadFromFile("Assets/cat1.png"))
		{
			std::cout << "Could not load cat image" << std::endl;
			return false;
		}
	}
	_catSprite.setTexture(_catTexture);
	_catSprite.setPosition(sf::Vector2f(285, 395));
	_catSprite.scale(sf::Vector2f(0.2, 0.2));

	if (!_meowSoundBuffer.loadFromFile("Assets/MeowSFX.ogg"))
	{
		std::cout << "Could not load cat audio" << std::endl;
		return false;
	}
	_meowSound.setBuffer(_meowSoundBuffer);
	_meowSound.setVolume(25);
	return true;
}

void Cat::Draw(sf::RenderWindow * window)
{
	window->draw(_catSprite);
}

bool Cat::CheckIfFed(sf::Vector2i mousePos) {
	float spriteMinX = _catSprite.getGlobalBounds().left;
	float spriteMaxX = _catSprite.getGlobalBounds().width + spriteMinX;
	float spriteMinY = _catSprite.getGlobalBounds().top;
	float spriteMaxY = _catSprite.getGlobalBounds().height + spriteMinY;
	float mouseX = mousePos.x;
	float mouseY = mousePos.y;
	return mouseX >= spriteMinX && mouseX <= spriteMaxX && mouseY >= spriteMinY && mouseY <= spriteMaxY;
}

bool Cat::Feed(int food) {
	Hunger -= food;
	_meowSound.play();
	return Hunger <= 0;
}