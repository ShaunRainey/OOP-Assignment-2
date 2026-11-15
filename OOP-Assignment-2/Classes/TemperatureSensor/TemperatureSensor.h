#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <string>
#include "../AircraftComponent/AircraftComponent.h"

using namespace std;

class TemperatureSensor : public AircraftComponent
{
public:
    TemperatureSensor(string id, string name, double minTemp, double maxTemp);

    void getReading() override;
    bool checkReading() const override;
    string getReadingDescription() const override;

private:
    double minTemperature;
    double maxTemperature;
    double currentTemperature;
    bool hasReading;
};

#endif