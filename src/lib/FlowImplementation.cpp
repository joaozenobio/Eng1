//
// Created by joaozenobio on 28/04/2022.
//

#include "FlowImplementation.h"

FlowImplementation::~FlowImplementation() = default;

FlowImplementation::FlowImplementation(std::string name, double value, System* systemBegin, System* systemEnd) : name(name), value(value), systemBegin(systemBegin), systemEnd(systemEnd) {}

FlowImplementation::FlowImplementation(const FlowImplementation& flow) {
    name = flow.getName();
    value = flow.getValue();
}

FlowImplementation& FlowImplementation::operator=(const Flow& flow){
    if (this == &flow){
        return *this;
    }
    setName(flow.getName());
    setValue(flow.getValue());
    return *this;
}

std::string FlowImplementation::getName() const {
    return name;
}

void FlowImplementation::setName(std::string n) {
    name = n;
}

double FlowImplementation::getValue() const {
    return value;
}

void FlowImplementation::setValue(double v) {
    value = v;
}

System* FlowImplementation::getSystemBegin() const {
    return systemBegin;
}

void FlowImplementation::setSystemBegin(System* system) {
    systemBegin = system;
}

System* FlowImplementation::getSystemEnd() const {
    return systemEnd;
}

void FlowImplementation::setSystemEnd(System* system) {
    systemEnd = system;
}
