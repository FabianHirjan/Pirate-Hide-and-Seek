#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Matrix.h"
#include "Tilemap.cpp"
#include <string>
#include <sstream>
#include "tilemaps.h"

int main() {

sf::RenderWindow window(sf::VideoMode(600, 600), "Tilemap");
    
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
    if(!font.loadFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/arial.ttf"))
        return -1;

    text.setFont(font);

    // set the string to display
    text.setString("Timp scurs:");
    text.setCharacterSize(24); // character size



    // set the color
    text.setFillColor(sf::Color::Red);
    // set the position
    text.setPosition(220, 70);

 
    
    // Generate matrix
    for(int i = 0; i<4; i++){
        mtx.pickElements(level[i]);
        mtx.generateSolutions(level[i], i+1, solt[i], freq);
    }
    
    // Create start game button
    Button btn1("START", { 100, 50 }, 30, sf::Color::Green, sf::Color::Black);
    btn1.setFont(font);
    btn1.setPosition({ 100, 300 });
    btn1.setSize(20);
    
    
    // Start game
    
    
    // run the main loop



std::string str = to_string(5.f);
    while (window.isOpen())
    {
        // handle events

        //
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {

                        case sf::Event::Closed:
                            window.close();
                        case sf::Event::MouseMoved:
                            if (btn1.isMouseOver(window)) {
                                btn1.setBackColor(sf::Color::Magenta);
                            }
                            else {
                                btn1.setBackColor(sf::Color::Green);
                            }
                            break;
                        case sf::Event::MouseButtonPressed:
                            if (btn1.isMouseOver(window)) {
                                tm.StartGame(level, solt);
                                window.setTitle("Pirates Game");
                            isGameStarted = true;
                                clock.restart();
                                minute = 0;
                            }
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
        if(isGameStarted){
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
        else
        btn1.drawTo(window);
        window.display();
    }


}
