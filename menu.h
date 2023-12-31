#pragma
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
#include "game.h"
#include <fstream>

class Menu {
private:

    Texture menu;
    Sprite bg_Menu;

    Texture l;
    Sprite logo;

    Texture p;
    Sprite plane;

    ofstream outfile;
    ifstream infile;


    Texture ts;
    Sprite lg;

    int Max_items;
    int selet_item;
    Font font, s;
    Text* text;
    Text* S;
    Text* instruction;
    int width;
    int height;
    int highestScore1 = 0;
    int highestScore2 = 0;
    int highestScore = 0;
    bool check = false;
    SoundBuffer bf, ck;
    Sound sound, clk;
public:
    RenderWindow window1;

    //add menu attributes here
    Menu(float height = 900, float width = 1380)
    {
        

        bf.loadFromFile("img/S3.wav");
        sound.setBuffer(bf);
        sound.setVolume(200);


        ck.loadFromFile("img/clk.wav");
        clk.setBuffer(ck);
        clk.setVolume(200);
        

        this->width = width;
        this->height = height;
        menu.loadFromFile("img/Menu.jpg");
        bg_Menu.setTexture(menu);
        bg_Menu.setScale(0.8, 0.83);

        l.loadFromFile("img/logo.png");
        logo.setTexture(l);
        logo.setScale(0.6, 0.6);
        logo.setPosition(290, 200);

        p.loadFromFile("img/p1.png");
        plane.setTexture(p);
        plane.setScale(0.9, 0.9);
        plane.setPosition(130, 350);

        ts.loadFromFile("img/lg.png");
        lg.setTexture(ts);
        lg.setScale(0.3, 0.2);
        lg.setPosition(670, 800);

        (VideoMode(width, height), title);
        Max_items = 4;
        font.loadFromFile("img/F1/Airtravelers.otf");
        text = new Text[Max_items];
        for (int i = 0; i < Max_items; i++)
        {
            text[i].setFont(font);
            text[i].setCharacterSize(50);
            text[i].setFillColor(Color::White);

        }
        s.loadFromFile("img/F3/f3.ttf");


        text[0].setString("Start New Game");
        text[1].setString("High Score");
        text[2].setString("Help");
        text[3].setString("Exit");

        text[0].setPosition(width / 2 - 100, height / 2 - 70);
        text[1].setPosition(width / 2 - 70, height / 2+10);
        text[2].setPosition(width / 2 - 25, height / 2 + 80);
        text[3].setPosition(width / 2 - 20, height / 2 + 160);

        S = nullptr;
        instruction = nullptr;
        selet_item = 0;
        window1.create(VideoMode(width, height), title);


    }



    void display_menu()

    {
        sound.play();
        Game g;
        while (window1.isOpen())
        {
            Event event;
            while (window1.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window1.close();
            }

            if ((Mouse::getPosition(window1).y <= 431 && Mouse::getPosition(window1).y >= 395)
                && (Mouse::getPosition(window1).x <= 905 && Mouse::getPosition(window1).x >= 603))
            {
                text[0].setFillColor(Color::Red);
                if (event.type == Event::MouseButtonReleased)
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        clk.play();
                        sound.setVolume(30);
                        selet_item = 1;
                    }
            }
            else if ((Mouse::getPosition(window1).y <= 511 && Mouse::getPosition(window1).y >= 479)
                && (Mouse::getPosition(window1).x <= 845 && Mouse::getPosition(window1).x >= 632))
            {
                text[1].setFillColor(Color::Red);
                if (event.type == Event::MouseButtonReleased)
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        clk.play();
                        selet_item = 2;
                        check = true;
                    }



            }
            else if ((Mouse::getPosition(window1).y <= 585 && Mouse::getPosition(window1).y >= 549)
                && (Mouse::getPosition(window1).x <= 770 && Mouse::getPosition(window1).x >= 672))
            {
                text[2].setFillColor(Color::Red);
                if (event.type == Event::MouseButtonReleased)
                    if (event.mouseButton.button == Mouse::Left)
                        selet_item = 3;

            }
            else if ((Mouse::getPosition(window1).y <= 661 && Mouse::getPosition(window1).y >= 627)
                && (Mouse::getPosition(window1).x <= 752 && Mouse::getPosition(window1).x >= 678))
            {
                text[3].setFillColor(Color::Red);
                if (event.type == Event::MouseButtonReleased)
                    if (event.mouseButton.button == Mouse::Left)
                        selet_item = 4;
            }
            else
                for (int i = 0; i < 4; i++)
                    text[i].setFillColor(Color::White);

