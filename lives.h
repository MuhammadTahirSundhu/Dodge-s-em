#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf; 
class Lives {
private:

    static int count;

public:
    Texture lv;
    Sprite sprite;

    Lives()
    {
        count++;
        if (count == 1)
            s1(0, 45);
        else if (count == 2)
            s1(40, 45);
        else if (count == 3)
            s1(80, 45);
        else if (count == 4)
            s1(120, 45);
        else if (count == 5)
            s1(160, 45);

    }
    void s1(int x, int y)
    {
        lv.loadFromFile("img/life.png");
        sprite.setTexture(lv);
        sprite.setScale(0.18, 0.1);
        sprite.setPosition(x, y);
    }

    void setLives(int x)
    {
        count = x;
    }
    int getLives()
    {
        return count;
    }

    static int getCount()
    {
        return count;
    }

    static void setCount(int c)
    {
        count = c;
    }

    ~Lives()
    {
        count--;
    }
};
int Lives::count = 0;
