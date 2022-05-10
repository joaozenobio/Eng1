//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_FLOWIMPLEMENTATION_H
#define ENG1_FLOWIMPLEMENTATION_H


#include "Flow.h"

/**
 * Flow that converges energy from a model to another
**/
class FlowImplementation : public Flow {

private:
    /**
     * Copy constructor
     * \param flow: Flow to copy from
     * \return Copied flow
    **/
    FlowImplementation(const FlowImplementation& flow);

protected:
    std::string name;
    double value;
    System* systemBegin;
    System* systemEnd;

public:
    /**
     * Default destructor
    **/
    ~FlowImplementation() override;

    /**
     * Default constructor
     * \param name: Inital flow name
     * \param value: Inital flow value
     * \param systemBegin: Inital system where the flow comes from
     * \param systemEnd: Inital system where the flow goes to
     * \return Flow with initial name, value, systemBegin and systemEnd
    **/
    FlowImplementation(std::string name, double value, System* systemBegin, System* systemEnd);

    /**
     * Copy Assignment Operator
     * \param flow: Flow to copy from
     * \return Copied flow
    **/
    FlowImplementation& operator=(const Flow& flow);

    /**
     * Sets the expression of the flow
    **/
    void expression() override = 0;

    /**
     * Get system name
    **/
    std::string getName() const override;

    /**
     * Set system name
     * \param n: Name for the flow
    **/
    void setName(std::string n) override;

    /**
     * Get system value
    **/
    double getValue() const override;

    /**
     * Set system value
     * \param v: Value for the flow
    **/
    void setValue(double v) override;

    /**
     * Get systemBegin
    **/
    System* getSystemBegin() const override;

    /**
     * Set systemBegin
     * \param system: SystemBegin for the flow
    **/
    void setSystemBegin(System* system) override;

    /**
     * Get systemEnd
    **/
    System* getSystemEnd() const override;

    /**
     * Set systemBegin
     * \param system: SystemEnd for the flow
    **/
    void setSystemEnd(System* system) override;
};


#endif //ENG1_FLOWIMPLEMENTATION_H
