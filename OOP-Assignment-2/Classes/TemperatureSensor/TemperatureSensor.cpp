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
        throw "\nInvalid threshold temperatures\n";
    }

    cout << "\nTemperature sensor created!\n";
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
        return "\nNo valid reading currently held\n";
    }
    return to_string(currentTemperature);
}

double TemperatureSensor::getMaxTemp() const
{
    return maxTemperature;
}

void TemperatureSensor::setMaxTemp()
{
    double newTemp;
    cout << "\nEnter a new value: ";
    cin >> newTemp;

    if (newTemp > minTemperature && newTemp > currentTemperature)
    {
        maxTemperature = newTemp;
        cout << "\nMaximum temperature successfully updated.\n";
    }
    else if (newTemp < currentTemperature)
    {
        cout << "\nNew maximum temperature cannot be less than the current temperature reading.\n";
    }
    else
    {
        cout << "\nMaximum temperature cannot be lower than the minimum permitted temperature.\n";
    }
}

double TemperatureSensor::getMinTemp() const
{
    return minTemperature;
}

void TemperatureSensor::setMinTemp()
{
    double newTemp;
    cout << "\nEnter a new value: ";
    cin >> newTemp;

    if (newTemp < maxTemperature && newTemp < currentTemperature) 
    {
        minTemperature = newTemp;
        cout << "\nMinimum temperature successfully updated.\n";
    }
    else if (newTemp < currentTemperature) 
    {
        cout << "\nNew minimum temperature cannot be greater than the current temperature reading.\n";
    }
    else
    {
        cout << "\nMinimum temperature cannot be higher than the max permitted temperature.\n";
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