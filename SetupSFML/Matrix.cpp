//
//  Matrix.cpp
//  SetupSFML
//
//  Created by Fabian-Andrei Hirjan on 04.01.2022.
//  Copyright © 2022 Fabian-Andrei Hirjan. All rights reserved.
//

#include "Matrix.h"

matrix::matrix(){

}
void matrix::drawMatrix(int v[48][48]) { // also draws borders
    for (int i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++) {
        for (int j = 0; j < MAX_NUMBER_OF_ELEMENTS; j++) {
            if (i == 3 || j == 3)
                v[i][j] = -1;
            else v[i][j] = 0;
        }
    }
}

void matrix::printMatrix(int v[48][48]) {
    for (int i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++) {
        for (int j = 0; j < MAX_NUMBER_OF_ELEMENTS; j++) {
            cout << v[i][j] << " ";
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


void matrix::generateSolutions(int v[48][48], int weight, int height){
    int solToBe[4][4];
    for(int i = 0 + height * 4; i< height * 2 -1; i++){
        for(int j = 0 + weight * 4 + weight; j< weight * 2 -1; j++){
            if(v[i][j] <= difficulty/3){
                cout << 1 << " ";
                }
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void matrix::debug() {
    cout << "Hello world";
}

// h : 0-3
// w: 0 - 3 | 5-7
//
//
// h : 4-7
//

//
