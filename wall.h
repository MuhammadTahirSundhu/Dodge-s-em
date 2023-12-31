#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;

class wall {
public:
	Texture tex;
	Sprite sprite;
	wall()
	{

	}
	void setParameters(std::string png_path,int x,int y,float width,float height)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		sprite.setPosition(x, y);
		sprite.setScale(width, height);
		sprite.setOrigin(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f);
	}
};
