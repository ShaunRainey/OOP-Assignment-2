#include "AircraftComponent.h"
#include <iostream>

using namespace std;

AircraftComponent::AircraftComponent(string id, string name)
{
    componentID = id;
    componentName = name;
    isOnline = true;
    needsMaintenance = false;
}

std::string AircraftComponent::getComponentID() const
{
    return componentID;
}

std::string AircraftComponent::getComponentName() const
{
    return componentName;
}

void AircraftComponent::setFunctioning(bool status)
{
    isOnline = status;
}

void AircraftComponent::setNeedsMaintenance(bool required)
{
    needsMaintenance = required;
}

std::string AircraftComponent::healthStatus() const
{
    if (!isOnline)
    {
        return "Offline";
    }

    if (needsMaintenance)
    {
        return "Needs Maintenance";
    }

    return "Healthy";
}

//void AircraftComponent::displayInfo() const
//{
//    std::cout << "Component ID: " << componentID << std::endl;
//    std::cout << "ComponentName: " << componentName << std::endl;
//    std::cout << "Health status: " << healthStatus() << std::endl;
//    std::cout << "Reading: " << getReadingDescription()
//        << ": " << checkReading() << std::endl;
//}
