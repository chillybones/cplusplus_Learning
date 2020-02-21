#pragma once


class Mortgage {

private:
	double principal, interestRate, marketValue, monthlyIncome;
	int years;

public:
	double mortgage;

	/*
		Default constructor, sets the entire mortgage class at one time.
	*/
	Mortgage(double, double, double, double, int);

	/*
		Set the entire variable set of the Mortgage class at one time.
	*/
	void SetMortgage(double, double, double, double, int);

	/*
		Calculate a simple mortgage based off of principal, interest rate, and years in the mortgage. Assumes monthly payments.
	*/
	double CalculateSimpleMortgage();

	/*
		Calculates an amorization table for a simple mortgage based off of principal, interest rate, any years in the mortgage. Assumes monthly payments.
	*/
	double CalculateSimpleAmortization();

#pragma region Gets and Sets
	void SetPrincipal(double _principal) { principal = _principal; }
	void SetInterestRate(double _interestRate) { interestRate = _interestRate; }
	void SetMarketValue(double _marketValue) { marketValue = _marketValue; }
	void SetMonthlyIncome(double _monthlyIncom) { monthlyIncome = _monthlyIncom; }
	void SetYears(int _years) { years = _years; }

	double GetPrincipal() { return principal; }
	double GetInterestRate() { return interestRate; }
	double GetMarketValue() { return marketValue; }
	double GetMonthlyIncome() { return monthlyIncome; }
	int GetYears() { return years; }
#pragma endregion

};

void SimpleMortgageCalc();

/*
	Main menu of the Mortgage program.  This will loop until the user is done with Mortgage calculation. Returns false by default, true when user exits.
*/
bool MortgageMenu();