//
// Created by joaozenobio on 28/04/2022.
//

#include "FunctionalTests.h"

/**
    Function to test the exponencial flow.
*/
void ExponencialTest() {
    std::cout << "Exponencial test\n";
    Model* exponencialModel = Model::createModel("Exponencial Model", 0);
    System* system1 = exponencialModel->createSystem("System 1", 100);
    System* system2 = exponencialModel->createSystem("System 2", 0);
    Flow* exponencialFlow = exponencialModel->createFlow<ExponencialFlow>("Exponencial Flow", system1, system2);

    assert(exponencialModel->getName() == "Exponencial Model");
    assert(system1->getName() == "System 1");
    assert(system2->getName() == "System 2");
    assert(exponencialFlow->getName() == "Exponencial Flow");

    assert(fabs(system1->getValue() - 100) < 0.00005);
    assert(fabs(system2->getValue() - 0) < 0.00005);
    assert(fabs(exponencialModel->getTime() - 0) < 0.00005);

    exponencialModel->simulate(0, 100, 1);

    assert(fabs(system1->getValue() - 36.6032) < 0.00005);
    assert(fabs(system2->getValue() - 63.3968) < 0.00005);
    assert(fabs(exponencialModel->getTime() - 100) < 0.00005);

    delete(exponencialModel);
}

/**
    Function to test the logistical flow.
*/
void LogisticalTest() {
    std::cout << "Logistical test\n";

    Model* logisticalModel = Model::createModel("Logistical Model", 0);
    System* system1 = logisticalModel->createSystem("System 1", 100);
    System* system2 = logisticalModel->createSystem("System 2", 10);
    Flow* logisticalFlow = logisticalModel->createFlow<LogisticalFlow>("Logistical Flow", system1, system2);

    assert(logisticalModel->getName() == "Logistical Model");
    assert(system1->getName() == "System 1");
    assert(system2->getName() == "System 2");
    assert(logisticalFlow->getName() == "Logistical Flow");

    assert(fabs(system1->getValue() - 100) < 0.00005);
    assert(fabs(system2->getValue() - 10) < 0.00005);
    assert(fabs(logisticalModel->getTime() - 0) < 0.00005);

    logisticalModel->simulate(0, 100, 1);

    assert(fabs(system1->getValue() - 88.2167) < 0.00005);
    assert(fabs(system2->getValue() - 21.7833) < 0.00005);
    assert(fabs(logisticalModel->getTime() - 100) < 0.00005);

    delete(logisticalModel);
}

/**
    Function to test the complex flow.
*/
void ComplexTest() {
    std::cout << "Complex test\n";

    Model* complexModel = Model::createModel("Complex Model", 0);
    System* system1 = complexModel->createSystem("System 1", 100);
    System* system2 = complexModel->createSystem("System 2", 0);
    System* system3 = complexModel->createSystem("System 3", 100);
    System* system4 = complexModel->createSystem("System 4", 0);
    System* system5 = complexModel->createSystem("System 5", 0);
    Flow* complexFlow1 = complexModel->createFlow<ComplexFlow>("Complex Flow 1", system1, system3);
    Flow* complexFlow2 = complexModel->createFlow<ComplexFlow>("Complex Flow 2", system3, system4);
    Flow* complexFlow3 = complexModel->createFlow<ComplexFlow>("Complex Flow 3", system4, system1);
    Flow* complexFlow4 = complexModel->createFlow<ComplexFlow>("Complex Flow 4", system1, system2);
    Flow* complexFlow5 = complexModel->createFlow<ComplexFlow>("Complex Flow 5", system2, system3);
    Flow* complexFlow6 = complexModel->createFlow<ComplexFlow>("Complex Flow 6", system2, system5);

    assert(complexModel->getName() == "Complex Model");
    assert(system1->getName() == "System 1");
    assert(system2->getName() == "System 2");
    assert(system3->getName() == "System 3");
    assert(system4->getName() == "System 4");
    assert(system5->getName() == "System 5");
    assert(complexFlow1->getName() == "Complex Flow 1");
    assert(complexFlow2->getName() == "Complex Flow 2");
    assert(complexFlow3->getName() == "Complex Flow 3");
    assert(complexFlow4->getName() == "Complex Flow 4");
    assert(complexFlow5->getName() == "Complex Flow 5");
    assert(complexFlow6->getName() == "Complex Flow 6");

    assert(fabs(system1->getValue() - 100) < 0.00005);
    assert(fabs(system2->getValue() - 0) < 0.00005);
    assert(fabs(system3->getValue() - 100) < 0.00005);
    assert(fabs(system4->getValue() - 0) < 0.00005);
    assert(fabs(system5->getValue() - 0) < 0.00005);
    assert(fabs(complexModel->getTime() - 0) < 0.00005);

    complexModel->simulate(0, 100, 1);

    assert(fabs(system1->getValue() - 31.8513) < 0.00005);
    assert(fabs(system2->getValue() - 18.4003) < 0.00005);
    assert(fabs(system3->getValue() - 77.1143) < 0.00005);
    assert(fabs(system4->getValue() - 56.1728) < 0.00005);
    assert(fabs(system5->getValue() - 16.4612) < 0.00005);
    assert(fabs(complexModel->getTime() - 100) < 0.00005);

    delete(complexModel);
}