#ifndef MAINLOOPFUNCTIONS_H
#define MAINLOOPFUNCTIONS_H

#include <string>
#include "../AircraftComponent/AircraftComponent.h"

using namespace std;

class MainLoopFunctions
{
public:

	static void sayHello()
	{
		cout << "\n Hello" << endl;
	};

	static void presentMenu()
	{
		cout << "\nPlease select an option from the menu (0 to quit program): " << endl;
		cout << "1) A" << endl;
		cout << "2) B" << endl;
		cout << "3) C" << endl;
		cout << "0) Game over" << endl;
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
			cout << "\nChoice not valid, please try again." << endl;
		}

		return isValid;
	}

	static void viewComponent(const unique_ptr<AircraftComponent>& component)
	{
		component->displayInfo();
	}



};

#endif