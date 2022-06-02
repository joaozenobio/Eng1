//
// Created by joaozenobio on 28/04/2022.
//

#include <iostream>

#include "FunctionalTests.h"

#define DEBUGING
#ifdef DEBUGING
    int numHandleCreated;
    int numHandleDeleted;
    int numBodyCreated;
    int numBodyDeleted;
#endif

int main() {

    std::cout << "Begin test...\n";
    ExponencialTest();
    LogisticalTest();
    ComplexTest();

    std::cout << "End test!\n";

    return 0;
}