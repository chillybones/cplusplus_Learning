#include <iostream>
#include <sstream>
#include "Helper.h"

double strToDouble(const std::string& input) {
	
	double num;

	std::istringstream i(input);
	if (!(i >> num)) {
		throw std::runtime_error("This is not a number.\n");
	}

	return num;
}

int strToInt(const std::string& input) {
	int num;

	std::istringstream i(input);
	if (!(i >> num)) {
		throw std::runtime_error("This is not a number.\n");
	}

	return num;
}