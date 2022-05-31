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
    System* system = new SystemImplementation("", 0);
    assert(system->getName() == "");
    assert(system->getValue() == 0.0);
}

/**
 * Tests System assignment operator
 */
void unitSystemAssignmentOperator(){
    SystemImplementation* system1 = new SystemImplementation("Original", 10);
    SystemImplementation* system2 = new SystemImplementation("Teste", 0);
    *system2 = *system1;
    system1->setName("Original teste");
    system1->setValue(100.0);
    std::cout << system2->getName() << "\n";
    assert(system2->getName() == "Original");
    assert(system2->getValue() == 10);
}

/**
 * Tests System getName method
 */
void unitSystemGetName(){
    System* system = new SystemImplementation("system", 10);
    assert(system->getName() == "system");
}

/**
 * Tests System setName method
 */
void unitSystemSetName() {
    System* system = new SystemImplementation("system", 10);
    system->setName("test");
    assert(system->getName() == "test");
}

/**
 * Tests System getValue method
 */
void unitSystemGetValue(){
    System* system = new SystemImplementation("", 10);
    assert(system->getValue() == 10);
}

/**
 * Tests System setValue method
 */
void unitSystemSetValue() {
    System* system = new SystemImplementation("", 10);
    system->setValue(20);
    assert(system->getValue() == 20);
}

/**
 * Run all unit tests for System
 */
void runUnitTestsSystem() {
    unitSystemDestructor();
    unitSystemDefaultConstructor();
    unitSystemAssignmentOperator();
    unitSystemGetName();
    unitSystemSetName();
    unitSystemGetValue();
    unitSystemSetValue();
}