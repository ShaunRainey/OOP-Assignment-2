#ifndef MAINLOOPFUNCTIONS_H
#define MAINLOOPFUNCTIONS_H

#include <string>
#include "../AircraftComponent/AircraftComponent.h"
#include <conio.h>
#include <optional>

using namespace std;

class MainLoopFunctions
{
public:

	static void presentSensorMenu()
	{
		cout << "\nPlease select an option from the menu (0 to quit program): \n";
		cout << "\n0. Exit program\n";
		cout << "\n1. Temperature sensors";
		cout << "\n2. Pressure sensors";
		cout << "\n";
	}

	static void presentMainMenu()
	{
		cout << "\nPlease select an option from the menu (0 to quit program): \n";
		cout << "\n0. Exit program\n";
		cout << "\n1. View all sensors";
		cout << "\n2. Add new sensor";
		cout << "\n3. Update sensor minimum threshold value";
		cout << "\n4. Update sensor maximum threshold value";
		cout << "\n5. Update reading";
		cout << "\n6. Delete sensor";
		cout << "\n";
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
			cout << "\nInvalid choice. Please enter a number: \n";
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

	static optional<TemperatureSensor> createTempSensor()
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
		while (!(cin >> minTemperature))
		{
			cout << "\nInvalid input. Please enter a numerical value: ";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		cout << "\nEnter component maximum temperature: ";
		while (!(cin >> maxTemperature))
		{
			cout << "\nInvalid input. Please enter a numerical value: ";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		if (minTemperature >= maxTemperature)
		{
			cout << "\nInvalid temperature thresholds. Sensor creation cancelled.\n";
			return nullopt;
		}

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

	static void clearScreen()
	{
		cout << "\nPress any key to continue...";
		_getch();

		system("cls");
	}
};

#endif