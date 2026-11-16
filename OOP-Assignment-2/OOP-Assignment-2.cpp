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
                MainLoopFunctions::clearScreen();
                break;

            case 2:
            {
                TemperatureSensor newSensor = MainLoopFunctions::createTempSensor();
                MainLoopFunctions::addNewTempSensor(newSensor, tempSensors);
                MainLoopFunctions::clearScreen();
                break;
            }

            case 3:
                cout << "Enter the ID of the component you wish to update: ";
                cin >> componentID;

                if (tempSensors.count(componentID) == 1)
                {
                    tempSensors.at(componentID).displayInfo();
                    tempSensors.at(componentID).setMinTemp();
                    tempSensors.at(componentID).healthCheck();
                }
                else
                {
                    cout << "\nComponent ID not found.\n" << endl;
                }
                MainLoopFunctions::clearScreen();
                break;

            case 4:
                cout << "Enter the ID of the component you wish to update: ";
                cin >> componentID;

                if (tempSensors.count(componentID) == 1)
                {
                    tempSensors.at(componentID).displayInfo();
                    tempSensors.at(componentID).setMaxTemp();
                    tempSensors.at(componentID).healthCheck();
                }
                else
                {
                    cout << "\nComponent ID not found.\n" << endl;
                }
                MainLoopFunctions::clearScreen();
                break;

            case 5:
                cout << "Enter the ID of the component you wish to update: ";
                cin >> componentID;

                if (tempSensors.count(componentID) == 1)
                {
                    tempSensors.at(componentID).displayInfo();
                    tempSensors.at(componentID).generateReading();
                    tempSensors.at(componentID).healthCheck();
                }
                else
                {
                    cout << "\nComponent ID not found.\n" << endl;
                }
                MainLoopFunctions::clearScreen();
                break;

            case 6:
                MainLoopFunctions::deleteTemperatureSensor(tempSensors);
                MainLoopFunctions::clearScreen();
                break;
        }
    }



    //return 0;

    
}