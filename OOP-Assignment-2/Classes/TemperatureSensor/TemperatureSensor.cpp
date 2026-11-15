#include "TemperatureSensor.h"
#include <iostream>

#include "../AircraftComponent/AircraftComponent.h"

using namespace std;

TemperatureSensor::TemperatureSensor(string id, string name, double minTemp, double maxTemp) : AircraftComponent(id, name)
{
    minTemperature = minTemp;
    maxTemperature = maxTemp;
    currentTemperature = 0;
    hasReading = false;

    if (minTemperature >= maxTemperature)
    {
        throw "Invalid threshold temperatures";
    }

    cout << "Temperature sensor created!" << endl;
}

void TemperatureSensor::getReading()
{
    cout << "\nPlease enter current temperature (Celcius): ";
    cin >> currentTemperature;
    hasReading = true;
}

bool TemperatureSensor::checkReading() const
{
    if (!hasReading)
    {
        return false;
    }

    return currentTemperature >= minTemperature && currentTemperature <= maxTemperature;
}

string TemperatureSensor::getReadingDescription() const
{
    if (!hasReading)
    {
        return "No valid reading currently held";
    }
    return to_string(currentTemperature);
}
