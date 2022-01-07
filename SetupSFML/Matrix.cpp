//
//  Matrix.cpp
//  SetupSFML
//
//  Created by Fabian-Andrei Hirjan on 04.01.2022.
//  Copyright © 2022 Fabian-Andrei Hirjan. All rights reserved.
//

#include "Matrix.h"
#include <SFML/Graphics.hpp>

matrix::matrix(){

}


void matrix::drawMatrix(int arr[49]){
    int counter = 0;
    for(int i = 0; i<=48; i++)
        if(i == 3  + (counter*7)){
            counter++;
            arr[i] = 1;
        }
        else if(i>20 && i<28)
            arr[i]=1;
        else arr[i] = 0;
}
/*
void matrix::drawMatrix(int v[48][48]) { // also draws borders
    for (int i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++) {
        for (int j = 0; j < MAX_NUMBER_OF_ELEMENTS; j++) {
            if (i == 3 || j == 3)
                v[i][j] = 1;
            else v[i][j] = 2;
        }
    }
}

void matrix::printMatrix(int v[48][48]) {
    for (int i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++) {
        for (int j = 0; j < MAX_NUMBER_OF_ELEMENTS; j++) {
            cout << v[i][j] << " ";
            //Entitate.
        }
        cout << endl;
    }
}

void matrix::pickIcons(int v[48][48]) {
    for(int i = 0; i<MAX_NUMBER_OF_ELEMENTS; i++){
        for(int j = 0; j < MAX_NUMBER_OF_ELEMENTS; j++){
            if(i != 3 && j != 3){
                v[i][j] = rand() % difficulty;
                freq[v[i][j]]++;
            }
            
        }
    }
}
void matrix::fillFreq(int v[6]){
    for(int i = 0; i<difficulty-1; i++)
        v[i] = 0;
}




void debugSquares(){
    sf::RectangleShape rectangle(sf::Vector2f(100, 100));
}

void matrix::debug() {
    cout << "Hello world";
}
*/
// h : 0-3
// w: 0 - 3 | 5-7
//
//
// h : 4-7
//

//
