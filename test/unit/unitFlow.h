//
// Created by joaozenobio on 19/05/22.
//

#ifndef ENG1_UNITFLOW_H
#define ENG1_UNITFLOW_H


#include <cassert>
#include <cmath>

#include "../../src/lib/SystemImplementation.h"
#include "../../src/lib/FlowImplementation.h"

/**
 * Flow used for testing
**/
class UnitTestFlow : public FlowImplementation{
public:
    /**
     * Default constructor
     * \param name: Inital flow name
     * \param value: Inital flow value
     * \param systemBegin: Inital system where the flow comes from
     * \param systemEnd: Inital system where the flow goes to
     * \return Flow with initial name, value, systemBegin and systemEnd
    **/
    UnitTestFlow(std::string name, double value, System* systemOut, System* systemIn) : FlowImplementation(name, value, systemOut, systemIn) {}
    /**
     * Flow expression method implementation for testing
    **/
    double expression() override {
        return 0.01 * getSystemBegin()->getValue();
    }
};

void unitFlowDestructor();
void unitFlowDefaultConstructor();
void unitFlowAssignmentOperator();
void unitFlowExpression();
void unitFlowGetName();
void unitFlowSetName();
void unitFlowGetValue();
void unitFlowSetValue();
void unitFlowGetSystemBegin();
void unitFlowSetSystemBegin();
void unitFlowGetSystemEnd();
void unitFlowSetSystemEnd();
void runUnitTestsFlow();


#endif //ENG1_UNITFLOW_H
