#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Food.h"
using namespace sf;
class GreenFood : public Food {
public:

	GreenFood(std::string png_path) : Food(png_path)
	{}

	void Benefits(bool& Enemy_Disappear, bool& Speed_Booster, Score& sc)
	{
		sc.setScore(20);
		if (Lives::getCount() < 5)
			Lives::setCount(Lives::getCount() + 1);
	}
};
