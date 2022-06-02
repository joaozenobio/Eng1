//
// Created by joaozenobio on 28/04/2022.
//

#ifndef ENG1_FLOWIMPLEMENTATION_H
#define ENG1_FLOWIMPLEMENTATION_H


#include "Flow.h"
#include "handlebody.h"

/**
 * Flow that converges energy from a model to another
**/
class FlowBody : public Body {
protected:
    std::string name;
    double value;
    System* systemBegin;
    System* systemEnd;

public:
    /**
     * Default destructor
    **/
    virtual ~FlowBody();

    /**
     * Default constructor
     * \param name: Inital flow name
     * \param value: Inital flow value
     * \param systemBegin: Inital system where the flow comes from
     * \param systemEnd: Inital system where the flow goes to
     * \return Flow with initial name, value, systemBegin and systemEnd
    **/
    FlowBody(std::string name="", System* systemBegin=NULL, System* systemEnd=NULL);

    /**
     * Copy constructor
     * \param flow: Flow to copy from
     * \return Copied flow
    **/
    FlowBody(const FlowBody& flow);

    /**
     * Copy Assignment Operator
     * \param flow: Flow to copy from
     * \return Copied flow
    **/
    FlowBody& operator=(const FlowBody& flow);

    /**
     * Sets the expression of the flow
    **/
    virtual double expression() = 0;

    /**
     * Get system name
    **/
    std::string getName() const;

    /**
     * Set system name
     * \param n: Name for the flow
    **/
    void setName(std::string n);

    /**
     * Get system value
    **/
    double getValue() const;

    /**
     * Set system value
     * \param v: Value for the flow
    **/
    void setValue(double v);

    /**
     * Get systemBegin
    **/
    System* getSystemBegin() const;

    /**
     * Set systemBegin
     * \param system: SystemBegin for the flow
    **/
    void setSystemBegin(System* system);

    /**
     * Get systemEnd
    **/
    System* getSystemEnd() const;

    /**
     * Set systemBegin
     * \param system: SystemEnd for the flow
    **/
    void setSystemEnd(System* system);
};

template <typename Flow_IMPL>
class FlowHandle : public Handle<Flow_IMPL>, public Flow {
public:

    ~FlowHandle() override = default;

    FlowHandle<Flow_IMPL>(std::string name="", System* systemBegin=NULL, System* systemEnd=NULL){
        this->pImpl_->setName(name);
        this->pImpl_->setSystemBegin(systemBegin);
        this->pImpl_->setSystemEnd(systemEnd);
    }

    double expression() override {
        return this->pImpl_->expression();
    }

    std::string getName() const override {
        return this->pImpl_->getName();
    }

    void setName(std::string name) override {
        this->pImpl_->setName(name);
    }

    double getValue() const override {
        return this->pImpl_->getValue();
    }

    void setValue(double v) override {
        this->pImpl_->setValue(v);
    }

    System* getSystemBegin() const override {
        return this->pImpl_->getSystemBegin();
    }

    void setSystemBegin(System* systemBegin) override {
        this->pImpl_->setSystemBegin(systemBegin);
    }

    System* getSystemEnd() const override {
        return this->pImpl_->getSystemEnd();
    }

    void setSystemEnd(System* systemEnd) override {
        this->pImpl_->setSystemEnd(systemEnd);
    }
};


#endif //ENG1_FLOWIMPLEMENTATION_H
