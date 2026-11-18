#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include <string>
#include "../AircraftComponent/AircraftComponent.h"

using namespace std;

class PressureSensor : public AircraftComponent
{
public:
    PressureSensor(string id, string name, double minPres, double maxPres);

    void generateReading() override;
    void healthCheck() override;
    string getReading() const override;
    void displayInfo() const override;
    double getMaxPres() const;
    void setMaxPres();
    double getMinPres() const;
    void setMinPres();


private:
    double minPressure;
    double maxPressure;
    double currentPressure;
    bool hasReading;
};

#endif