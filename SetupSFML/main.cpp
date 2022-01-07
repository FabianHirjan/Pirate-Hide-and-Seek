#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Matrix.h"
#include "Tilemap.cpp"
#include <string>

int main() {
    
sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");
    // Text
    //vars
    sf::Text text;
    sf::Font font;
    //------------
    if(!font.loadFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/SetupSFML/arial.ttf"))
        return -1;
    
    text.setFont(font);

    // set the string to display
    text.setString("Time spent:");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);
    // set the position
    text.setPosition(375, 0);
    //--------------------------
    

    // Matrix and tilemap
    /*
    const int level[] =
    {
        0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1
    };
     */
    matrix mtx;
    int level[49];
    mtx.drawMatrix(level);
    Tilemap map;
    if (!map.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), level, 7, 7))
        return -1;
    
    //------------------------
    

    
    

    // run the main loop
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

        // draw the map
        window.clear();
        window.draw(map);
        window.draw(text);
        window.display();
    }
}
