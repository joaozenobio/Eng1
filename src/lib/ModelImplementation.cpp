//
// Created by joaozenobio on 28/04/2022.
//

#include <iostream>

#include "ModelImplementation.h"

ModelImplementation::~ModelImplementation() {
    flows.clear();
    systems.clear();
}

ModelImplementation::ModelImplementation(std::string name, double time) : name(name), time(time) {}

ModelImplementation::ModelImplementation(const ModelImplementation& model) {
    name = model.name;
    time = model.time;
    flows = model.flows;
    systems = model.systems;
}

ModelImplementation& ModelImplementation::operator=(const ModelImplementation& model) {
    if (this == &model){
        return *this;
    }
    name = model.name;
    time = model.time;
    flows = model.flows;
    systems = model.systems;
    return *this;
}

void ModelImplementation::simulate(double start, double end, double timestep) {
    int count = 0;
    for (double i = start; i < end; i += timestep) {
        for (Flow* flow : flows) {
            flow->setValue(flow->expression());
        }
        for(Flow* flow : flows) {
            if(flow->getSystemBegin() != NULL) {
                flow->getSystemBegin()->setValue(flow->getSystemBegin()->getValue() - flow->getValue());
            }
            if(flow->getSystemEnd() != NULL) {
                flow->getSystemEnd()->setValue(flow->getSystemEnd()->getValue() + flow->getValue());
            }
            count++;
        }
        time += timestep;
    }
}

std::string ModelImplementation::getName() const {
    return name;
}

void ModelImplementation::setName(std::string n) {
    name = n;
}

double ModelImplementation::getTime() const {
    return time;
}

void ModelImplementation::setTime(double t) {
    time = t;
}

void ModelImplementation::add(Flow* flow) {
    flows.push_back(flow);
}

void ModelImplementation::add(System* system) {
    systems.push_back(system);
}

std::vector<System *>::iterator ModelImplementation::getSystemsIterator() {
    return systems.begin();
}

std::vector<Flow *>::iterator ModelImplementation::getFlowsIterator() {
    return flows.begin();
}
