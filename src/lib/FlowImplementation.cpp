//
// Created by joaozenobio on 28/04/2022.
//

#include "FlowImplementation.h"

FlowImplementation::~FlowImplementation() = default;

FlowImplementation::FlowImplementation(std::string name, double value, System* systemBegin, System* systemEnd) : name(name), value(value), SystemBegin(systemBegin), SystemEnd(systemEnd) {}

FlowImplementation::FlowImplementation(const FlowImplementation& flow) {
    this->name = flow.getName();
    this->value = flow.getValue();
}

Flow& FlowImplementation::operator=(const Flow& flow){
    if (this == &flow){
        return *this;
    }
    setName(flow.getName());
    setSystemBegin(NULL);
    setSystemEnd(NULL);
    return *this;
}

std::string FlowImplementation::getName() const {
    return name;
}

void FlowImplementation::setName(std::string name) {
    this->name = name;
}

double FlowImplementation::getValue() const {
    return value;
}

void FlowImplementation::setValue(double value) {
    this->value = value;
}

System* FlowImplementation::getSystemBegin() const {
    return this->SystemBegin;
}

void FlowImplementation::setSystemBegin(System* system) {
    this->SystemBegin = system;
}

System* FlowImplementation::getSystemEnd() const {
    return this->SystemEnd;
}

void FlowImplementation::setSystemEnd(System* system) {
    this->SystemEnd = system;
}
