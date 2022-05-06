//
// Created by joaozenobio on 28/04/2022.
//

#include "SystemImplementation.h"

SystemImplementation::~SystemImplementation() = default;

SystemImplementation::SystemImplementation(std::string name, double value): name(name), value(value) {}

SystemImplementation::SystemImplementation (const SystemImplementation& system){
    this->name = system.getName();
    this->value = system.getValue();
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
    return this->name;
}

void SystemImplementation::setName(std::string name) {
    this->name = name;
}

double SystemImplementation::getValue() const {
    return this->value;
}

void SystemImplementation::setValue(double value) {
    this->value = value;
}
