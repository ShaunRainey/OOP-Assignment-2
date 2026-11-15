#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <stdexcept>

using namespace std;

enum SensorStatus
{
    Online,
    Offline,
    Error
};

class AircraftComponent
{
private:
    string componentID;
    string componentName;
    bool isOnline;
    bool needsMaintenance;

public:
    AircraftComponent(string id, string name)
    {
        componentID = id;
        componentName = name;
        isOnline = true;
        needsMaintenance = false;
    }

    virtual ~AircraftComponent() = default;

    string getComponentID()
    {
        return componentID;
    }

    string getComponentName()
    {
        return componentName;
    }

    void setFunctioning(SensorStatus status)
    {
        isOnline = status;
    }

    void setNeedsMaintenance(bool required)
    {
        needsMaintenance = required;
    }

    virtual void getReading() = 0;
    virtual bool checkReading() const = 0;
    virtual string getReadingDescription() const = 0;

    string healthStatus() const
    {
        if (!isOnline)
        {
            //return SensorStatus::Offline;
            return "Offline";
        }

        if (needsMaintenance)
        {
            return "Needs Maintenance";
        }

        return "Healthy";
    }

    void displayInfo() const
    {
        cout << "Component ID: " << componentID << endl;
        cout << "ComponentName: " << componentName << endl;
        cout << "Health status: " << healthStatus() << endl;
        cout << "Reading: " << getReadingDescription() << ": " << checkReading() << endl;
    }
};

class TemperatureSensor : public AircraftComponent
{
private:
    double minTemperature;
    double maxTemperature;
    double currentTemp;
    bool hasReading;

public:
    TemperatureSensor(string id, string name, double minTemp, double maxTemp) : AircraftComponent(id, name)
    {
        minTemperature = minTemp;
        maxTemperature = maxTemp;
        currentTemp = 0;
        hasReading = false;

        if (minTemperature >= maxTemperature)
        {
            throw "Invalid threshold temperatures";
        }

        cout << "Temperature sensor created!" << endl;
    }

    void getReading() override
    {
        cout << "\nPlease enter current temperature (Celcius): ";
        cin >> currentTemp;
        hasReading = true;
    }

    bool checkReading() const override
    {
        if (!hasReading)
        {
            return false;
        }

        return currentTemp >= minTemperature && currentTemp <= maxTemperature;
    }

    string getReadingDescription() const override
    {
        if (!hasReading)
        {
            return "No valid reading currently held";
        }

        return to_string(currentTemp);
    }
};

class PressureSensor : public AircraftComponent
{
private:
    double minPressure;
    double maxPressure;
    double currentPressure;
    bool hasReading;

public:
    PressureSensor(string id, string name, double minPres, double maxPres) : AircraftComponent(id, name)
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

    void getReading() override
    {
        cout << "\nPlease enter current pressure: ";
        cin >> currentPressure;
        hasReading = true;
    }

    bool checkReading() const override
    {
        if (!hasReading)
        {
            return false;
        }

        return currentPressure >= minPressure && currentPressure <= maxPressure;
    }

    string getReadingDescription() const override
    {
        if (!hasReading)
        {
            return "No valid reading currently held";
        }
        return to_string(currentPressure);
    }
};

int main()
{
    bool exit = false;

    vector<unique_ptr<AircraftComponent>> components;

    vector<string> cars;

    components.push_back(make_unique<TemperatureSensor>("T001", "Temperature Sensor 1", 50, 150));
    components.push_back(make_unique<PressureSensor>("P001", "Pressure Sensor 1", 100, 300));

    for (const auto& component : components)
    {
        cout << "\nAircraft Component Monitoring";

        component->getReading();
        component->displayInfo();
    }

    return 0;
}