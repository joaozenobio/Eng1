//
// Created by joaozenobio on 28/04/2022.
//

#include <iostream>

#include "FunctionalTests.h"

int main() {

    std::cout << "Begin test...\n";
    Test::ExponencialTest();
    Test::LogisticalTest();
    Test::ComplexTest();

    std::cout << "End test!\n";

    return 0;
}