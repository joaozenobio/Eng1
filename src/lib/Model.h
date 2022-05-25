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
    /**
     * Default destructor
    **/
    virtual ~Model() = default;
    /**
     * Simulates the model during a period of time between start and end time values with a specified timestep
     * \param start: Time where the simulation starts
     * \param end: Time where the simulation ends
     * \param timestep: Timestep value to simulate with
    **/
    virtual void simulate(double, double, double) = 0;
    /**
     * Get model name
    **/
    virtual std::string getName() const = 0;
    /**
     * Set model name
     * \param n: Name for the system
    **/
    virtual void setName(std::string) = 0;
    /**
     * Get model time
    **/
    virtual double getTime() const = 0;
    /**
     * Set model time
     * \param t: Name for the system
    **/
    virtual void setTime(double) = 0;
    /**
    * Add a system to the model
    * \param system: System to be added to the model
   **/
    virtual void add(System*) = 0;
    /**
     * Add a flow to the model
     * \param flow: Flow to be added to the model
    **/
    virtual void add(Flow*) = 0;
    /**
     * Get model systems iterator
    **/
    virtual std::vector<System*>::iterator getSystemsIterator() = 0;
    /**
     * Get model flows iterator
    **/
    virtual std::vector<Flow*>::iterator getFlowsIterator() = 0;
};


#endif //ENG1_MODEL_H
