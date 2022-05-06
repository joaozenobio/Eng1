//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_SYSTEMIMPLEMENTATION_H
#define ENG1_SYSTEMIMPLEMENTATION_H

#include "System.h"

class SystemImplementation : public System {
protected:
    std::string name;
    double value;
public:
    ~SystemImplementation() override;
    SystemImplementation(std::string name, double value);
    SystemImplementation(const SystemImplementation& other);
    SystemImplementation& operator=(const SystemImplementation& sistema);
    std::string getName() const override;
    void setName(std::string n) override;
    double getValue() const override;
    void setValue(double v) override;
};


#endif //ENG1_SYSTEMIMPLEMENTATION_H
