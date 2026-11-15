#include "TemperatureSensor.h"
#include <iostream>

#include "../AircraftComponent/AircraftComponent.h"

using namespace std;

TemperatureSensor::TemperatureSensor(string id, string name, double minTemp, double maxTemp) : AircraftComponent(id, name)
{
    minTemperature = minTemp;
    maxTemperature = maxTemp;
    currentTemperature = 20;
    hasReading = true;

    if (minTemperature >= maxTemperature)
    {
        throw "Invalid threshold temperatures";
    }

    cout << "Temperature sensor created!" << endl;
}

void TemperatureSensor::generateReading()
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

string TemperatureSensor::getReading() const
{
    if (!hasReading)
    {
        return "No valid reading currently held";
    }
    return to_string(currentTemperature);
}

double TemperatureSensor::getMaxTemp() const
{
    return maxTemperature;
}

double TemperatureSensor::getMinTemp() const
{
    return minTemperature;
}

void TemperatureSensor::setMinTemp()
{
    double newTemp;
    cout << "Enter a new value: ";
    cin >> newTemp;

    if (newTemp > maxTemperature) {
        cout << "\nMinimum temperature cannot be higher than the max permitted temperature.\n";
    }
    else
    {
        minTemperature = newTemp;
    }
}

void TemperatureSensor::displayInfo() const
{
    cout << "\nComponent ID: " << getComponentID();
    cout << "\nComponentName: " << getComponentName();
    cout << "\nHealth status: " << healthStatus();
    cout << "\nCurrent reading: " << getReading();
    cout << "\nMax permitted temperature:" << getMaxTemp();
    cout << "\nMin permitted temperature:" << getMinTemp() << "\n";
}