//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_FLOWIMPLEMENTATION_H
#define ENG1_FLOWIMPLEMENTATION_H


#include "Flow.h"

class FlowImplementation : public Flow {
protected:
    std::string name;
    double value;
    System* SystemBegin;
    System* SystemEnd;
public:
    ~FlowImplementation() override;
    FlowImplementation(std::string name, double value, System* systemBegin, System* systemEnd);
    FlowImplementation(const FlowImplementation& flow);
    Flow& operator=(const Flow& flow);
    void expression() override = 0;
    std::string getName() const override;
    void setName(std::string name) override;
    double getValue() const override;
    void setValue(double value) override;
    System* getSystemBegin() const override;
    void setSystemBegin(System* system) override;
    System* getSystemEnd() const override;
    void setSystemEnd(System* system) override;
};


#endif //ENG1_FLOWIMPLEMENTATION_H
