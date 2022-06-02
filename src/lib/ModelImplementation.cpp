//
// Created by joaozenobio on 28/04/2022.
//

#include <iostream>

#include "ModelImplementation.h"
#include "SystemImplementation.h"

std::vector<Model*> ModelBody::models;

ModelBody::~ModelBody(){    /*!destrutor padrao */
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
    auto i = getModelsIterator();
    for (Model* item : models){
        if (this == (ModelBody*)item){
            models.erase(i);
        }
        ++i;
    }
}

ModelBody::ModelBody(std::string name, double time) : name(name), time(time) {}

ModelBody::ModelBody(const ModelBody& model) {
    name = model.name;
    time = model.time;
    flows = model.flows;
    systems = model.systems;
}

ModelBody& ModelBody::operator=(const ModelBody& model) {
    if (this == &model){
        return *this;
    }
    name = model.name;
    time = model.time;
    flows = model.flows;
    systems = model.systems;
    return *this;
}

void ModelBody::simulate(double start, double end, double timestep) {
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

std::string ModelBody::getName() const {
    return name;
}

void ModelBody::setName(std::string n) {
    name = n;
}

double ModelBody::getTime() const {
    return time;
}

void ModelBody::setTime(double t) {
    time = t;
}

void ModelBody::add(Flow* flow) {
    flows.push_back(flow);
}

void ModelBody::add(System* system) {
    systems.push_back(system);
}

std::vector<System *>::iterator ModelBody::getSystemsIterator() {
    return systems.begin();
}

std::vector<Flow *>::iterator ModelBody::getFlowsIterator() {
    return flows.begin();
}

std::vector<Model *>::iterator ModelBody::getModelsIterator() {
    return models.begin();
}

std::vector<System*>::iterator ModelBody::endSystems(){
    return systems.end();
}

std::vector<Flow*>::iterator ModelBody::endFlows(){
    return flows.end();
}

std::vector<Model*>::iterator ModelBody::endModels(){
    return models.end();
}

System* ModelBody::createSystem(std::string name, double value){
    System* system = new SystemHandle(name, value);
    add(system);
    return system;
}

Model* Model::createModel(std::string name, double time){
    return ModelBody::createModel(name, time);
}

Model* ModelBody::createModel(std::string name, double time){
    Model* model = new ModelHandle(name, time);
    models.push_back(model);
    return model;
}