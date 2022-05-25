//
// Created by joaozenobio on 19/05/22.
//

#include "unitModel.h"

/**
 * Tests Model destructor
 */
void unitModelDestructor(){};

/**
 * Tests Model default constructor
 */
void unitModelDefaultConstructor(){
    Model* model = new ModelImplementation("", 0);
    assert(model->getName() == "");
    assert(model->getTime() == 0.0);
}

/**
 * Tests Model assignment operator
 */
void unitModelAssignmentOperator(){
    Model* model1 = new ModelImplementation("", 10);
    Model* model2 = model1;
    model1->setName("Original");
    model1->setTime(100.0);
    assert(model2->getName() == "Original");
    assert(model2->getTime() == 100.0);
}

/**
 * Tests Model simluate method
 */
void unitModelSimulate() {
    System* system1 = new SystemImplementation("", 100);
    System* system2 = new SystemImplementation("", 0);
    Flow* flow = new UnitTestFlow2("", 0, system1, system2);
    Model* model = new ModelImplementation("", 0);
    model->add(system1);
    model->add(system2);
    model->add(flow);
    model->simulate(0, 100, 1);
    assert(fabs(system1->getValue() - 36.6032) < 0.00005);
    assert(fabs(system2->getValue() - 63.3968) < 0.00005);
}

/**
 * Tests Model getName method
 */
void unitModelGetName(){
    Model* model = new ModelImplementation("model", 10);
    assert(model->getName() == "model");
}

/**
 * Tests Model setName method
 */
void unitModelSetName() {
    Model* model = new ModelImplementation("test", 10);
    model->setName("test");
    assert(model->getName() == "test");
}

/**
 * Tests Model getTime method
 */
void unitModelGetTime(){
    Model* model = new ModelImplementation("", 10);
    assert(model->getTime() == 10);
}

/**
 * Tests Model setTime method
 */
void unitModelSetTime() {
    Model* model = new ModelImplementation("", 10);
    model->setTime(20);
    assert(model->getTime() == 20);
}

/**
 * Tests Model add to add a System
 */
void unitModeladdSystem() {
    System* system = new SystemImplementation("", 100);
    Model* model = new ModelImplementation("", 0);
    model->add(system);
    assert((*(model->getSystemsIterator()))->getName() == system->getName());
}

/**
 * Tests Model add to add a Flow
 */
void unitModeladdFlow() {
    System* system1 = new SystemImplementation("", 100);
    System* system2 = new SystemImplementation("", 0);
    Flow* flow = new UnitTestFlow2("", 0, system1, system2);
    Model* model = new ModelImplementation("", 0);
    model->add(flow);
    assert((*(model->getFlowsIterator()))->getName() == flow->getName());
}

/**
 * Run all unit tests for Model
 */
void runUnitTestsModel() {
    unitModelDestructor();
    unitModelDefaultConstructor();
    unitModelAssignmentOperator();
    unitModelSimulate();
    unitModelGetName();
    unitModelSetName();
    unitModelGetTime();
    unitModelSetTime();
    unitModeladdSystem();
    unitModeladdFlow();
}