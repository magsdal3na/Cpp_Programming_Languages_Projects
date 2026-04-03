#ifndef INVESTMENT_H_
#define INVESTMENT_H_

class Investment {
public:
	//constructor information
	Investment() {
		initialInvestment = 0.0;
		monthlyDeposit = 0.0;
		annualInterest = 0.0;
		numOfYears = 0;
	}

	//input
	void promptForData() {
		cout << "Initial Investment Amount: " << endl;
		cin >> initialInvestment;
		cout << "Monthly Deposit: " << endl;
		cin >> monthlyDeposit;
		cout << "Annual Interest: " << endl;
		cin >> annualInterest;
		cout << "Number of Years: " << endl;
		cin >> numOfYears;
	}

	//displayed to user
	void displayInputData() {
		cout << "Initial Investment: $" << initialInvestment << endl;
		cout << "Monthly Deposit: $" << monthlyDeposit << endl;
		cout << "Annual Interest: " << annualInterest << endl;
		cout << "Years: " << numOfYears << endl;
	}

private:
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numOfYears;
};

#endif
