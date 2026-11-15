#include "PressureSensor.h"
#include <iostream>

#include "../AircraftComponent/AircraftComponent.h"

using namespace std;

PressureSensor :: PressureSensor(string id, string name, double minPres, double maxPres) : AircraftComponent(id, name)
{
    minPressure = minPres;
    maxPressure = maxPres;
    currentPressure = 0;
    hasReading = false;

    if (minPressure >= maxPressure)
    {
        throw "Invalid threshold pressures";
    }

    cout << "Pressure sensor created!" << endl;
}
    
void PressureSensor::getReading()
{
    cout << "\nPlease enter current pressure: ";
    cin >> currentPressure;
    hasReading = true;
}

bool PressureSensor::checkReading() const 
{
    if (!hasReading)
    {
        return false;
    }

    return currentPressure >= minPressure && currentPressure <= maxPressure;
}

string PressureSensor::getReadingDescription() const
{
    if (!hasReading)
    {
        return "No valid reading currently held";
    }
    return to_string(currentPressure);
}
