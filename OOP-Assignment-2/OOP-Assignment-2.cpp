#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <stdexcept>

#include "Classes/AircraftComponent/AircraftComponent.h"
#include "Classes/PressureSensor/PressureSensor.h"
#include "Classes/TemperatureSensor/TemperatureSensor.h"
#include "Classes/MainLoopFunctions/MainLoopFunctions.h"

using namespace std;

enum SensorStatus
{
    Online,
    Offline,
    Error
};

int main()
{
    bool exit = false;

    while (exit == false)
    {
        string choice;

        MainLoopFunctions::sayHello();

        MainLoopFunctions::presentMenu();
        cin >> choice;

        MainLoopFunctions::validateChoice(choice);

        if (choice == "0")
        {
            exit = true;
        }

    }
    //vector<unique_ptr<AircraftComponent>> components;

    //vector<string> cars;

    //components.push_back(make_unique<TemperatureSensor>("T001", "Temperature Sensor 1", 50, 150));
    //components.push_back(make_unique<PressureSensor>("P001", "Pressure Sensor 1", 100, 300));

    //for (const auto& component : components)
    //{
    //    cout << "\nAircraft Component Monitoring";

    //    component->getReading();
    //    component->displayInfo();
    //}

    //return 0;

    
}