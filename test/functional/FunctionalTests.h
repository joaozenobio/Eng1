//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_FUNCTIONALTESTS_H
#define ENG1_FUNCTIONALTESTS_H

#include <iostream>
#include <cassert>
#include <cmath>

#include "../../src/lib/System.h"
#include "../../src/lib/FlowImplementation.h"
#include "../../src/lib/Model.h"

/**
 * Flow that converges energy from a model to another exponencialy with 1% of the initial system per timestep
**/
class ExponencialFlow : public FlowImplementation{
public:
    /**
     * Default constructor
     * \param name: Inital flow name
     * \param value: Inital flow value
     * \param systemBegin: Inital system where the flow comes from
     * \param systemEnd: Inital system where the flow goes to
     * \return Exponencial flow with initial name, value, systemBegin and systemEnd
    **/
    ExponencialFlow(std::string name, System* systemOut, System* systemIn) : FlowImplementation(name, systemOut, systemIn) {}
    /**
     * Exponencial expression
    **/
    double expression() override {
        return 0.01 * getSystemBegin()->getValue();
    }
};

/**
 * Flow that converges energy from a model to another exponencialy with 1% of the end system per timestep
 * times onde minus the end system divided by seventy
**/
class LogisticalFlow : public FlowImplementation{
public:
    /**
     * Default constructor
     * \param name: Inital flow name
     * \param value: Inital flow value
     * \param systemBegin: Inital system where the flow comes from
     * \param systemEnd: Inital system where the flow goes to
     * \return Logistical flow with initial name, value, systemBegin and systemEnd
    **/
    LogisticalFlow(std::string name, System* systemOut, System* systemIn) : FlowImplementation(name, systemOut, systemIn) {}
    /**
     * Logistical expression
    **/
    double expression() override {
        return 0.01 * this->getSystemEnd()->getValue() * (1 - this->getSystemEnd()->getValue() / 70);
    }
};

/**
 * Flow that converges energy from a model to another exponencialy with 1% of the end system per timestep
**/
class ComplexFlow : public FlowImplementation{
public:
    /**
     * Default constructor
     * \param name: Inital flow name
     * \param value: Inital flow value
     * \param systemBegin: Inital system where the flow comes from
     * \param systemEnd: Inital system where the flow goes to
     * \return Complex flow with initial name, value, systemBegin and systemEnd
    **/
    ComplexFlow(std::string name, System* systemOut, System* systemIn) : FlowImplementation(name, systemOut, systemIn) {}
    /**
     * Complex expression
    **/
    double expression() override {
        return 0.01 * getSystemBegin()->getValue();
    }
};

void ExponencialTest();
void ComplexTest();
void LogisticalTest();

#endif //ENG1_FUNCTIONALTESTS_H
