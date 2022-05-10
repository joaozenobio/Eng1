//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_SYSTEMIMPLEMENTATION_H
#define ENG1_SYSTEMIMPLEMENTATION_H

#include "System.h"

class SystemImplementation : public System {

private:
    /**
     * Copy constructor
     * \param system: System to copy from
     * \return Copied system
    **/
    SystemImplementation(const SystemImplementation& system);

protected:
    std::string name;
    double value;

public:
    /**
     * Default destructor
    **/
    ~SystemImplementation() override;

    /**
     * Default constructor
     * \param name: Inital system name
     * \param value: Inital system value
     * \return System with initial name and value
    **/
    SystemImplementation(std::string name, double value);

    /**
     * Copy Assignment Operator
     * \param system: System to copy from
     * \return Copied system
    **/
    SystemImplementation& operator=(const SystemImplementation& system);

    /**
     * Get system name
    **/
    std::string getName() const override;

    /**
     * Set system name
     * \param n: Name for the system
    **/
    void setName(std::string n) override;

    /**
     * Get system value
    **/
    double getValue() const override;

    /**
     * Set system value
     * \param v: Value for the system
    **/
    void setValue(double v) override;
};


#endif //ENG1_SYSTEMIMPLEMENTATION_H
