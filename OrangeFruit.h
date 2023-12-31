#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Food.h"
using namespace sf;
class OrangeFood : public Food {
public:

	OrangeFood(std::string png_path) : Food(png_path)
	{}

	void Benefits(bool& Enemy_Disappear, bool& Speed_Booster, Score& sc)
	{
		sc.setScore(10);
		Speed_Booster = true;
	}
};
