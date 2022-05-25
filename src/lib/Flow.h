//
// Created by joaozenobio on 27/04/2022.
//

#ifndef ENG1_FLOW_H
#define ENG1_FLOW_H

#include <string>

#include "System.h"

class Flow {
public:
    /**
     * Default destructor
    **/
    virtual ~Flow() = default;
    /**
     * Get system name
    **/
    virtual std::string getName() const = 0;
    /**
     * Set system name
     * \param n: Name for the flow
    **/
    virtual void setName(std::string) = 0;
    /**
     * Get system value
    **/
    virtual double getValue() const = 0;
    /**
     * Set system value
     * \param v: Value for the flow
    **/
    virtual void setValue(double) = 0;
    /**
     * Sets the expression of the flow
    **/
    virtual double expression() = 0;
    /**
     * Get systemBegin
    **/
    virtual System* getSystemBegin() const = 0;
    /**
     * Set systemBegin
     * \param system: SystemBegin for the flow
    **/
    virtual void setSystemBegin(System*) = 0;
    /**
     * Get systemEnd
    **/
    virtual System* getSystemEnd() const = 0;
    /**
     * Set systemBegin
     * \param system: SystemEnd for the flow
    **/
    virtual void setSystemEnd(System*) = 0;
};


#endif //ENG1_FLOW_H
