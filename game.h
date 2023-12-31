#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;
#include "player.h"
#include "Enemy.h"
#include "wall.h"
#include "level.h"
#include "lives.h"
#include "Score.h"
#include "Food.h"
#include "whiteFruit.h"
#include "OrangeFruit.h"
#include "GreenFruit.h"
#include "RedFruit.h"
#include "CommenFruit.h"

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Box
{
public:
    RectangleShape shape;
    int direction; // Direction of movement for the box

    Box(float x, float y, float width, float height, int initialDirection)
        : direction(initialDirection)
    {
        shape.setSize(Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(Color::Red); // Adjust the color as needed
    }

    void move(float speed, float offsetY)
    {
        shape.move(speed * direction, offsetY);
    }
};


class Game
{
   
public:
    ofstream outfile;
    ifstream infile;
    Sprite background; //Game background sprite
    Texture bg_texture;
    Player* p; //player 
    Enemy* e1; //player 
    Enemy* e2; //player 
    bool enemy_disappear;
    bool speed_Booster;
    Level* level;
    Score sc;
    Lives l1[5];
    Food* F[4];
    bool f[4];
    bool food_gotit;
    bool Enemy_disappear;
    bool Speed_Booster;
    CommenFood* CF;
    int levelup;
    bool isPause = false;
    SoundBuffer bf1, bf2,bf3,bf4,bf5;
    Sound s1, s2,s3,s4,s5;
    // add other game attributes
    //std::vector<Box> smallBoxes; // Declare the vector here
   // int direction = 1; // Variable to store the direction of movement
    sf::RectangleShape line[32];

    void setline_parameters(sf::RectangleShape& line ,int sw, int sh, int px, int py)
    {
        line.setSize(sf::Vector2f(sw, sh));
        line.setOutlineColor(sf::Color::Red);
        line.setOutlineThickness(4);
        line.setPosition(px, py);
        line.setFillColor(Color::Blue);      
    }

    Game()
    {

        srand(time(0));
        bg_texture.loadFromFile("img/background3.jpg");
        background.setTexture(bg_texture);
        background.setScale(1.08, 1.25);
        // initializeSmallBoxes();
        p = new Player("img/car1.png");
        e1 = new Enemy("img/car3.png");
        e2 = new Enemy("img/car3.png");
        e2->sprite.setPosition(280, 500);
        level = new Level;
        F[0] = new whiteFood("img/foodw.png");
        F[1] = new RedFood("img/foodr.png");
        F[2] = new GreenFood("img/foodg.png");
        F[3] = new OrangeFood("img/foodo.png");
        CF = new CommenFood[115];
        CF->DrawCF(CF);
        f[0] = f[1] = f[2] = f[3] = false;
        food_gotit = false;
        Enemy_disappear = false;
        Speed_Booster = false;
        levelup = 0;
        bf1.loadFromFile("img/pickup.wav");
        s1.setBuffer(bf1);
        bf2.loadFromFile("img/powerup.wav");
        s2.setBuffer(bf2);
        bf3.loadFromFile("img/enemyCollion.wav");
        s3.setBuffer(bf3);
        bf4.loadFromFile("img/monster.wav");
        s4.setBuffer(bf4);
        bf5.loadFromFile("img/winner.wav");
        s5.setBuffer(bf5);
        setline_parameters(line[0], 530, 20, 2, 100);
        setline_parameters(line[1], 530, 20, 848, 100);
        setline_parameters(line[2], 530, 20, 2, 873);
        setline_parameters(line[3], 530, 20, 848, 873);
        setline_parameters(line[4], 30, 300, 2, 125);
        setline_parameters(line[5], 30, 300, 1348, 125);
        setline_parameters(line[6], 30, 300, 2, 565);
        setline_parameters(line[7], 30, 300, 1348, 565);

        setline_parameters(line[8], 380, 20, 150, 200);//width , height , x , y
        setline_parameters(line[9], 380, 20, 848, 200);
        setline_parameters(line[10], 380, 20, 150, 773);
        setline_parameters(line[11], 380, 20, 848, 773);
        setline_parameters(line[12], 30, 199, 150, 225);
        setline_parameters(line[13], 30, 199, 1198, 225);
        setline_parameters(line[14], 30, 199, 150, 565);
        setline_parameters(line[15], 30, 199, 1198, 565);

        setline_parameters(line[16], 230, 20, 298, 300);//width , height , x , y
        setline_parameters(line[17], 230, 20, 848, 300);
        setline_parameters(line[18], 230, 20, 298, 673);
        setline_parameters(line[19], 230, 20, 848, 673);
        setline_parameters(line[20], 30, 99, 298, 325);
        setline_parameters(line[21], 30, 99, 1048, 325);
        setline_parameters(line[22], 30, 99, 298, 565);
        setline_parameters(line[23], 30, 99, 1048, 565);


        setline_parameters(line[24], 80, 20, 430, 400);//width , height , x , y
        setline_parameters(line[25], 80, 20, 860, 400);
        setline_parameters(line[26], 80, 20, 430, 573);
        setline_parameters(line[27], 80, 20, 860, 573);

        setline_parameters(line[28], 150, 20, 600, 460);//width , height , x , y
        setline_parameters(line[29], 150, 20, 600, 510);


        setline_parameters(line[30], 15, 15, 600, 490);//width , height , x , y
        setline_parameters(line[31], 15, 15, 735, 490);


        //void initializeSmallBoxes()
        //{
        //    // Add code here to initialize small boxes as needed
        //    smallBoxes.emplace_back(100.f, 100.f, 15.f, 15.f, 1); // Initial direction is 1 (right)
        //    smallBoxes.emplace_back(400.f, 500.f, 30.f, 30.f, -1); // Initial direction is -1 (left)
        //}

        outfile.open("game_data.txt", std::ios::app);

        if (!outfile.is_open()) {
            cout << "Error opening file for writing!" << endl;
            return;
        }

    }

    void start_game()
    {
        int road_choice = 0;
        int road_choice1 = 0;
        srand(time(0));
        RenderWindow window(VideoMode(1380, 900), title);
        Clock clock;
        float timer = 0;
        float clk=0;
        float food_incoming_timer = 0;
        float food_staying_timer = 0;
        float food_collide_timer = 0;
        float   level_timer = 0;
        bool gameOver = false;
        bool youWon = false;
        Event e;

        while (window.isOpen())
        {
            if (Lives::getCount() == 0)
            {
                gameOver = true;
                outfile << sc.getScore() << endl;
                outfile.close();
                break;
            }
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            clk += time;
            food_incoming_timer += time;
            food_staying_timer += time;
            food_collide_timer += time;
            level_timer += time;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game                        	    
            }
            if (Keyboard::isKeyPressed(Keyboard::P)) //If left key is pressed
            {
                isPause = true;
            }
            if (Keyboard::isKeyPressed(Keyboard::R)) //If left key is pressed
            {
                isPause = false;
            }

            if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            {
                if (!p->collion_with_walls(line))
                    p->move("l");    // Player will move to left
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            {
                if (!p->collion_with_walls(line))
                    p->move("r");  //player will move to right
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            {
                if (!p->collion_with_walls(line))
                    p->move("u");    //playet will move upwards
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            {
                if (!p->collion_with_walls(line))
                    p->move("d");  //player will move downwards

            }

            if (!isPause)
            {

                // Instead of immediately trying the next road_choice, try to resolve the collision
                if (road_choice == 0 && Enemy_disappear == false)
                {
                    e1->move(p->sprite.getPosition().x, p->sprite.getPosition().y, 0, line, level);
                    if (e1->collion_with_walls(line))
                        ++road_choice;
                }
                else if (road_choice == 1 && Enemy_disappear == false)
                {
                    e1->move(p->sprite.getPosition().x, p->sprite.getPosition().y, 1, line, level);
                    if (e1->collion_with_walls(line))
                        ++road_choice;
                }
                else if (road_choice == 2 && Enemy_disappear == false)
                {
                    e1->move(p->sprite.getPosition().x, p->sprite.getPosition().y, 2, line, level);
                    if (e1->collion_with_walls(line))
                        ++road_choice;
                }
                else if (road_choice == 3 && Enemy_disappear == false)
                {
                    e1->move(p->sprite.getPosition().x, p->sprite.getPosition().y, 3, line, level);
                    if (e1->collion_with_walls(line))
                        road_choice = 0;
                }
                //////////////////////////////////
                if (level->level >= 2)
                {
                    if (road_choice1 == 0 && Enemy_disappear == false)
                    {
                        e2->move(p->sprite.getPosition().x, p->sprite.getPosition().y, 0, line, level);
                        if (e2->collion_with_walls(line))
                            ++road_choice1;
                    }
                    else if (road_choice1 == 1 && Enemy_disappear == false)
                    {
                        e2->move(p->sprite.getPosition().x, p->sprite.getPosition().y, 1, line, level);
                        if (e2->collion_with_walls(line))
                            ++road_choice1;
                    }
                    else if (road_choice1 == 2 && Enemy_disappear == false)
                    {
                        e2->move(p->sprite.getPosition().x, p->sprite.getPosition().y, 2, line, level);
                        if (e2->collion_with_walls(line))
                            ++road_choice1;
                    }
                    else if (road_choice1 == 3 && Enemy_disappear == false)
                    {
                        e2->move(p->sprite.getPosition().x, p->sprite.getPosition().y, 3, line, level);
                        if (e2->collion_with_walls(line))
                            road_choice1 = 0;
                    }
                }
                ////////////////////////////////////////////////////////////Here we set the time for food to come and also set the random type of food that we got

                if ((int(food_incoming_timer) % 15 == 0) && timer > 3 && food_gotit == false)
                {

                    int c = rand() % 4;
                    if (c == 0)
                    {
                        do
                        {
                            int xFood = rand() % 1360 + 10;
                            int yFood = rand() % 780 + 100;
                            F[0]->sprite.setPosition(xFood, yFood);
                        } while (F[0]->Collion_with_wall(line));
                        f[0] = 1;
                    }
                    else if (c == 1)
                    {
                        do
                        {
                            int xFood = rand() % 1360 + 10;
                            int yFood = rand() % 780 + 100;
                            F[1]->sprite.setPosition(xFood, yFood);
                        } while (F[1]->Collion_with_wall(line));
                        f[1] = 1;

                    }
                    else if (c == 2)
                    {
                        do
                        {
                            int xFood = rand() % 1360 + 10;
                            int yFood = rand() % 780 + 100;
                            F[2]->sprite.setPosition(xFood, yFood);
                        } while (F[2]->Collion_with_wall(line));
                        f[2] = 1;
                    }
                    else
                    {
                        do
                        {
                            int xFood = rand() % 1360 + 10;
                            int yFood = rand() % 780 + 100;
                            F[3]->sprite.setPosition(xFood, yFood);
                        } while (F[3]->Collion_with_wall(line));
                        f[3] = 1;
                    }
                    food_staying_timer = 0;
                    food_gotit = true;
                }

                    for (int i = 0; i < 4; i++)            // here the collion with food detect and perform the steps according to it
                    if (f[i])
                    {
                        p->Collion_with_Food(F[i], Enemy_disappear, Speed_Booster, sc, food_collide_timer,s2);
                    }
                if (food_collide_timer > 10)
                {
                    Enemy_disappear = false;
                    p->speed = 0.5;

                    Speed_Booster = false;

                }
                p->Collion_with_cf(CF, sc,s1);
                ////////////////////////////////////////////////////////
                if (food_staying_timer > 10 && (f[0] == 1 || f[1] == 1 || f[2] == 1 || f[3] == 1))
                {
                    f[0] = f[1] = f[2] = f[3] = 0;
                    F[0]->sprite.setPosition(-10, -10);
                    F[1]->sprite.setPosition(-10, -10);
                    F[2]->sprite.setPosition(-10, -10);
                    F[3]->sprite.setPosition(-10, -10);
                    food_gotit = false;
                }

                /////////////////////////////////////Here The Affect of Fruits appear/////////////////////////


                // Increment the road_choice for the next iteration
                 

                ////////////////////////////////////////////////////////
                if (clk >= 1)
                {
                    sc.setTime(1);
                    clk = 0;
                }

                // ####################### Collion Detection Functions
                if (Enemy_disappear == false)
                {
                    p->collion_with_opponent(e1,s3);
                    if (level->level > 1)
                        p->collion_with_opponent(e2,s3);
                }
                if (Speed_Booster)
                {
                    p->speed = p->speed + p->speed / 2;
                    Speed_Booster = false;
                }

                levelup = false;
                if (CommenFood::cf_count == 0)
                {
                    level->Levelup();
                    if (level->level == 5)
                    {
                        youWon = true;
                        outfile << sc.getScore()  << endl;
                        outfile.close();
                        break;
                    }
                        CF->DrawCF(CF);
                    if (level->level == 3)
                        e2->speed = e2->speed + 0.8;
                    if (level->level == 4)
                        e2->speed = e1->speed;
                    levelup = true;
                    CommenFood::cf_count = 114;
                    level_timer = 0;
                    p->sprite.setPosition(640, 100);
                }
                ////////////////////////////////////////////////
                /////  Call your functions here ///////////////
                //////////////////////////////////////////////

                if (levelup || level_timer < 4)
                {
                    window.clear(Color::Black); //clears the screen
                    window.draw(background);  // setting background
                    Font font;
                    Text sc;
                    font.loadFromFile("img/font1/2.ttf");
                    sc.setFont(font);
                    sc.setCharacterSize(150);
                    sc.setFillColor(Color::Blue);
                    sc.setPosition(240, 370);
                    sc.setString("LEVEL " + to_string(level->level));
                    window.draw(sc);
                }
                else
                {
                    window.clear(Color::Black); //clears the screen
                    window.draw(background);  // setting background
                    for (int i = 0; i < 32; i++)
                        window.draw(line[i]);

                    window.draw(p->sprite);
                    if (Enemy_disappear == false)
                    {
                        window.draw(e1->sprite);
                        if (level->level > 1)
                            window.draw(e2->sprite);
                    }
                    window.draw(sc.sc);
                    window.draw(sc.time);
                    for (int i = 0; i < l1->getLives(); i++)
                        window.draw(l1[i].sprite);
                    for (int i = 1; i < 115; i++)
                    {
                        window.draw(CF[i].sprite);
                    }
                    for (int i = 0; i < 4; i++)
                    {
                        if (f[i] == 1)
                            window.draw(F[i]->sprite);
                    }
                }
            }
                if (isPause == true && !(levelup || level_timer < 6) )
                {
                    Font font1;
                    Text sc1;
                    font1.loadFromFile("img/font1/2.ttf");
                    sc1.setFont(font1);
                    sc1.setCharacterSize(150);
                    sc1.setFillColor(Color::Green);
                    sc1.setPosition(240, 370);
                    sc1.setString("PAUSED!!!");
                    window.draw(sc1);
                }
                window.display();  //Displying all the sprites
            }
            while(1)
            {
           
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    break;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    break;
                if (gameOver)
                {
                    s4.play();
                    window.clear(Color::Black); //clears the screen
                    window.draw(background);  // setting background
                    Font font2;
                    Text sc2;
                    Text sc3;
                    font2.loadFromFile("img/font1/2.ttf");
                    sc2.setFont(font2);
                    sc2.setCharacterSize(120);
                    sc2.setFillColor(Color::Blue);
                    sc2.setPosition(130, 170);
                    sc2.setString("! Game Over !\n\n");
                    sc3.setFont(font2);
                    sc3.setCharacterSize(70);
                    sc3.setFillColor(Color::Red);
                    sc3.setPosition(380, 430);
                    sc3.setString("Your Score  \n\n      " + to_string(sc.getScore()));
                    window.draw(sc2);
                    window.draw(sc3);
                }
                if (youWon)
                {
                    s5.play();
                    window.clear(Color::Black); //clears the screen
                    window.draw(background);  // setting background
                    Font font2;
                    Text sc2;
                    Text sc3;
                    font2.loadFromFile("img/font1/1.otf");
                    sc2.setFont(font2);
                    sc2.setCharacterSize(120);
                    sc2.setFillColor(Color::Blue);
                    sc2.setPosition(210, 170);
                    sc2.setString("! You Won !\n\n");
                    sc3.setFont(font2);
                    sc3.setCharacterSize(70);
                    sc3.setFillColor(Color::Red);
                    sc3.setPosition(410, 430);
                    sc3.setString("Your Score  \n\n      " + to_string(sc.getScore()));
                    window.draw(sc2);
                    window.draw(sc3);
                }
                window.display();  //Displying all the sprites
            }
        }
    


};

