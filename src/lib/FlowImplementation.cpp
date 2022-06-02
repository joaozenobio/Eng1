//
// Created by joaozenobio on 28/04/2022.
//

#include "FlowImplementation.h"

FlowBody::~FlowBody() = default;

FlowBody::FlowBody(std::string name, System* systemBegin, System* systemEnd) : name(name), systemBegin(systemBegin), systemEnd(systemEnd) {
    value = 0;
}

std::string FlowBody::getName() const {
    return name;
}

void FlowBody::setName(std::string n) {
    name = n;
}

double FlowBody::getValue() const {
    return value;
}

void FlowBody::setValue(double v) {
    value = v;
}

System* FlowBody::getSystemBegin() const {
    return systemBegin;
}

void FlowBody::setSystemBegin(System* system) {
    systemBegin = system;
}

System* FlowBody::getSystemEnd() const {
    return systemEnd;
}

void FlowBody::setSystemEnd(System* system) {
    systemEnd = system;
}
