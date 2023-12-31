#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include<string.h>
#include "Food.h"
using namespace sf;
class CommenFood : public Food {
public:
    static int cf_count;

	CommenFood(std::string png_path="img/cfood.png") : Food(png_path)
	{
        cf_count++;
	}

	void DrawCF(CommenFood* CF)
	{
        int cc = 165;

        for (int i = 1; i < 114; i++)
        {
            if (i < 21)
            {
                CF[i].sprite.setPosition(95, cc);
                CF[++i].sprite.setPosition(1300, cc);
                cc += 74;
                if (i == 20)
                    cc = 165;
            }
            else if (i < 53)
            {
                CF[i].sprite.setPosition(cc, 165);
                CF[++i].sprite.setPosition(cc, 838);
                cc += 70;
                if (i == 52)
                    cc = 268;
            }
            else if (i < 67)
            {
                CF[i].sprite.setPosition(247, cc);
                CF[++i].sprite.setPosition(1135, cc);
                cc += 76;
                if (i == 66)
                    cc = 300;
            }
            else if (i < 91)
            {
                CF[i].sprite.setPosition(cc, 268);
                CF[++i].sprite.setPosition(cc, 728);
                cc += 70;
                if (i == 90)
                    cc = 371;
            }
            else if (i < 101)
            {
                CF[i].sprite.setPosition(395, cc);
                CF[++i].sprite.setPosition(970, cc);
                cc += 66;
                if (i == 100)
                    cc = 473;
            }
            else if (i < 114)
            {
                CF[i].sprite.setPosition(cc, 371);
                CF[++i].sprite.setPosition(cc, 635);
                cc += 70;

            }

        }
	}

    static void setcount(int a)
    {
        cf_count = a;
    }

    static int getcount()
    {
        return cf_count;
    }


	void Benefits(bool& Enemy_Disappear, bool& Speed_Booster, Score& sc)
	{
		sc.setScore(1);
	}

   
};

int CommenFood::cf_count = -1;
