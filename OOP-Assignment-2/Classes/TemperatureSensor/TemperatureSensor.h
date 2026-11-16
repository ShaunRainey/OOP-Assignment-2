#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <string>
#include "../AircraftComponent/AircraftComponent.h"

using namespace std;

class TemperatureSensor : public AircraftComponent
{
public:
    TemperatureSensor(string id, string name, double minTemp, double maxTemp);

    void generateReading() override;
    void healthCheck() override;
    string getReading() const override;
    void displayInfo() const override;
    double getMaxTemp() const;
    void setMaxTemp();
    double getMinTemp() const;
    void setMinTemp();


private:
    double minTemperature;
    double maxTemperature;
    double currentTemperature;
    bool hasReading;
};

#endif