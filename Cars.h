#ifndef MAZE_H
#define MAZE_H
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Cars {
public:
	Texture tex;
	Sprite sprite;
	float speed = 0.5;
	int x, y;
	Cars(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 280; y = 400 ;
		sprite.setPosition(x, y);
		sprite.setScale(0.15, 0.15);
		sprite.setOrigin(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f);
		srand(time(0));	
	}
	
	virtual void move(std::string s) {}					// Virtual Functions Are Used here 
	virtual bool collion_with_walls(sf::RectangleShape line[]) = 0; //Pure Virtual Functions use here because both the vhile clases has there own functionalities for this function; 


};

#endif // MAZE_H
