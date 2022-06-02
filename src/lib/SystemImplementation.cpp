//
// Created by joaozenobio on 28/04/2022.
//

#include "SystemImplementation.h"

SystemBody::~SystemBody() = default;

SystemBody::SystemBody(std::string name, double value): name(name), value(value) {}

std::string SystemBody::getName() const {
    return name;
}

void SystemBody::setName(std::string n) {
    name = n;
}

double SystemBody::getValue() const {
    return value;
}

void SystemBody::setValue(double v) {
    value = v;
}
