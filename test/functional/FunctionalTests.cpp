//
// Created by joaozenobio on 28/04/2022.
//

#include "FunctionalTests.h"

/**
 * Flow that converges energy from a model to another exponencialy with 1% of the initial system per timestep
**/
class ExponencialFlow : public FlowImplementation{
public:
    /**
     * Default constructor
     * \param name: Inital flow name
     * \param value: Inital flow value
     * \param systemBegin: Inital system where the flow comes from
     * \param systemEnd: Inital system where the flow goes to
     * \return Exponencial flow with initial name, value, systemBegin and systemEnd
    **/
    ExponencialFlow(std::string name, double value, System* systemOut, System* systemIn) : FlowImplementation(name, value, systemOut, systemIn) {}
    /**
     * Exponencial expression
    **/
    double expression() override {
        return 0.01 * getSystemBegin()->getValue();
    }
};

/**
 * Flow that converges energy from a model to another exponencialy with 1% of the end system per timestep
 * times onde minus the end system divided by seventy
**/
class LogisticalFlow : public FlowImplementation{
public:
    /**
     * Default constructor
     * \param name: Inital flow name
     * \param value: Inital flow value
     * \param systemBegin: Inital system where the flow comes from
     * \param systemEnd: Inital system where the flow goes to
     * \return Logistical flow with initial name, value, systemBegin and systemEnd
    **/
    LogisticalFlow(std::string name, double value, System* systemOut, System* systemIn) : FlowImplementation(name, value, systemOut, systemIn) {}
    /**
     * Logistical expression
    **/
    double expression() override {
        return 0.01 * this->getSystemEnd()->getValue() * (1 - this->getSystemEnd()->getValue() / 70);
    }
};

/**
 * Flow that converges energy from a model to another exponencialy with 1% of the end system per timestep
**/
class ComplexFlow : public FlowImplementation{
public:
    /**
     * Default constructor
     * \param name: Inital flow name
     * \param value: Inital flow value
     * \param systemBegin: Inital system where the flow comes from
     * \param systemEnd: Inital system where the flow goes to
     * \return Complex flow with initial name, value, systemBegin and systemEnd
    **/
    ComplexFlow(std::string name, double value, System* systemOut, System* systemIn) : FlowImplementation(name, value, systemOut, systemIn) {}
    /**
     * Complex expression
    **/
    double expression() override {
        return 0.01 * getSystemBegin()->getValue();
    }
};

/**
    Function to test the exponencial flow.
*/
void ExponencialTest() {
    std::cout << "Exponencial test\n";
    System* system1 = new SystemImplementation("System 1", 100);
    System* system2 = new SystemImplementation("System 2", 0);
    Flow* exponencialFlow = new ExponencialFlow("Exponencial Flow", 0, system1, system2);
    Model* exponencialModel = new ModelImplementation("Exponencial Model", 0);
    exponencialModel->add(system1);
    exponencialModel->add(system2);
    exponencialModel->add(exponencialFlow);

    assert(system1->getName() == "System 1");
    assert(system2->getName() == "System 2");
    assert(exponencialFlow->getName() == "Exponencial Flow");
    assert(exponencialModel->getName() == "Exponencial Model");

    assert(fabs(system1->getValue() - 100) < 0.00005);
    assert(fabs(system2->getValue() - 0) < 0.00005);

    exponencialModel->simulate(0, 100, 1);

    assert(fabs(system1->getValue() - 36.6032) < 0.00005);
    assert(fabs(system2->getValue() - 63.3968) < 0.00005);
}

/**
    Function to test the logistical flow.
*/
void LogisticalTest() {
    std::cout << "Logistical test\n";

    System* system1 = new SystemImplementation("System 1", 100);
    System* system2 = new SystemImplementation("System 2", 10);
    Flow* logisticalFlow = new LogisticalFlow("Logistical Flow", 0, system1, system2);
    Model* logisticalModel = new ModelImplementation("Logistical Model", 0);
    logisticalModel->add(system1);
    logisticalModel->add(system2);
    logisticalModel->add(logisticalFlow);

    assert(system1->getName() == "System 1");
    assert(system2->getName() == "System 2");
    assert(logisticalFlow->getName() == "Logistical Flow");
    assert(logisticalModel->getName() == "Logistical Model");

    assert(fabs(system1->getValue() - 100) < 0.00005);
    assert(fabs(system2->getValue() - 10) < 0.00005);

    logisticalModel->simulate(0, 100, 1);

    assert(fabs(system1->getValue() - 88.2167) < 0.00005);
    assert(fabs(system2->getValue() - 21.7833) < 0.00005);
}

/**
    Function to test the complex flow.
*/
void ComplexTest() {
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
    complexModel->add(system1);
    complexModel->add(system2);
    complexModel->add(system3);
    complexModel->add(system4);
    complexModel->add(system5);
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

    assert(fabs(system1->getValue() - 100) < 0.00005);
    assert(fabs(system2->getValue() - 0) < 0.00005);
    assert(fabs(system3->getValue() - 100) < 0.00005);
    assert(fabs(system4->getValue() - 0) < 0.00005);
    assert(fabs(system5->getValue() - 0) < 0.00005);

    complexModel->simulate(0, 100, 1);

    assert(fabs(system1->getValue() - 31.8513) < 0.00005);
    assert(fabs(system2->getValue() - 18.4003) < 0.00005);
    assert(fabs(system3->getValue() - 77.1143) < 0.00005);
    assert(fabs(system4->getValue() - 56.1728) < 0.00005);
    assert(fabs(system5->getValue() - 16.4612) < 0.00005);
}