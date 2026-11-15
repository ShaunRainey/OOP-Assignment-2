#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
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

    //vector<unique_ptr<AircraftComponent>> components;

    //components.push_back(make_unique<TemperatureSensor>("T001", "Temperature Sensor 1", 50, 150));
    //components.push_back(make_unique<PressureSensor>("P001", "Pressure Sensor 1", 100, 300));

    unordered_map<string, unique_ptr<AircraftComponent>> components;

    components["T001"] = make_unique<TemperatureSensor>("T001", "Temperature Sensor 1", 50, 150);
    //components["P001"] = make_unique<PressureSensor>("P001", "Pressure Sensor 1", 0, 200);

    while (exit == false)
    {
        string choice;

        MainLoopFunctions::presentMenu();
        cin >> choice;

        MainLoopFunctions::validateChoice(choice);

        if (choice == "0")
        {
            exit = true;
        }

        int intChoice = stoi(choice);

        switch (intChoice)
        {
            case 1:
                MainLoopFunctions::sayHello();
                break;
            case 2:
                //MainLoopFunctions::viewVectorEntry(components[0]);
                //MainLoopFunctions::viewVectorEntry(components[1]);
                MainLoopFunctions::viewComponent(components["T001"]);
                break;
            case 3:
                //do some stuff
                break;
        }



    }



    //return 0;

    
}