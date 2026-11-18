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
    double number; 

    cout << "\nPlease enter current temperature (Celcius): ";

    while (!(cin >> number))
    {
        cout << "\nInvalid input type, please try again\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (number > minTemperature && number < maxTemperature)
    {
        currentTemperature = number;
        hasReading = true;
    }
    else
    {
        cout << "Value is beyond permissable thresholds";
    }
}

void TemperatureSensor::healthCheck()
{
    if (!hasReading)
    {
        cout << "\nNo reading currently present.\n";
        return;
    }

    if (currentTemperature > minTemperature && currentTemperature < maxTemperature) 
    {
        setFunctioning("Healthy");
    }
    else if (currentTemperature < minTemperature)
    {
        cout << "WARNING: Current temperature is beneath minimum threshold!";
        setFunctioning("Min threshold breached");
    }
    else
    {
        cout << "WARNING: Current temperature is above maximum threshold!";
        setFunctioning("Max threshold breached");
    }
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

    cout << "\nPlease enter new maximum temperature threshold (Celcius): ";

    while (!(cin >> newTemp))
    {
        cout << "\nInvalid input type, please try again\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

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

    cout << "\nPlease enter new minimum temperature threshold (Celcius): ";

    while (!(cin >> newTemp))
    {
        cout << "\nInvalid input type, please try again\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (newTemp < maxTemperature && newTemp < currentTemperature) 
    {
        minTemperature = newTemp;
        cout << "\nMinimum temperature successfully updated.\n";
    }
    else if (newTemp > currentTemperature) 
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
    cout << "\nMin permitted temperature:" << getMinTemp();
    cout << "\nMax permitted temperature:" << getMaxTemp() << "\n";
}