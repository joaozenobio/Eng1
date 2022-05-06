//
// Created by joaozenobio on 28/04/2022.
//

#include <iostream>

#include "ModelImplementation.h"

ModelImplementation::~ModelImplementation() {
    this->flows.clear();
    this->systems.clear();
}

ModelImplementation::ModelImplementation(std::string name, double time) : name(name), time(time) {}

ModelImplementation::ModelImplementation(const ModelImplementation &other) {}

ModelImplementation& ModelImplementation::operator=(const ModelImplementation& model) {
    return *this;
}

void ModelImplementation::simulate(double start, double end, double interval) {
    int count = 0;
    for (double i = start; i < end; i += interval) {
        for (Flow* flow : this->flows) {
            flow->expression();
        }
        for(Flow* flow : this->flows) {
            if(flow->getSystemBegin() != NULL) {
                flow->getSystemBegin()->setValue(flow->getSystemBegin()->getValue() - flow->getValue());
            }
            if(flow->getSystemEnd() != NULL) {
                flow->getSystemEnd()->setValue(flow->getSystemEnd()->getValue() + flow->getValue());
            }
            count++;
        }
        this->time += interval;
    }
}

std::string ModelImplementation::getName(){
    return this->name;
}

void ModelImplementation::setName(std::string name){
    this->name = name;
}

void ModelImplementation::add(Flow* flow){
    this->flows.push_back(flow);
}

void ModelImplementation::add(System* system){
    this->systems.push_back(system);
}