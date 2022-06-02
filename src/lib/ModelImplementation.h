//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_MODELIMPLEMENTATION_H
#define ENG1_MODELIMPLEMENTATION_H


#include "Model.h"
#include "handlebody.h"

/**
 * Model that simulates the energy flow through models
**/
class ModelBody: public Body {
private:
    /**
     * Copy constructor
     * \param model: Model to copy from
     * \return Copied model
    **/
    ModelBody(const ModelBody& model);

    /**
     * Copy Assignment Operator
     * \param model: Model to copy from
     * \return Copied model
    **/
    ModelBody& operator=(const ModelBody& model);

protected:
    std::string name;
    double time;
    std::vector<System*> systems;
    std::vector<Flow*> flows;
    static std::vector<Model*> models;

public:
    /**
     * Default destructor
    **/
    virtual ~ModelBody();

    /**
     * Default constructor
     * \param name: Inital model name
     * \param time: Inital model time
     * \return Model with initial name and time
    **/
    ModelBody(std::string name="", double time=0.0);

    /**
     * Simulates the model during a period of time between start and end time values with a specified timestep
     * \param start: Time where the simulation starts
     * \param end: Time where the simulation ends
     * \param timestep: Timestep value to simulate with
    **/
    void simulate(double start, double end, double timestep);

    /**
     * Get model name
    **/
    std::string getName() const;

    /**
     * Set model name
     * \param n: Name for the system
    **/
    void setName(std::string n);

    /**
     * Get model time
    **/
    double getTime() const;

    /**
     * Set model time
     * \param t: Name for the system
    **/
    void setTime(double t);

    /**
     * Add a system to the model
     * \param system: System to be added to the model
    **/
    void add(System* system);

    /**
     * Add a flow to the model
     * \param flow: Flow to be added to the model
    **/
    void add(Flow* flow);

    /**
     * Get model systems iterator
    **/
    std::vector<System*>::iterator getSystemsIterator();

    /**
     * Get model flows iterator
    **/
    std::vector<Flow*>::iterator getFlowsIterator();

    /**
     * Get model models iterator
    **/
    static std::vector<Model*>::iterator getModelsIterator();

    std::vector<System*>::iterator endSystems();

    std::vector<Flow*>::iterator endFlows();

    static std::vector<Model*>::iterator endModels();

    System* createSystem(std::string name, double value);

    static Model* createModel(std::string name, double time);
};

class ModelHandle : public Handle<ModelBody>, public Model{
public:

    ~ModelHandle() override = default;

    ModelHandle(std::string name="", double time=0.0){
        pImpl_->setName(name);
        pImpl_->setTime(time);
    }

    void simulate(double start, double end, double timestep) override {
        pImpl_->simulate(start, end, timestep);
    }

    System* createSystem(std::string name, double value) override{
        return pImpl_->createSystem(name, value);
    }

    static Model* createModel(std::string name, double time){
        return ModelBody::createModel(name, time);
    }

    void setName(std::string n) override {
        pImpl_->setName(n);
    }

    std::string getName() const override {
        return pImpl_->getName();
    }

    void setTime(double t) override {
        pImpl_->setTime(t);
    }

    double getTime() const override {
        return pImpl_->getTime();
    }

    void add(System* system) override {
        return pImpl_->add(system);
    }

    void add(Flow* flow) override {
        return pImpl_->add(flow);
    }

    std::vector<System*>::iterator getSystemsIterator() override {
        return pImpl_->getSystemsIterator();
    }

    std::vector<Flow*>::iterator getFlowsIterator() override {
        return pImpl_->getFlowsIterator();
    }

    std::vector<Model*>::iterator getModelsIterator() override {
        return ModelBody::getModelsIterator();
    }

    std::vector<System*>::iterator endSystems() override {
        return pImpl_->endSystems();
    };

    std::vector<Flow*>::iterator endFlows() override {
        return pImpl_->endFlows();
    };

    std::vector<Model*>::iterator endModels() override {
        return ModelBody::endModels();
    };
};

#endif //ENG1_MODELIMPLEMENTATION_H
