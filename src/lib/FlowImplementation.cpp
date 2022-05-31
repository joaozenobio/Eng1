//
// Created by joaozenobio on 28/04/2022.
//

#include "FlowImplementation.h"

FlowImplementation::~FlowImplementation() = default;

FlowImplementation::FlowImplementation(std::string name, System* systemBegin, System* systemEnd) : name(name), systemBegin(systemBegin), systemEnd(systemEnd) {
    value = 0;
}

FlowImplementation::FlowImplementation(const FlowImplementation& flow) {
    name = flow.name;
    value = flow.value;
    systemBegin = flow.systemBegin;
    systemEnd = flow.systemEnd;
}

FlowImplementation& FlowImplementation::operator=(const FlowImplementation& flow){
    if (this == &flow){
        return *this;
    }
    name = flow.name;
    value = flow.value;
    systemBegin = flow.systemBegin;
    systemEnd = flow.systemEnd;
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
