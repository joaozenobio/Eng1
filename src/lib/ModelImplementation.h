//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_MODELIMPLEMENTATION_H
#define ENG1_MODELIMPLEMENTATION_H


#include "Model.h"

class ModelImplementation: public Model {
protected:
    std::string name;
    double time;
    std::vector<System*> systems;
    std::vector<Flow*> flows;
public:
    ~ModelImplementation() override;
    explicit ModelImplementation(std::string name, double time);
    ModelImplementation(const ModelImplementation& model);
    ModelImplementation& operator=(const ModelImplementation& model);
    void simulate(double start, double end, double interval) override;
    std::string getName() const override;
    void setName(std::string n) override;
    double getTime() const override;
    void setTime(std::string t) override;
    void add(System*) override;
    void add(Flow*) override;
};


#endif //ENG1_MODELIMPLEMENTATION_H
