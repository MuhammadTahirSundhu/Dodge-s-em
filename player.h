#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include<string.h>
#include "Enemy.h"
#include "Score.h"
#include "Lives.h"
#include "Food.h"
#include "CommenFruit.h"
using namespace sf;
class Player:public Cars {
public:

	Player(std::string png_path):Cars(png_path)
	{
		this->sprite.setPosition(640, 110);
		this->sprite.setScale(0.1, 0.1);
	}
	void fire()
	{

	}
	void move(std::string s) {

		

			float delta_x = 0, delta_y = 0;
			if (s == "l")
			{
					if (this->sprite.getPosition().x < 0)
					this->sprite.setPosition(1380,this->sprite.getPosition().y);
				delta_x = -1;
				this->sprite.setRotation(-90);
			}
			// move the player left
			else if (s == "r")
			{
				if (this->sprite.getPosition().x > 1380)
					this->sprite.setPosition(0, this->sprite.getPosition().y);
				delta_x = 1;
				this->sprite.setRotation(90);
			}
			//; move the player right
			if (s == "u")
			{
				    if (this->sprite.getPosition().y < 100)
					this->sprite.setPosition(this->sprite.getPosition().x, 915);
					delta_y = -1;
					this->sprite.setRotation(0);
			}
			else if (s == "d")
			{
				    if (this->sprite.getPosition().y > 915)
					this->sprite.setPosition(this->sprite.getPosition().x,90);
					delta_y = 1;
					this->sprite.setRotation(-180);
			}

			delta_x *= speed;
			delta_y *= speed;

			sprite.move(delta_x, delta_y);
		
	}
	bool collion_with_opponent(Enemy* ptr,Sound& s)
	{
		if (this->sprite.getGlobalBounds().intersects(ptr->sprite.getGlobalBounds()))
		{
			s.play();
			this->sprite.setPosition(640, 100);
			Lives::setCount(Lives::getCount()-1);
			return true;
		}  
	}

	bool collion_with_walls(sf::RectangleShape line[])
	{
		sf::FloatRect playerBounds = this->sprite.getGlobalBounds();
		sf::Vector2f playerPosition = this->sprite.getPosition();

		for (int i = 0; i < 32; i++)
		{
			sf::FloatRect wallBounds = line[i].getGlobalBounds();
			if (i == 4 || i == 6)
				wallBounds.width -= 1;
			// Check if the player's bounds intersect with the wall's bounds
			if (playerBounds.intersects(wallBounds))
			{
				line[i].setOutlineColor(Color::Green);
				// Calculate the MTV (Minimum Translation Vector) using SAT
				sf::Vector2f overlap = calculateMTV(playerBounds, wallBounds);
				this->sprite.move(overlap);
				return true;
			}
			//line[i].setOutlineColor(Color::Red);
		}

		return false; // No collision
	}

	sf::Vector2f calculateMTV(const sf::FloatRect& rectA, const sf::FloatRect& rectB)
	{
		// Calculate the minimum translation vector (MTV) needed to separate the two rectangles
		sf::Vector2f overlap;

		float deltaX = (rectA.left + rectA.width / 2) - (rectB.left + rectB.width / 2);
		float deltaY = (rectA.top + rectA.height / 2) - (rectB.top + rectB.height / 2);

		float intersectX = rectA.width / 2 + rectB.width / 2 - std::abs(deltaX);
		float intersectY = rectA.height / 2 + rectB.height / 2 - std::abs(deltaY);

		// Use the smaller of the two intersects as the MTV
		if (intersectX < intersectY)
		{
			overlap.x = (deltaX > 0) ? intersectX : -intersectX;
		}
		else
		{
			overlap.y = (deltaY > 0) ? intersectY : -intersectY;
		}

		return overlap;
	}

	void Collion_with_Food(Food* ptr, bool& enemy_disappear, bool& Speed_Booster, Score& sc, float& timer,Sound& s)
	{
		if (ptr->sprite.getGlobalBounds().intersects(this->sprite.getGlobalBounds()))
		{
			s.play();
			ptr->Benefits(enemy_disappear, Speed_Booster, sc);
			ptr->sprite.setPosition(-10, -10);
			timer = 0;
		}
	}

	void Collion_with_cf(CommenFood* cf,Score& sc,Sound& s)
	{
			for (int i = 0; i < 115; i++)
			if (cf[i].sprite.getGlobalBounds().intersects(this->sprite.getGlobalBounds()))
			{
				s.play();
				cf[i].sprite.setPosition(-50, -50);
				sc.setScore(1);
				CommenFood::setcount(CommenFood::getcount()-1);
			}
	}


};
