//
// Created by joaozenobio on 27/04/2022.
//

#ifndef ENG1_SYSTEM_H
#define ENG1_SYSTEM_H

#include <string>

class System {
public:
    virtual ~System() = default;
    virtual std::string getName() const = 0;
    virtual void setName(std::string) = 0;
    virtual double getValue() const = 0;
    virtual void setValue(double) = 0;
};


#endif //ENG1_SYSTEM_H
