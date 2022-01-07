//
//  Matrix.h
//  SetupSFML
//
//  Created by Fabian-Andrei Hirjan on 04.01.2022.
//  Copyright © 2022 Fabian-Andrei Hirjan. All rights reserved.
//

#pragma once
#include<iostream>
using namespace std;

#define MAX_NUMBER_OF_ELEMENTS 7 // matrix size - it can be improved.
#define difficulty 4 // to be introduced + 1

// Level 1 - 1 element
// Level 2 - 2 elements
//..................
//..................


class matrix
{
public:
    matrix();
    
    void drawMatrix(int arr[49]);
    /*
    int arr[48][48];
    int freq[6];
    void fillMatrix(int v[48][48]);  // fills the matrix with random elements + searched elements
    void drawMatrix(int v[48][48]); // draw the matrix (with zeros) and the borders
    void printMatrix(int v[48][48]); // print, usually for debug
    void pickIcons(int v[48][48]); // pics some icons to be picked depending to the difficulty
    void fillFreq(int v[6]);
    void generateSolutions(int v[48][48], int weight, int height);
    void debug(); // Hello world
    void debugSquares();
     */
    
    
};
