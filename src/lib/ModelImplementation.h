//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_MODELIMPLEMENTATION_H
#define ENG1_MODELIMPLEMENTATION_H


#include "Model.h"

/**
 * Model that simulates the energy flow through models
**/
class ModelImplementation: public Model {

private:
    /**
     * Copy constructor
     * \param model: Model to copy from
     * \return Copied model
    **/
    ModelImplementation(const ModelImplementation& model);

protected:
    std::string name;
    double time;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    /**
     * Default destructor
    **/
    ~ModelImplementation() override;

    /**
     * Default constructor
     * \param name: Inital model name
     * \param time: Inital model time
     * \return Model with initial name and time
    **/
    ModelImplementation(std::string name, double time);

    /**
     * Copy Assignment Operator
     * \param model: Model to copy from
     * \return Copied model
    **/
    ModelImplementation& operator=(const ModelImplementation& model);

    /**
     * Simulates the model during a period of time between start and end time values with a specified timestep
     * \param start: Time where the simulation starts
     * \param end: Time where the simulation ends
     * \param timestep: Timestep value to simulate with
    **/
    void simulate(double start, double end, double timestep) override;

    /**
     * Get model name
    **/
    std::string getName() const override;

    /**
     * Set model name
     * \param n: Name for the system
    **/
    void setName(std::string n) override;

    /**
     * Get model time
    **/
    double getTime() const override;

    /**
     * Set model time
     * \param t: Name for the system
    **/
    void setTime(double t) override;

    /**
     * Add a system to the model
     * \param system: System to be added to the model
    **/
    void add(System* system) override;

    /**
     * Add a flow to the model
     * \param flow: Flow to be added to the model
    **/
    void add(Flow* flow) override;
};


#endif //ENG1_MODELIMPLEMENTATION_H
