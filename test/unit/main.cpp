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
    std::cout << "Unit test concluded" << "\n";
    return 0;
}