#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Level {
public:
	
	int level;

	Level()
	{
		level = 1;
	}
	void Levelup()
	{
		++level;
	}
	int getLevel()
	{
		return level;
	}


};
