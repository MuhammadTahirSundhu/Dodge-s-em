#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Cars.h"
#include "player.h"
#include "wall.h"
#include "time.h"
#include "level.h"
#include "cmath"
using namespace std;
using namespace sf;
class Enemy : public  Cars {
public:
	
	int arr[4];
	Enemy(std::string png_path):Cars(png_path)
	{
	
		srand(time(0));
		arr[0] = 100;
		arr[1] = 500;
		arr[2] = 900;
		arr[3] = 1200;
	}
	void fire()
	{

	}

	float Distance(int x, int y)
	{
		return sqrt(std::pow(this->sprite.getPosition().x - x, 2) + pow(this->sprite.getPosition().y - y, 2));
	}

	void move(int x, int y,int road_choice1,sf::RectangleShape line[],Level* l1) {
		float delta_x = 0, delta_y = 0;

		
			if (l1->level > 3)
			{
				if (Distance(x, y) <= 250 )
				{
					for(int i=0;i<32;i++)
					{
						if (this->sprite.getPosition().x > x && !this->collion_with_walls(line))
							delta_x = -1;
						else if (this->sprite.getPosition().x <= x && !this->collion_with_walls(line))
							delta_x = 1;
						if(l1->level == 4)
						{
							if (this->sprite.getPosition().y > y && !this->collion_with_walls(line))
								delta_y = -1;
							else
							{
								delta_y = 1;
							}
						}
					}
				}
			}

			int road_choice = (road_choice1 + 1) % 4;
			if (road_choice == 0) {
				
				delta_x = -1;
				this->sprite.setRotation(90);
			}
			else if (road_choice == 1 ) {
				delta_y = 1;
				this->sprite.setRotation(0);
			}
			else if (road_choice == 2) {
				
				delta_x = 1;
				this->sprite.setRotation(90);
			}
			else if (road_choice == 3) {
				
				delta_y = -1;
				this->sprite.setRotation(180);
			}
		//}
		if (this->sprite.getPosition().x < 0)
			this->sprite.setPosition(1380, this->sprite.getPosition().y);
		else if(this->sprite.getPosition().y < 100)
			this->sprite.setPosition(this->sprite.getPosition().x, 915);
		else if (this->sprite.getPosition().x > 1380)
			this->sprite.setPosition(0, this->sprite.getPosition().y);
		else if (this->sprite.getPosition().y > 915)
			this->sprite.setPosition(this->sprite.getPosition().x, 100);

		delta_x *= 0.3*speed;
		delta_y *= 0.3*speed;

		sprite.move(delta_x, delta_y);
	}

	bool collion_with_walls(sf::RectangleShape line[])
	{
		sf::FloatRect enemyBounds = this->sprite.getGlobalBounds();
		sf::Vector2f enemyPosition = this->sprite.getPosition();

		for (int i = 0; i < 32; i++)
		{
			sf::FloatRect wallBounds = line[i].getGlobalBounds();
			if (enemyBounds.intersects(wallBounds))
			{
				sf::Vector2f overlap = calculateMTV(enemyBounds, wallBounds);
				this->sprite.move(overlap);
				return true;
			}
		}
		return false; // No collision
	}

	sf::Vector2f calculateMTV(const sf::FloatRect& rectA, const sf::FloatRect& rectB)
	{
		sf::Vector2f overlap;
		float deltaX = (rectA.left + rectA.width / 2) - (rectB.left + rectB.width / 2);
		float deltaY = (rectA.top + rectA.height / 2) - (rectB.top + rectB.height / 2);

		float intersectX = rectA.width / 2 + rectB.width / 2 - std::abs(deltaX);
		float intersectY = rectA.height / 2 + rectB.height / 2 - std::abs(deltaY);
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

};
