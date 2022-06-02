//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_SYSTEMIMPLEMENTATION_H
#define ENG1_SYSTEMIMPLEMENTATION_H

#include "System.h"
#include "handlebody.h"

/**
 * System that stores energy
**/
class SystemBody : public Body {
protected:
    std::string name;
    double value;

public:
    /**
     * Default destructor
    **/
    virtual ~SystemBody() override;

    /**
     * Default constructor
     * \param name: Inital system name
     * \param value: Inital system value
     * \return System with initial name and value
    **/
    SystemBody(std::string name="", double value=0.0);

    /**
     * Copy constructor
     * \param system: System to copy from
     * \return Copied system
    **/
    SystemBody(const SystemBody& system);

    /**
     * Copy Assignment Operator
     * \param system: System to copy from
     * \return Copied system
    **/
    SystemBody& operator=(const SystemBody& system);

    /**
     * Get system name
    **/
    std::string getName() const;

    /**
     * Set system name
     * \param n: Name for the system
    **/
    void setName(std::string n);

    /**
     * Get system value
    **/
    double getValue() const;

    /**
     * Set system value
     * \param v: Value for the system
    **/
    void setValue(double v);
};

class SystemHandle : public Handle<SystemBody>, public System{
public:
    ~SystemHandle() override = default;

    SystemHandle(std::string name="", double value=0.0){
        pImpl_->setName(name);
        pImpl_->setValue(value);
    }

    std::string getName() const override {
        return pImpl_->getName();
    }

    void setName(std::string sysName) override {
        pImpl_->setName(sysName);
    }

    double getValue() const override {
        return pImpl_->getValue();
    }

    void setValue(double sysValue) override {
        pImpl_->setValue(sysValue);
    }
};

#endif //ENG1_SYSTEMIMPLEMENTATION_H
