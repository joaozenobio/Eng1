//
// Created by joaozenobio on 28/04/2022.
//

#include "FlowImplementation.h"

FlowImplementation::~FlowImplementation() = default;

FlowImplementation::FlowImplementation(std::string name, double value, System* systemBegin, System* systemEnd) : name(name), value(value), SystemBegin(systemBegin), SystemEnd(systemEnd) {}

FlowImplementation::FlowImplementation(const FlowImplementation& flow) {
    name = flow.getName();
    value = flow.getValue();
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
    return SystemBegin;
}

void FlowImplementation::setSystemBegin(System* system) {
    SystemBegin = system;
}

System* FlowImplementation::getSystemEnd() const {
    return SystemEnd;
}

void FlowImplementation::setSystemEnd(System* system) {
    SystemEnd = system;
}
