//
// Created by joaozenobio on 27/04/2022.
//

#ifndef ENG1_SYSTEM_H
#define ENG1_SYSTEM_H

#include <string>

class System {
public:
    /**
     * Default destructor
    **/
    virtual ~System() = default;
    /**
     * Get system name
    **/
    virtual std::string getName() const = 0;
    /**
     * Set system name
     * \param n: Name for the system
    **/
    virtual void setName(std::string) = 0;
    /**
     * Get system value
    **/
    virtual double getValue() const = 0;
    /**
     * Set system value
     * \param v: Value for the system
    **/
    virtual void setValue(double) = 0;
};


#endif //ENG1_SYSTEM_H
