// StarterProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MortgageCalc.h"
#include "Helper.h"

void controller(int);

int main()
{
	std::string s_sel;
	int sel;
	bool sel_success = false;

    std::cout << "==Starter Projects Collection.==\n\nSelect a Project to Run:\n";
    std::cout << "1.\tCost to Tile Floor\n2\tMortgage Calculator\n\n: ";


	while (sel_success == false) {
		try {
			std::cin >> s_sel;
			sel = strToInt(s_sel);
			sel_success = true;
		}
		catch (std::exception e) {
			std::cout << e.what() << "\n";
			sel_success = false;
			std::cout << ": ";
		}
	}

	controller(sel);
}

void controller(int sel) {
	switch (sel)
	{

	case 1:
		break;

	case 2:
		// Loop through the app for unlimited calcs.
		MortgageMenu();
		break;

	default:
		break;

	}
}