//
// Created by joaozenobio on 19/05/22.
//

#ifndef ENG1_UNITMODEL_H
#define ENG1_UNITMODEL_H


#include <cassert>
#include <cmath>

#include "../../src/lib/SystemImplementation.h"
#include "../../src/lib/FlowImplementation.h"
#include "../../src/lib/ModelImplementation.h"

/**
 * Flow used for testing
**/
class UnitTestFlow2 : public FlowImplementation{
public:
    /**
     * Default constructor
     * \param name: Inital flow name
     * \param value: Inital flow value
     * \param systemBegin: Inital system where the flow comes from
     * \param systemEnd: Inital system where the flow goes to
     * \return Flow with initial name, value, systemBegin and systemEnd
    **/
    UnitTestFlow2(std::string name, double value, System* systemOut, System* systemIn) : FlowImplementation(name, value, systemOut, systemIn) {}
    /**
     * Flow expression method implementation for testing
    **/
    double expression() override {
        return 0.01 * getSystemBegin()->getValue();
    }
};

void unitModelDestructor();
void unitModelDefaultConstructor();
void unitModelAssignmentOperator();
void unitModelSimulate();
void unitModelGetName();
void unitModelSetName();
void unitModelGetTime();
void unitModelSetTime();
void unitModeladdSystem();
void unitModeladdFlow();
void runUnitTestsModel();


#endif //ENG1_UNITMODEL_H
