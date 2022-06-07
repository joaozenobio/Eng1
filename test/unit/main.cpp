//
// Created by joaozenobio on 19/05/22.
//

#include <iostream>

#include "unitTests.h"

#define DEBUGING
#ifdef DEBUGING
int numHandleCreated;
int numHandleDeleted;
int numBodyCreated;
int numBodyDeleted;
#endif

int main(){
    runGlobal();
    std::cout << numBodyCreated << "\n";
    std::cout << numBodyDeleted << "\n";
    std::cout << numHandleCreated << "\n";
    std::cout << numHandleDeleted << "\n";
    std::cout << "Unit test concluded" << "\n";
    return 0;
}