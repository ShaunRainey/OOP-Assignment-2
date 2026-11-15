#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include <string>
#include "../AircraftComponent/AircraftComponent.h"

using namespace std;

class PressureSensor : public AircraftComponent
{
public:
    PressureSensor(string id, string name, double minPres, double maxPres);

    void getReading() override;
    bool checkReading() const override;
    string getReadingDescription() const override;

private:
    double minPressure;
    double maxPressure;
    double currentPressure;
    bool hasReading;
};

#endif