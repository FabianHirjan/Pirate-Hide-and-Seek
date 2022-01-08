#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Matrix.h"
#include "Tilemap.cpp"
#include <string>
#include <sstream>

int main() {

sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tilemap");
    // Text
    //vars
    sf::Text text;
    sf::Font font;
    //------------
    if(!font.loadFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/arial.ttf"))
        return -1;

    text.setFont(font);

    // set the string to display
    text.setString("Timp scurs:");


    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);
    // set the position
    text.setPosition(375, 0);

    // Matrix and tilemap
    /*
    const int level[] =
    {
        0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1
    };
     */
    matrix mtx;
    int level1[9];
    int level2[9];
    int level3[9];
    int level4[9];
    mtx.pickElements(level1,level1);
    mtx.pickElements(level2,level2);
    mtx.pickElements(level3,level3);
    mtx.pickElements(level4,level4);
    //mtx.drawMatrix(level);
    Tilemap map;
    if (!map.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), level1, 3, 3))
        return -1;

    //------------------------
    Tilemap map2;
    if (!map2.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), level2, 3, 3))
        return -1;
    map2.setPosition(128, 0);
    //
    Tilemap map3;
    if (!map3.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), level3, 3, 3))
        return -1;
    map3.setPosition(0, 128);
    //
    Tilemap map4;
    if (!map4.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), level4, 3, 3))
        return -1;
    map4.setPosition(128, 128);
    /*

    */

    
    // run the main loop
    sf::Clock clock;


std::string str = to_string(5.f);
    while (window.isOpen())
    {
        // handle events

        //
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time elapsed = clock.getElapsedTime();
        text.setString("Timp Scurs : " + to_string(int(elapsed.asSeconds())));
        // draw the map
        window.clear();
        window.draw(map);
        window.draw(map2);
        window.draw(map3);
        window.draw(map4);
        window.draw(text);
        window.display();
    }


}
