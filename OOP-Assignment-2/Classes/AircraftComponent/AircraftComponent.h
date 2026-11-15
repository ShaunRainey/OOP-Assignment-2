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

    string getComponentID();
    string getComponentName();

    void setFunctioning(bool status);
    void setNeedsMaintenance(bool required);

    virtual void getReading() = 0;
    virtual bool checkReading() const = 0;
    virtual string getReadingDescription() const = 0;

    string healthStatus() const;
    void displayInfo() const;

private:
    string componentID;
    string componentName;
    bool isOnline;
    bool needsMaintenance;
};

#endif
