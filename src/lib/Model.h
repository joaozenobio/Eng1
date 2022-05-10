//
// Created by joaozenobio on 27/04/2022.
//

#ifndef ENG1_MODEL_H
#define ENG1_MODEL_H


#include <vector>
#include <string>

#include "System.h"
#include "Flow.h"

class Model {
public:
    virtual ~Model() = default;
    virtual void simulate(double, double, double) = 0;
    virtual std::string getName() const = 0;
    virtual void setName(std::string) = 0;
    virtual double getTime() const = 0;
    virtual void setTime(double) = 0;
    virtual void add(System*) = 0;
    virtual void add(Flow*) = 0;
};


#endif //ENG1_MODEL_H
