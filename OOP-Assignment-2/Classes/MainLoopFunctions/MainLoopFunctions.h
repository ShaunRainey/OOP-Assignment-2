#ifndef MAINLOOPFUNCTIONS_H
#define MAINLOOPFUNCTIONS_H

#include <string>
#include "../AircraftComponent/AircraftComponent.h"

using namespace std;

class MainLoopFunctions
{
public:

	static void presentMenu()
	{
		cout << "\nPlease select an option from the menu (0 to quit program): \n";
		cout << "\n1) View all temperature sensors";
		cout << "\n2) Add new temperature sensor";
		cout << "\n3) Update temperature sensor minimum threshold value";
		cout << "\n4) Update temperature sensor maximum threshold value";
		cout << "\n0) Game over\n";
	}

	static bool validateChoice(string input)
	{
		bool isValid = false;

		try
		{
			int validifier = stoi(input);
			isValid = true;
		}

		catch (...)
		{
			cout << "\nChoice not valid, please try again.\n";
		}

		return isValid;
	}

	static void displayAllTempSensors(unordered_map<string, TemperatureSensor> temperatureSensors)
	{
		for (const auto& sensor : temperatureSensors)
		{
			sensor.second.displayInfo();
		}
	}

	static void addNewTempSensor(TemperatureSensor newSensor, unordered_map<string, TemperatureSensor>& temperatureSensors) 
	{
		if (temperatureSensors.count(newSensor.getComponentID()) == 1) {
			cout << "Component with this ID already exists.";
		}
		else
		{
			temperatureSensors.emplace(newSensor.getComponentID(), newSensor);
			cout << temperatureSensors.size();
		}
	}

	static TemperatureSensor createTempSensor()
	{
		string componentID;
		string componentName;
		double minTemperature;
		double maxTemperature;

		cout << "\nEnter component ID: ";
		cin >> componentID;

		cout << "\nEnter component name: ";
		cin >> componentName;

		cout << "\nEnter component minimum temperature: ";
		cin >> minTemperature;

		cout << "\nEnter component maximum temperature: ";
		cin >> maxTemperature;

		return TemperatureSensor(componentID, componentName, minTemperature, maxTemperature);
	}

	static void deleteTemperatureSensor(unordered_map<string, TemperatureSensor>& temperatureSensors)
	{
		string componentID;

		cout << "\nEnter the ID of the component you wish to update: ";
		cin >> componentID;

		if (temperatureSensors.count(componentID) == 1)
		{
			temperatureSensors.at(componentID).displayInfo();
			temperatureSensors.erase(componentID);

			cout << "\nComponent with ID: " << componentID << " has been deleted.\n";
		}
		else
		{
			cout << "\nComponent ID not found\n";
		}
	}
};

#endif