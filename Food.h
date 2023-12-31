#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Score.h"
#include "Lives.h"
using namespace sf;
class Food {
public:
	int count;
	Texture tex;
	Sprite sprite;
	Food(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		sprite.setScale(0.8, 0.8);
		sprite.setOrigin(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f);
		count = 0;
	}

	bool Collion_with_wall(sf::RectangleShape line[])
	{
		for (int i = 0; i < 32; i++)
		{
			if (line[i].getGlobalBounds().intersects(this->sprite.getGlobalBounds()))
				return true;
		}
		return false;
			

	}


	virtual void Benefits(bool& Enemy_Disappear, bool& Speed_Booster, Score& scr) = 0;




};
