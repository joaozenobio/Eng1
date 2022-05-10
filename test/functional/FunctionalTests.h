//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_FUNCTIONALTESTS_H
#define ENG1_FUNCTIONALTESTS_H

#include <iostream>
#include <cassert>
#include <cmath>

#include "../../src/lib/SystemImplementation.h"
#include "../../src/lib/FlowImplementation.h"
#include "../../src/lib/ModelImplementation.h"

class ExponencialFlow : public FlowImplementation{
public:
    ExponencialFlow(std::string name, double value, System* systemOut, System* systemIn) : FlowImplementation(name, value, systemOut, systemIn) {}
    void expression() override {
        this->setValue(0.01 * this->getSystemBegin()->getValue());
    }
};

class LogisticalFlow : public FlowImplementation{
public:
    LogisticalFlow(std::string name, double value, System* systemOut, System* systemIn) : FlowImplementation(name, value, systemOut, systemIn) {}
    void expression() override {
        this->setValue(0.01 * this->getSystemEnd()->getValue() * (1 - this->getSystemEnd()->getValue() / 70));
    }
};

class ComplexFlow : public FlowImplementation{
public:
    ComplexFlow(std::string name, double value, System* systemOut, System* systemIn) : FlowImplementation(name, value, systemOut, systemIn) {}
    void expression() override {
        this->setValue(0.01 * this->getSystemBegin()->getValue());
    }
};

class Test{
public:
    static void ExponencialTest();
    static void ComplexTest();
    static void LogisticalTest();
};

#endif //ENG1_FUNCTIONALTESTS_H