            if (selet_item)
            {
                clk.play();
            }
            switch (selet_item)
            {
            case 1:
            {

                sound.play();
                window1.close();
                g.start_game();
                window1.create(VideoMode(width, height), title);
                sound.setVolume(200);
                selet_item = 0;
            }
            break;
            case 2:
            {
                if (check)
                {

                    infile.open("game_data.txt");
                    if (infile.is_open()) {
                        std::string line;
                        while (std::getline(infile, line)) {
                            int score = std::stoi(line);
                            if (score > highestScore) {
                                highestScore2 = highestScore1;
                                highestScore1 = highestScore;
                                highestScore = score;
                            }
                            if (score > highestScore1 && score < highestScore) {
                                highestScore1 = score;
                            }
                            if (score > highestScore2 && score < highestScore1) {
                                highestScore2 = score;
                            }
                        }
                        infile.close();
                    }


                    check = false;
                }
                S = new Text;
                S->setFont(s);
                S->setFillColor(Color::Blue);
                S->setCharacterSize(70);
                S->setPosition(500, 250);
                S->setString("HIGHEST SCORES\n\n\t\t" + to_string(highestScore) + "\n\t\t" + to_string(highestScore1) + "\n\t\t" + to_string(highestScore2));
                menu.loadFromFile("img/inst.jpg");
                bg_Menu.setTexture(menu);
                bg_Menu.setScale(1.5, 1.9);
                window1.clear();
                window1.draw(bg_Menu);
                window1.draw(*S);
                window1.display();
                if (event.type == Event::KeyReleased)
                    if (event.key.code == Keyboard::Backspace)
                    {
                        selet_item = 0;

                        menu.loadFromFile("img/Menu.jpg");
                        bg_Menu.setTexture(menu);
                        bg_Menu.setScale(0.8, 0.83);
                        infile.close();

                    }



            }
            break;
            case 3:
            {
                instruction = new Text;
                instruction->setFont(font);
                instruction->setFillColor(Color::Blue);
                instruction->setCharacterSize(45);
                instruction->setPosition(300, 150);
                instruction->setString("\t\t\t\t\tInstructions \n\n\nYou Need to Move the Arrow Keys to move \nyour car in all directions. i.e Up for Upward.\n You have to Dodge from the Enemies\n  and get Highest Score.\n\n\nPress 'Backspace' Key to Back\n\n");
                menu.loadFromFile("img/inst.jpg");
                bg_Menu.setTexture(menu);
                bg_Menu.setScale(1.5, 1.9);
                window1.clear();
                window1.draw(bg_Menu);
                window1.draw(*instruction);
                window1.display();
                if (event.type == Event::KeyReleased)
                    if (event.key.code == Keyboard::Backspace)
                    {
                        selet_item = 0;
                        menu.loadFromFile("img/Menu.jpg");
                        bg_Menu.setTexture(menu);
                        bg_Menu.setScale(0.8, 0.83);
                    }
            }
            break;
            case 4:
            {
                window1.close();
            }
            break;
            default:
                break;
            }
            if (selet_item == 0)
            {
                window1.clear();
                window1.draw(bg_Menu);
                window1.draw(logo);
                window1.draw(plane);
                window1.draw(lg);
                window1.draw(lg);
                for (int i = 0; i < 4; i++)
                {
                    window1.draw(text[i]);
                }
                window1.display();
            }
        }

        //display menu screen here

        // add functionality of all the menu options here

        //if Start game option is chosen 


    }


};
