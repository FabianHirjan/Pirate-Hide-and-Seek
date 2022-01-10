#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "Button.h"
#include "Matrix.h"
#include "Tilemap.cpp"
#include "tilemaps.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(600, 600), "- Pirates Hide And Seek -");

    //vars
    sf::Text text;
    sf::Font font;
    tilemaps tm;
    matrix mtx;
    sf::Clock clock;
    int level[4][9];
    int solt[4][9];
    int freq[4];
    int isGameStarted = 0;
    int minute = 0;

    // Load font from file
    if(!font.loadFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/SetupSFML/arial.ttf"))
        return -1;

    text.setFont(font);
    text.setCharacterSize(24); // character size



    // set the color
    text.setFillColor(sf::Color::Red);
    // set the position
    text.setPosition(220, 70);



    // Generate matrix
    for(int i = 0; i<4; i++)
    {
        mtx.pickElements(level[i]);
        mtx.generateSolutions(level[i], i+1, solt[i], freq);
    }

    // Create start game button
    Button btn1("START", { 100, 50 }, 30, sf::Color::Green, sf::Color::Black);
    btn1.setFont(font);
    btn1.setPosition({ 250, 200 });
    btn1.setSize(25);
    Button btn2("EXIT", { 100, 50 }, 30, sf::Color::Green, sf::Color::Black);
    btn2.setFont(font);
    btn2.setPosition({ 250, 270 });
    btn2.setSize(25);


    // Start game


    // run the main loop



    std::string str = to_string(5.f);
    sf::Music music;

     //if (!music.openFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/SetupSFML/mel.wav"))
       //  return -1;

     music.play();
    bool isLongPressActiv = false, sq1 = false, sq2 = false, sq3 = false, sq4 = false;
    while (window.isOpen())
    {
        // handle events

        //
        sf::Event event;
        while (window.pollEvent(event))
        {
            sf::Vector2i mousePos;
            mousePos = sf::Mouse::getPosition(window);
            switch (event.type)
            {

            case sf::Event::Closed:
                window.close();

                break;

            case sf::Event::MouseButtonPressed:
            {
                sf::RectangleShape pt;
                pt.setSize({96, 96});
                pt.setPosition(450, 100);
                if(pt.getGlobalBounds().contains(sf::Vector2f(mousePos)))
                    sq1 = true;
                else
                {
                    pt.setPosition({450, 200});
                    if(pt.getGlobalBounds().contains(sf::Vector2f(mousePos)))
                        sq2 = true;
                    else
                    {
                        pt.setPosition({450, 300});
                        if(pt.getGlobalBounds().contains(sf::Vector2f(mousePos)))
                            sq3 = true;
                        else
                        {
                            pt.setPosition({450, 400});
                            if(pt.getGlobalBounds().contains(sf::Vector2f(mousePos)))
                                sq4 = true;
                            else
                            {
                                pt.setPosition({450, 500});

                            }

                        }
                    }
                }

                isLongPressActiv = true;
                if (btn1.isMouseOver(window))
                {
                    tm.StartGame(level, solt);
                    isGameStarted = true;
                    clock.restart();
                    minute = 0;
                }
                if (btn2.isMouseOver(window))
                {
                    window.close();
                }
                break;

            }
            case sf::Event::MouseMoved:
                if(isLongPressActiv == true)
                {
                    if(sq1 == true)
                        tm.sol1.setPosition({float(mousePos.x), float(mousePos.y)});
                    if(sq2 == true)
                        tm.sol2.setPosition({float(mousePos.x), float(mousePos.y)});
                    if(sq3 == true)
                        tm.sol3.setPosition({float(mousePos.x), float(mousePos.y)});
                    if(sq4 == true)
                        tm.sol4.setPosition({float(mousePos.x), float(mousePos.y)});
                }
                if (btn1.isMouseOver(window))
                {
                    btn1.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    btn1.setBackColor(sf::Color::Green);
                }
                if (btn2.isMouseOver(window))
                {
                    btn2.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    btn2.setBackColor(sf::Color::Green);
                }
                break;

            // verif daca coord is peste 1 din cele 4 matr
            case sf::Event::MouseButtonReleased:
                isLongPressActiv = false;
                sq1 = false;
                sq2 = false;
                sq3 = false;
                sq4 = false;
                tm.sol1.setPosition(450, 100);
                tm.sol2.setPosition(450, 200);
                tm.sol3.setPosition(450, 300);
                tm.sol4.setPosition(450, 400);
            }
        }

        sf::Time elapsed = clock.getElapsedTime();
        if(int(elapsed.asSeconds()) == 60)
        {
            clock.restart();
            minute++;
        }
        text.setString("Timp Scurs: " + to_string(minute) + ":" + to_string(int(elapsed.asSeconds())));
        // draw the map
        window.clear();
        if(isGameStarted)
        {
            window.draw(tm.map);
            window.draw(tm.map2);
            window.draw(tm.map3);
            window.draw(tm.map4);
            window.draw(text);
            window.draw(tm.sol1);
            window.draw(tm.sol2);
            window.draw(tm.sol3);
            window.draw(tm.sol4);
            
        }
        else{
            btn1.drawTo(window);
            btn2.drawTo(window);
        }
            
           
        window.display();
    }


}
