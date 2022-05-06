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
    name = model.getName();
    name = model.getTime();
}

ModelImplementation& ModelImplementation::operator=(const ModelImplementation& model) {
    return *this;
}

void ModelImplementation::simulate(double start, double end, double interval) {
    int count = 0;
    for (double i = start; i < end; i += interval) {
        for (Flow* flow : flows) {
            flow->expression();
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
        time += interval;
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

void ModelImplementation::setTime(std::string t) {
    name = t;
}

void ModelImplementation::add(Flow* flow) {
    flows.push_back(flow);
}

void ModelImplementation::add(System* system) {
    systems.push_back(system);
}