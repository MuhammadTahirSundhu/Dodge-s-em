#pragma once

#include<iostream>
using namespace std;
#include<string>
#include <SFML/Graphics.hpp>
using namespace sf;
class Score {
private:

    int score;
    int min;
    int sec;

public:
    Font font;
    Text sc;
    Text time;


    Score()
    {
        score = 0;
        min = 0;
        sec = 0;
        font.loadFromFile("img/font1/1.otf");
        sc.setFont(font);
        sc.setCharacterSize(50);
        sc.setFillColor(Color::Magenta);
        sc.setPosition(1300, 40);
        sc.setString(to_string(score));

        time.setFont(font);
        time.setCharacterSize(34);
        time.setFillColor(Color::Blue);
        time.setPosition(650, 20);
        time.setString("0" + to_string(min) + ":" + to_string(sec));

    }
    void setTime(int timer)
    {
        sec += timer;
        if (sec > 60)
        {
            sec = 0;
            min++;
        }
        time.setString("0" + to_string(min) + " : " + to_string(sec));

    }
    void setScore(int x)
    {
        score += x;
        sc.setString(to_string(score));
    }

    int getScore()
    {
        return score;
    }
};