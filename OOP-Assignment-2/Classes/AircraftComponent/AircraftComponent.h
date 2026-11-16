#ifndef AIRCRAFTCOMPONENT_H
#define AIRCRAFTCOMPONENT_H

#include <string>
//#include "SensorStatus.h"

using namespace std;

class AircraftComponent
{
public:
    AircraftComponent(std::string id, std::string name);

    virtual ~AircraftComponent() = default;

    string getComponentID() const;
    string getComponentName() const;

    void setFunctioning(string status);
    void setNeedsMaintenance(bool required);

    virtual void generateReading() = 0;
    virtual void healthCheck() = 0;
    virtual string getReading() const = 0;
    virtual void displayInfo() const = 0;

    string healthStatus() const;

private:
    string componentID;
    string componentName;
    string health;
    bool needsMaintenance;
};

#endif
