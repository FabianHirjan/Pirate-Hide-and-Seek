#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Matrix.h"

int main() {
    bool isGameStarted = false;
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(900, 900), "Pirates hide and seek", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    sf::Font font;
    if (!font.loadFromFile("sansation.ttf"))
        std::cout << "Font not found!\n";
    
    // Matrix class call
    matrix mtx;
    
    mtx.drawMatrix(mtx.arr);
    mtx.pickIcons(mtx.arr);
    mtx.generateSolutions(mtx.arr, 0, 0);
    mtx.printMatrix(mtx.arr);
    
    
    // Easy created buttons;
    Button btn1("START", { 200, 100 }, 30, sf::Color::Green, sf::Color::Black);
    btn1.setFont(font);
    btn1.setPosition({ 100, 300 });


    //Main Loop:
    while (window.isOpen()) {

        sf::Event Event;

        //Event Loop:
        while (window.pollEvent(Event)) {
            switch (Event.type) {

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
                    window.setTitle("Pirates Game");
                    isGameStarted = true;
                }
            }
        }
        window.clear();
        if(isGameStarted == false) btn1.drawTo(window);
        window.display();
    }
}
