#ifndef MAINLOOPFUNCTIONS_H
#define MAINLOOPFUNCTIONS_H

#include <string>

using namespace std;

class MainLoopFunctions
{
public:

	static void sayHello()
	{
		cout << "Hello" << endl;
	};

	static void presentMenu()
	{
		cout << "Please select an option from the menu (0 to quit program): " << endl;
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
			cout << "Choice not valid, please try again." << endl;
		}

		return isValid;
	}
};

#endif