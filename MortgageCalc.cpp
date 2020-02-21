#include <iostream>
#include <cmath>
#include "MortgageCalc.h"
#include "Helper.h"

bool MortgageMenu() {

	std::string s_sel, input;
	int sel = 0, years = 0;
	double principal, interestRate;
	bool success = false;

	std::cout << "\n\nLet's build a mortgage.\nPlease enter...\nPrincipal: ";

	// Loop until a valid number has been found.
	while (success == false) {
		try {
			std::cin >> input;
			principal = strToDouble(input);
			success = true;
		}
		catch (std::exception e) {
			std::cout << e.what();
			std::cout << "Principal: ";
			success = false;
		}
	}

	// Reset the success flag to deal with next input
	success = false;
	while (success == false) {
		try {
			std::cout << "\nInterest Rate: ";
			std::cin >> input;
			interestRate = strToDouble(input);
			success = true;
		}
		catch (std::exception e) {
			std::cout << e.what() << "\n";
			success = false;
		}
	}

	// AGAIN - moving to an INT, however.
	success = false;
	while (success == false)
	{
		try {
			std::cout << "\nYears: ";
			std::cin >> input;
			years = strToInt(input);
			success = true;
		}
		catch (std::exception e) {
			std::cout << e.what() << "\n";
			success = false;
		}
	}

	// Mortgage!
	Mortgage m(principal, interestRate, NULL, NULL, years);

	// Begin loop of mortgage.
	while (true) {
		std::cout << "\n\n\n\n==Mortgage Menu==\nCurrent Mortgage:\n" << "Principal: " << principal << "\nInterest Rate: " << interestRate << "\nYears: " << years << std::endl;
		std::cout << "Select what you would like to do.\n";
		std::cout << "1. Change Mortgage Amounts\n2. Run a Simple Mortgage Calculation\n3. Run a Simple Amortization\n";

		success = false;
		while (success == false) {
			try {
				std::cout << ": ";
				std::cin >> s_sel;
				sel = strToInt(s_sel);
				success = true;
			}
			catch (std::exception e) {
				std::cout << "\n" << e.what() << "\n";
				success = false;
			}
		}

		// Successful cases, except for exit, should return false to keep in the loop.
		switch (sel)
		{
		case 1:
			break;
		case 2:
			std::cout << "Monthly Payment: " << m.CalculateSimpleMortgage();
			break;
		case 3:
			m.CalculateSimpleAmortization();
			break;
		default:
			break;
		}
	}
}

Mortgage::Mortgage(double _principal, double _interestRate, double _marketValue, double _monthlyIncome, int _years) {
	SetMortgage(_principal, _interestRate, _marketValue, _monthlyIncome, _years);
}

void Mortgage::SetMortgage(double _principal, double _interestRate, double _marketValue, double _monthlyIncome, int _years) {
	principal = _principal;
	interestRate = _interestRate;
	marketValue = _marketValue;
	monthlyIncome = _monthlyIncome;
	years = _years;
}

double Mortgage::CalculateSimpleMortgage() {

	double tot_monthlyPayments = 12.00 * years;
	double periodic_interest = (interestRate/100) / 12.00;
	double discount_factor = (std::pow(1.00 + periodic_interest, tot_monthlyPayments) - 1.00) / (periodic_interest * std::pow(1.00 + periodic_interest, tot_monthlyPayments));

	double mortgage_payment = principal / discount_factor;

	return mortgage_payment;
}

double Mortgage::CalculateSimpleAmortization() {
	double monthly_payment = CalculateSimpleMortgage();
	double tot_monthlyPayments = 12.00 * years;
	double periodic_interest_rate = (interestRate / 100) / 12.00;
	double periodic_interest, periodic_principal;
	double startingPrincipal = principal;
	double remainingPrincipal = principal;

	std::cout << "Period\tStart\tMonthly\tInterest\tPrincipal\tLeft\n";

	for (int i = 0; i < tot_monthlyPayments; i++) {
		startingPrincipal = remainingPrincipal;
		periodic_interest = remainingPrincipal * periodic_interest_rate;
		periodic_principal = monthly_payment - periodic_interest;
		remainingPrincipal = startingPrincipal - periodic_principal;

		std::cout << i + 1 << "\t" << startingPrincipal << "\t" << monthly_payment << "\t" << periodic_interest << "\t\t" << periodic_principal << "\t\t" << remainingPrincipal << "\n";
	}
	return monthly_payment;
}
