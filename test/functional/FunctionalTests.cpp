//
// Created by joaozenobio on 28/04/2022.
//

#include "FunctionalTests.h"

void Test::ExponencialTest() {
    std::cout << "Exponencial test\n";
    System* system1 = new SystemImplementation("System 1", 100);
    System* system2 = new SystemImplementation("System 2", 0);
    Flow* exponencialFlow = new ExponencialFlow("Exponencial Flow", 0, system1, system2);
    Model* exponencialModel = new ModelImplementation("Exponencial Model", 0);
    exponencialModel->add(exponencialFlow);

    assert(system1->getName() == "System 1");
    assert(system2->getName() == "System 2");
    assert(exponencialFlow->getName() == "Exponencial Flow");
    assert(exponencialModel->getName() == "Exponencial Model");

    assert(fabs(system1->getValue() - 100) < 0.001);
    assert(fabs(system2->getValue() - 0) < 0.001);

    exponencialModel->simulate(0, 100, 1);

//    std::cout << system1->getValue() << "\n";
//    std::cout << system2->getValue() << "\n";
    assert(fabs(system1->getValue() - 36.6032) < 0.001);
    assert(fabs(system2->getValue() - 63.3968) < 0.001);
}

void Test::LogisticTest() {
    std::cout << "Logistic test\n";

    System* system1 = new SystemImplementation("System 1", 100);
    System* system2 = new SystemImplementation("System 2", 10);
    Flow* logisticFlow = new LogisticFlow("Logistic Flow", 0, system1, system2);
    Model* logisticModel = new ModelImplementation("Logistic Model", 0);
    logisticModel->add(logisticFlow);

    assert(system1->getName() == "System 1");
    assert(system2->getName() == "System 2");
    assert(logisticFlow->getName() == "Logistic Flow");
    assert(logisticModel->getName() == "Logistic Model");

    assert(fabs(system1->getValue() - 100) < 0.001);
    assert(fabs(system2->getValue() - 10) < 0.001);

    logisticModel->simulate(0, 100, 1);

//    std::cout << system1->getValue() << "\n";
//    std::cout << system2->getValue() << "\n";
    assert(fabs(system1->getValue() - 88.2167) < 0.0001);
    assert(fabs(system2->getValue() - 21.7833) < 0.0001);
}

void Test::ComplexTest() {
    std::cout << "Complex test\n";

    System* system1 = new SystemImplementation("System 1", 100);
    System* system2 = new SystemImplementation("System 2", 0);
    System* system3 = new SystemImplementation("System 3", 100);
    System* system4 = new SystemImplementation("System 4", 0);
    System* system5 = new SystemImplementation("System 5", 0);
    Flow* complexFlow1 = new ComplexFlow("Complex Flow 1", 0, system1, system3);
    Flow* complexFlow2 = new ComplexFlow("Complex Flow 2", 0, system3, system4);
    Flow* complexFlow3 = new ComplexFlow("Complex Flow 3", 0, system4, system1);
    Flow* complexFlow4 = new ComplexFlow("Complex Flow 4", 0, system1, system2);
    Flow* complexFlow5 = new ComplexFlow("Complex Flow 5", 0, system2, system3);
    Flow* complexFlow6 = new ComplexFlow("Complex Flow 6", 0, system2, system5);
    Model* complexModel = new ModelImplementation("Complex Model", 0);
    complexModel->add(complexFlow1);
    complexModel->add(complexFlow2);
    complexModel->add(complexFlow3);
    complexModel->add(complexFlow4);
    complexModel->add(complexFlow5);
    complexModel->add(complexFlow6);

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
    assert(complexModel->getName() == "Complex Model");

    assert(fabs(system1->getValue() - 100) < 0.0001);
    assert(fabs(system2->getValue() - 0) < 0.0001);
    assert(fabs(system3->getValue() - 100) < 0.0001);
    assert(fabs(system4->getValue() - 0) < 0.0001);
    assert(fabs(system5->getValue() - 0) < 0.0001);

    complexModel->simulate(0, 100, 1);

//    std::cout << system1->getValue() << "\n";
//    std::cout << system2->getValue() << "\n";
//    std::cout << system3->getValue() << "\n";
//    std::cout << system4->getValue() << "\n";
//    std::cout << system5->getValue() << "\n";
    assert(fabs(system1->getValue() - 31.8513) < 0.0001);
    assert(fabs(system2->getValue() - 18.4003) < 0.0001);
    assert(fabs(system3->getValue() - 77.1143) < 0.0001);
    assert(fabs(system4->getValue() - 56.1728) < 0.0001);
    assert(fabs(system5->getValue() - 16.4612) < 0.0001);
}