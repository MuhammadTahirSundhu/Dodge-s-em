#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Food.h"
using namespace sf;
class whiteFood : public Food{
public:
	
	whiteFood(std::string png_path): Food(png_path)
	{}

	void Benefits(bool& Enemy_Disappear, bool& Speed_Booster, Score& sc)
	{
		Enemy_Disappear = true;
	}
};
