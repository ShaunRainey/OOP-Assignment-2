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

    void setFunctioning(bool status);
    void setNeedsMaintenance(bool required);

    virtual void generateReading() = 0;
    virtual bool checkReading() const = 0;
    virtual string getReading() const = 0;
    virtual void displayInfo() const = 0;

    string healthStatus() const;

private:
    string componentID;
    string componentName;
    bool isOnline;
    bool needsMaintenance;
};

#endif
