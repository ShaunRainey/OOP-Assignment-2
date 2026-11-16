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

    unordered_map<string, TemperatureSensor> tempSensors;
    tempSensors.emplace("T001", TemperatureSensor("T001", "Temperature Sensor 1", 20, 170));

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
        string componentID;

        switch (intChoice)
        {
            case 1:
                MainLoopFunctions::displayAllTempSensors(tempSensors);
                break;

            case 2:
            {
                TemperatureSensor newSensor = MainLoopFunctions::createTempSensor();
                MainLoopFunctions::addNewTempSensor(newSensor, tempSensors);
                break;
            }

            case 3:
                cout << "Enter the ID of the component you wish to update: ";
                cin >> componentID;

                if (tempSensors.count(componentID) == 1)
                {
                    tempSensors.at(componentID).displayInfo();
                    tempSensors.at(componentID).setMinTemp();
                }
                else
                {
                    cout << "\nComponent ID not found.\n" << endl;
                }
                break;

            case 4:
                cout << "Enter the ID of the component you wish to update: ";
                cin >> componentID;

                if (tempSensors.count(componentID) == 1)
                {
                    tempSensors.at(componentID).displayInfo();
                    tempSensors.at(componentID).setMaxTemp();
                }
                else
                {
                    cout << "\nComponent ID not found.\n" << endl;
                }
                break;

            case 5:
                MainLoopFunctions::deleteTemperatureSensor(tempSensors);
                break;
        }
    }



    //return 0;

    
}