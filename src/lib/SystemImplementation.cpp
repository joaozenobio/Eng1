//
// Created by joaozenobio on 28/04/2022.
//

#include "SystemImplementation.h"

SystemImplementation::~SystemImplementation() = default;

SystemImplementation::SystemImplementation(std::string name, double value): name(name), value(value) {}

SystemImplementation::SystemImplementation (const SystemImplementation& system){
    name = system.getName();
    value = system.getValue();
}
SystemImplementation& SystemImplementation::operator=(const SystemImplementation& system){
    if (this == &system){
        return *this;
    }
    setName(system.getName());
    setValue(system.getValue());
    return *this;
}

std::string SystemImplementation::getName() const {
    return name;
}

void SystemImplementation::setName(std::string n) {
    name = n;
}

double SystemImplementation::getValue() const {
    return value;
}

void SystemImplementation::setValue(double v) {
    value = v;
}
