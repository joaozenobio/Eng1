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
    Model* model = Model::createModel("", 0);
    assert(model->getName() == "");
    assert(model->getTime() == 0.0);
    delete(model);
}

/**
 * Tests Model simluate method
 */
void unitModelSimulate() {
    Model* model = Model::createModel("", 0);
    System* system1 = model->createSystem("", 100);
    System* system2 = model->createSystem("", 0);
    Flow* flow = model->createFlow<UnitTestFlow2>("", system1, system2);
    model->simulate(0, 100, 1);
    assert(fabs(system1->getValue() - 36.6032) < 0.00005);
    assert(fabs(system2->getValue() - 63.3968) < 0.00005);
    delete(model);
}

/**
 * Tests Model getName method
 */
void unitModelGetName() {
    Model* model = Model::createModel("model", 10);
    assert(model->getName() == "model");
    delete(model);
}

/**
 * Tests Model setName method
 */
void unitModelSetName() {
    Model* model = Model::createModel("test", 10);
    model->setName("test");
    assert(model->getName() == "test");
    delete(model);
}

/**
 * Tests Model getTime method
 */
void unitModelGetTime(){
    Model* model = Model::createModel("", 10);
    assert(model->getTime() == 10);
    delete(model);
}

/**
 * Tests Model setTime method
 */
void unitModelSetTime() {
    Model* model = Model::createModel("", 10);
    model->setTime(20);
    assert(model->getTime() == 20);
    delete(model);
}

/**
 * Tests Model add to add a System
 */
void unitModelAddSystem() {
    Model* model = Model::createModel("", 10);
    System* system = model->createSystem("", 100);
    assert((*(model->getSystemsIterator())) == system);
    delete(model);
}

/**
 * Tests Model add to add a Flow
 */
void unitModelAddFlow() {
    Model* model = Model::createModel("", 10);
    Flow* flow = model->createFlow<UnitTestFlow2>("", NULL, NULL);
    assert((*(model->getFlowsIterator())) == flow);
    delete(model);
}

/**
 * Tests Model createSystem
 */
void unitModelCreateSystem() {
    Model* model = Model::createModel("", 0);
    System* system = model->createSystem("test", 100);
    assert(system->getName() == "test");
    assert(system->getValue() == 100);
    delete(model);
}

/**
 * Tests Model createFlow
 */
void unitModelCreateFlow() {
    Model* model = Model::createModel("", 0);
    Flow* flow = model->createFlow<UnitTestFlow2>("test", NULL, NULL);
    assert(flow->getName() == "test");
    assert(flow->getValue() == 0);
    delete(model);
}

/**
 * Tests Model createModel
 */
void unitModelCreateModel() {
    Model* model = Model::createModel("test", 10);
    assert(model->getName() == "test");
    assert(model->getTime() == 10);
    delete(model);
}

/**
 * Run all unit tests for Model
 */
void runUnitTestsModel() {
    unitModelDestructor();
    unitModelDefaultConstructor();
    unitModelSimulate();
    unitModelGetName();
    unitModelSetName();
    unitModelGetTime();
    unitModelSetTime();
    unitModelAddSystem();
    unitModelAddFlow();
    unitModelCreateSystem();
    unitModelCreateFlow();
    unitModelCreateModel();
}