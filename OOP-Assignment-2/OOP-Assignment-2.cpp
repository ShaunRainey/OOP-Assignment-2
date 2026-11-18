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
    tempSensors.emplace("T001", TemperatureSensor("T001", "Temperature Sensor 1", 10, 170));

    unordered_map<string, PressureSensor> presSensors;
    presSensors.emplace("P001", PressureSensor("P001", "Pressure Sensor 1", 10, 170));

    while (exit == false)
    {
        string choice;
        string sensorChoice;

        MainLoopFunctions::presentSensorMenu();
        cout << "\n";
        cin >> sensorChoice;

        if (sensorChoice == "0") 
        {
            exit = true;
        }
        else if (sensorChoice == "1") 
        {
            MainLoopFunctions::presentMainMenu();
            cout << "\n";
            cin >> choice;

            while (!MainLoopFunctions::validateChoice(choice))
            {
                cin >> choice;
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
                    optional<TemperatureSensor> newSensor = MainLoopFunctions::createTempSensor();

                    if (!newSensor.has_value())
                    {
                        break;
                    }

                    MainLoopFunctions::addNewTempSensor(newSensor.value(), tempSensors);
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

                default:
                    cout << "\nReturning to start menu\n";
                    MainLoopFunctions::clearScreen();
            }
        } 
        else if (sensorChoice == "2")
        {
            MainLoopFunctions::presentMainMenu();
            cout << "\n";
            cin >> choice;

            while (!MainLoopFunctions::validateChoice(choice))
            {
                cin >> choice;
            }

            int intChoice = stoi(choice);
            string componentID;

            switch (intChoice)
            {
            case 1:
                MainLoopFunctions::displayAllPresSensors(presSensors);
                MainLoopFunctions::clearScreen();
                break;

            case 2:
            {
                optional<PressureSensor> newSensor = MainLoopFunctions::createPresSensor();

                if (!newSensor.has_value())
                {
                    break;
                }

                MainLoopFunctions::addNewPresSensor(newSensor.value(), presSensors);
                MainLoopFunctions::clearScreen();
                break;
            }

            case 3:
                cout << "Enter the ID of the component you wish to update: ";
                cin >> componentID;

                if (presSensors.count(componentID) == 1)
                {
                    presSensors.at(componentID).displayInfo();
                    presSensors.at(componentID).setMinPres();
                    presSensors.at(componentID).healthCheck();
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

                if (presSensors.count(componentID) == 1)
                {
                    presSensors.at(componentID).displayInfo();
                    presSensors.at(componentID).setMaxPres();
                    presSensors.at(componentID).healthCheck();
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

                if (presSensors.count(componentID) == 1)
                {
                    presSensors.at(componentID).displayInfo();
                    presSensors.at(componentID).generateReading();
                    presSensors.at(componentID).healthCheck();
                }
                else
                {
                    cout << "\nComponent ID not found.\n" << endl;
                }
                MainLoopFunctions::clearScreen();
                break;

            case 6:
                MainLoopFunctions::deletePressureSensor(presSensors);
                MainLoopFunctions::clearScreen();
                break;

            default:
                cout << "\nReturning to start menu\n";
                MainLoopFunctions::clearScreen();
            }
        }
        else
        {
            cout << "\nInvalid choice, please try again\n";
            MainLoopFunctions::clearScreen();
        }
    } 
}