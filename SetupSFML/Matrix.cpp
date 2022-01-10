//
//  Matrix.cpp
//  SetupSFML
//
//  Created by Fabian-Andrei Hirjan on 04.01.2022.
//  Copyright © 2022 Fabian-Andrei Hirjan. All rights reserved.
//

#include "Matrix.h"
#include <SFML/Graphics.hpp>
#include "calculus.hpp"

matrix::matrix(){

}
calculus clc;
void matrix::pickElements(int arr[9], int freq[9]){
    //v2 = rand() % 100 + 1;
    int picked;
    for(int i = 0; i<=8; i++){
        picked = clc.pickProb(1, 9);
        arr[i] = picked;
        freq[picked]++;
    }
}

int matrix::pickLegend(int arr[9], int legend[4], int i){
    int picked;
    picked = rand()%9 + 1;
    while(arr[picked] == 0)
        picked = rand()%9 + 1;
        return picked;
        
    }



void matrix::generateSolutions(int arr[9], int searched, int mat[9]){
    
    for(int i = 0; i<=8; i++){
        if(arr[i] != searched && arr[i] != 0)
            mat[i] = 0;
        else{
            mat[i] = 69;
    }
    
}
    
}
