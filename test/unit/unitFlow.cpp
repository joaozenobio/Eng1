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
    Model* model = Model::createModel("", 0);
    Flow* flow = model->createFlow<UnitTestFlow>("", NULL, NULL);
    assert(flow->getName() == "");
    assert(flow->getValue() == 0.0);
    delete(model);
}

/**
 * Tests Flow expression
 */
void unitFlowExpression() {
    Model* model = Model::createModel("", 0);
    System* system1 = model->createSystem("system1", 10);
    System* system2 = model->createSystem("system2", 0);
    Flow* flow = model->createFlow<UnitTestFlow>("", system1, system2);
    assert(fabs(flow->expression() - 0.1) < 0.00005);
    delete(model);
}

/**
 * Tests Flow getName method
 */
void unitFlowGetName(){
    Model* model = Model::createModel("", 0);
    Flow* flow = model->createFlow<UnitTestFlow>("flow", NULL, NULL);
    assert(flow->getName() == "flow");
    delete(model);
}

/**
 * Tests Flow setName method
 */
void unitFlowSetName() {
    Model* model = Model::createModel("", 0);
    Flow* flow = model->createFlow<UnitTestFlow>("", NULL, NULL);
    flow->setName("test");
    assert(flow->getName() == "test");
    delete(model);
}

/**
 * Tests Flow getValue method
 */
void unitFlowGetValue(){
    Model* model = Model::createModel("", 0);
    Flow* flow = model->createFlow<UnitTestFlow>("", NULL, NULL);
    flow->setValue(10);
    assert(flow->getValue() == 10);
    delete(model);
}

/**
 * Tests Flow setValue method
 */
void unitFlowSetValue() {
    Model* model = Model::createModel("", 0);
    Flow* flow = model->createFlow<UnitTestFlow>("", NULL, NULL);
    flow->setValue(20);
    assert(flow->getValue() == 20);
    delete(model);
}

/**
 * Tests Flow getSystemBegin method
 */
void unitFlowGetSystemBegin() {
    Model* model = Model::createModel("", 0);
    System* system1 = model->createSystem("system1", 10);
    Flow* flow = model->createFlow<UnitTestFlow>("", system1, NULL);
    System* system2 = flow->getSystemBegin();
    assert(system2->getName() == "system1");
    assert(system2->getValue() == 10);
    delete(model);
}

/**
 * Tests Flow setSystemBegin method
 */
void unitFlowSetSystemBegin() {
    Model* model = Model::createModel("", 0);
    Flow* flow = model->createFlow<UnitTestFlow>("", NULL, NULL);
    System* system1 = model->createSystem("system1", 10);
    flow->setSystemBegin(system1);
    System* system2 = flow->getSystemBegin();
    assert(system2->getName() == "system1");
    assert(system2->getValue() == 10);
    delete(model);
}

/**
 * Tests Flow getSystemEnd method
 */
void unitFlowGetSystemEnd() {
    Model* model = Model::createModel("", 0);
    System* system1 = model->createSystem("system1", 10);
    Flow* flow = model->createFlow<UnitTestFlow>("", NULL, system1);
    System* system2 = flow->getSystemEnd();
    assert(system2->getName() == "system1");
    assert(system2->getValue() == 10);
    delete(model);
}

/**
 * Tests Flow setSystemEnd method
 */
void unitFlowSetSystemEnd() {
    Model* model = Model::createModel("", 0);
    Flow* flow = model->createFlow<UnitTestFlow>("", NULL, NULL);
    System* system1 = model->createSystem("system1", 10);
    flow->setSystemEnd(system1);
    System* system2 = flow->getSystemEnd();
    assert(system2->getName() == "system1");
    assert(system2->getValue() == 10);
    delete(model);
}

/**
 * Run all unit tests for Flow
 */
void runUnitTestsFlow() {
    unitFlowDestructor();
    unitFlowDefaultConstructor();
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
