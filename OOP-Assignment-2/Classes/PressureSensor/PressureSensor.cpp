#include "PressureSensor.h"
#include <iostream>


#include "../AircraftComponent/AircraftComponent.h"

using namespace std;

PressureSensor::PressureSensor(string id, string name, double minPres, double maxPres) : AircraftComponent(id, name)
{
    minPressure = minPres;
    maxPressure = maxPres;
    currentPressure = 20;
    hasReading = true;

    if (minPressure >= maxPressure)
    {
        throw "\nInvalid threshold pressures\n";
    }

    cout << "\nPressure sensor created!\n";
}

void PressureSensor::generateReading()
{
    double number;

    cout << "\nPlease enter current pressure: ";

    while (!(cin >> number))
    {
        cout << "\nInvalid input type, please try again\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (number > minPressure && number < maxPressure)
    {
        currentPressure = number;
        hasReading = true;
    }
    else
    {
        cout << "Value is beyond permissable thresholds";
    }
}

void PressureSensor::healthCheck()
{
    if (!hasReading)
    {
        cout << "\nNo reading currently present.\n";
        return;
    }

    if (currentPressure > minPressure && currentPressure < maxPressure)
    {
        setFunctioning("Healthy");
    }
    else if (currentPressure < minPressure)
    {
        cout << "WARNING: Current pressure is beneath minimum threshold!";
        setFunctioning("Min threshold breached");
    }
    else
    {
        cout << "WARNING: Current pressure is above maximum threshold!";
        setFunctioning("Max threshold breached");
    }
}

string PressureSensor::getReading() const
{
    if (!hasReading)
    {
        return "\nNo valid reading currently held\n";
    }
    return to_string(currentPressure);
}

double PressureSensor::getMaxPres() const
{
    return maxPressure;
}

void PressureSensor::setMaxPres()
{
    double newPres;

    cout << "\nPlease enter new maximum pressure threshold (Celcius): ";

    while (!(cin >> newPres))
    {
        cout << "\nInvalid input type, please try again\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (newPres > minPressure && newPres > currentPressure)
    {
        maxPressure = newPres;
        cout << "\nMaximum pressure successfully updated.\n";
    }
    else if (newPres < currentPressure)
    {
        cout << "\nNew maximum pressure cannot be less than the current pressure reading.\n";
    }
    else
    {
        cout << "\nMaximum pressure cannot be lower than the minimum permitted pressure.\n";
    }
}

double PressureSensor::getMinPres() const
{
    return minPressure;
}

void PressureSensor::setMinPres()
{
    double newPres;

    cout << "\nPlease enter new minimum pressure threshold (Celcius): ";

    while (!(cin >> newPres))
    {
        cout << "\nInvalid input type, please try again\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (newPres < maxPressure && newPres < currentPressure)
    {
        minPressure = newPres;
        cout << "\nMinimum pressure successfully updated.\n";
    }
    else if (newPres > currentPressure)
    {
        cout << "\nNew minimum pressure cannot be greater than the current pressure reading.\n";
    }
    else
    {
        cout << "\nMinimum pressure cannot be higher than the max permitted pressure.\n";
    }
}

void PressureSensor::displayInfo() const
{
    cout << "\nComponent ID: " << getComponentID();
    cout << "\nComponentName: " << getComponentName();
    cout << "\nHealth status: " << healthStatus();
    cout << "\nCurrent reading: " << getReading();
    cout << "\nMin permitted pressure:" << getMinPres();
    cout << "\nMax permitted pressure:" << getMaxPres() << "\n";
}