//
// Created by joaozenobio on 19/05/22.
//

#include "unitFlow.h"

/**
 * Tests Flow destructor
 */
void unitFlowDestructor(){};

/**
 * Tests Flow default constructor
 */
void unitFlowDefaultConstructor(){
    Flow* flow = new UnitTestFlow("", 0, NULL, NULL);
    assert(flow->getValue() == 0.0);
    assert(flow->getName() == "");
}

/**
 * Tests Flow assignment operator
 */
void unitFlowAssignmentOperator(){
    Flow* flow1 = new UnitTestFlow("", 0, NULL, NULL);
    Flow* flow2 = *(&flow1);
    flow1->setName("Original");
    flow1->setValue(100.0);
    assert(flow2->getName() == "Original");
    assert(flow2->getValue() == 100.0);
}

/**
 * Tests Flow expression
 */
void unitFlowExpression() {
    System* system1 = new SystemImplementation("system1", 10);
    System* system2 = new SystemImplementation("system2", 0);
    Flow* flow = new UnitTestFlow("", 0, system1, system2);
    assert(fabs(flow->expression() - 0.1) < 0.00005);
}

/**
 * Tests Flow getName method
 */
void unitFlowGetName(){
    Flow* flow = new UnitTestFlow("flow", 0, NULL, NULL);
    assert(flow->getName() == "flow");
}

/**
 * Tests Flow setName method
 */
void unitFlowSetName( ) {
    Flow* flow = new UnitTestFlow("", 0, NULL, NULL);
    flow->setName("test");
    assert(flow->getName() == "test");
}

/**
 * Tests Flow getValue method
 */
void unitFlowGetValue(){
    Flow* flow = new UnitTestFlow("", 10, NULL, NULL);
    assert(flow->getValue() == 10);
}

/**
 * Tests Flow setValue method
 */
void unitFlowSetValue( ) {
    Flow* flow = new UnitTestFlow("", 0, NULL, NULL);
    flow->setValue(20);
    assert(flow->getValue() == 20);
}

/**
 * Tests Flow getSystemBegin method
 */
void unitFlowGetSystemBegin() {
    System* system1 = new SystemImplementation("system1", 10);
    Flow* flow = new UnitTestFlow("", 0, system1, NULL);
    System* system2 = flow->getSystemBegin();
    assert(system2->getName() == "system1");
    assert(system2->getValue() == 10);
}

/**
 * Tests Flow setSystemBegin method
 */
void unitFlowSetSystemBegin() {
    Flow* flow = new UnitTestFlow("", 0, NULL, NULL);
    System* system1 = new SystemImplementation("system1", 10);
    flow->setSystemBegin(system1);
    System* system2 = flow->getSystemBegin();
    assert(system2->getName() == "system1");
    assert(system2->getValue() == 10);
}

/**
 * Tests Flow getSystemEnd method
 */
void unitFlowGetSystemEnd() {
    System* system1 = new SystemImplementation("system1", 10);
    Flow* flow = new UnitTestFlow("", 0, NULL, system1);
    System* system2 = flow->getSystemEnd();
    assert(system2->getName() == "system1");
    assert(system2->getValue() == 10);
}

/**
 * Tests Flow setSystemEnd method
 */
void unitFlowSetSystemEnd() {
    Flow* flow = new UnitTestFlow("", 0, NULL, NULL);
    System* system1 = new SystemImplementation("system1", 10);
    flow->setSystemEnd(system1);
    System* system2 = flow->getSystemEnd();
    assert(system2->getName() == "system1");
    assert(system2->getValue() == 10);
}

/**
 * Run all unit tests for Flow
 */
void runUnitTestsFlow() {
    unitFlowDestructor();
    unitFlowDefaultConstructor();
    unitFlowAssignmentOperator();
    unitFlowExpression();
    unitFlowGetName();
    unitFlowSetName();
    unitFlowGetValue();
    unitFlowSetValue();
    unitFlowGetSystemBegin();
    unitFlowSetSystemBegin();
    unitFlowGetSystemEnd();
    unitFlowSetSystemEnd();
}
