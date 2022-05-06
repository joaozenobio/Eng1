//
// Created by joaozenobio on 27/04/2022.
//

#ifndef ENG1_FLOW_H
#define ENG1_FLOW_H

#include <string>

#include "System.h"

class Flow {
public:
    virtual ~Flow() = default;
    virtual std::string getName() const = 0;
    virtual void setName(std::string) = 0;
    virtual double getValue() const = 0;
    virtual void setValue(double) = 0;
    virtual void expression() = 0;
    virtual System* getSystemBegin() const = 0;
    virtual void setSystemBegin(System*) = 0;
    virtual System* getSystemEnd() const = 0;
    virtual void setSystemEnd(System*) = 0;
};


#endif //ENG1_FLOW_H
