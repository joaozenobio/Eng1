//
// Created by joaozenobio on 19/05/22.
//

#include <iostream>
#include "unitSystem.h"

/**
 * Tests System destructor
 */
void unitSystemDestructor(){};

/**
 * Tests System default constructor
 */
void unitSystemDefaultConstructor(){
    Model* model = Model::createModel("", 0);
    System* system = model->createSystem("", 0);
    assert(system->getName() == "");
    assert(system->getValue() == 0.0);
    delete(model);
}

/**
 * Tests System getName method
 */
void unitSystemGetName(){
    Model* model = Model::createModel("", 0);
    System* system = model->createSystem("system", 10);
    assert(system->getName() == "system");
    delete(model);
}

/**
 * Tests System setName method
 */
void unitSystemSetName() {
    Model* model = Model::createModel("", 0);
    System* system = model->createSystem("system", 10);
    system->setName("test");
    assert(system->getName() == "test");
    delete(model);
}

/**
 * Tests System getValue method
 */
void unitSystemGetValue(){
    Model* model = Model::createModel("", 0);
    System* system = model->createSystem("", 10);
    assert(system->getValue() == 10);
    delete(model);
}

/**
 * Tests System setValue method
 */
void unitSystemSetValue() {
    Model* model = Model::createModel("", 0);
    System* system = model->createSystem("", 10);
    system->setValue(20);
    assert(system->getValue() == 20);
    delete(model);
}

/**
 * Run all unit tests for System
 */
void runUnitTestsSystem() {
    unitSystemDestructor();
    unitSystemDefaultConstructor();
    unitSystemGetName();
    unitSystemSetName();
    unitSystemGetValue();
    unitSystemSetValue();
}