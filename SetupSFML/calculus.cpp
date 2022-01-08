//
//  calculus.cpp
//  SetupSFML
//
//  Created by Fabian-Andrei Hirjan on 08.01.2022.
//  Copyright © 2022 Fabian-Andrei Hirjan. All rights reserved.
//

#include "calculus.hpp"
#define prob 50


int calculus::pickProb(int from, int to){
    // 80% prob - 0
    // 20% prob another elements
    // to be changed
    int pick = rand()%100 + 0;
    
    if(pick < prob){
        return 0;
    }
    else return rand()%to + from;
    
}
