//
// Created by joaozenobio on 28/04/2022.
//

#include <iostream>

#include "ModelImplementation.h"
#include "SystemImplementation.h"

ModelImplementation::~ModelImplementation(){    /*!destrutor padrao */
    if(!flows.empty()){
        for (Flow* item : flows) {
            delete (item);
        }
        flows.clear();
    }
    if(!systems.empty()){
        for (System* item : systems) {
            delete (item);
        }
        systems.clear();
    }
    auto i = beginModels();
    for (Model* item : models){
        if (this == item){
            models.erase(i);
            break;
        }
        ++i;
    }
}

ModelImplementation::ModelImplementation(std::string name, double time) : name(name), time(time) {}

ModelImplementation::ModelImplementation(const ModelImplementation& model) {
    name = model.name;
    time = model.time;
    flows = model.flows;
    systems = model.systems;
}

ModelImplementation& ModelImplementation::operator=(const ModelImplementation& model) {
    if (this == &model){
        return *this;
    }
    name = model.name;
    time = model.time;
    flows = model.flows;
    systems = model.systems;
    return *this;
}

void ModelImplementation::simulate(double start, double end, double timestep) {
    int count = 0;
    for (double i = start; i < end; i += timestep) {
        for (Flow* flow : flows) {
            flow->setValue(flow->expression());
        }
        for(Flow* flow : flows) {
            if(flow->getSystemBegin() != NULL) {
                flow->getSystemBegin()->setValue(flow->getSystemBegin()->getValue() - flow->getValue());
            }
            if(flow->getSystemEnd() != NULL) {
                flow->getSystemEnd()->setValue(flow->getSystemEnd()->getValue() + flow->getValue());
            }
            count++;
        }
        time += timestep;
    }
}

std::string ModelImplementation::getName() const {
    return name;
}

void ModelImplementation::setName(std::string n) {
    name = n;
}

double ModelImplementation::getTime() const {
    return time;
}

void ModelImplementation::setTime(double t) {
    time = t;
}

void ModelImplementation::add(Flow* flow) {
    flows.push_back(flow);
}

void ModelImplementation::add(System* system) {
    systems.push_back(system);
}

std::vector<System *>::iterator ModelImplementation::getSystemsIterator() {
    return systems.begin();
}

std::vector<Flow *>::iterator ModelImplementation::getFlowsIterator() {
    return flows.begin();
}

std::vector<System*>::iterator ModelImplementation::beginSystems(){
    return systems.begin();
}

std::vector<System*>::iterator ModelImplementation::endSystems(){
    return systems.end();
}

std::vector<Flow*>::iterator ModelImplementation::beginFlows(){
    return flows.begin();
}

std::vector<Flow*>::iterator ModelImplementation::endFlows(){
    return flows.end();
}

std::vector<Model*>::iterator ModelImplementation::beginModels(){
    return models.begin();
}

std::vector<Model*>::iterator ModelImplementation::endModels(){
    return models.end();
}

System* ModelImplementation::createSystem(std::string name, double value){
    System* system = new SystemImplementation(name, value);
    add(system);
    return system;
}

Model* Model::createModel(std::string name, double time){
    return ModelImplementation::createModel(name, time);
}

std::vector<Model*> ModelImplementation::models;

Model* ModelImplementation::createModel(std::string name, double time){
    Model* model = new ModelImplementation(name, time);
    models.push_back(model);
    return model;
}