#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void Test() {
	cout << "Test block" << endl;
}

void WelcomeScreen(int& selection) { //sets up the welcome screen

	cout << setfill('*') << setw(34) << "" << endl;
	cout << setfill('*') << setw(12) << "" << " Welcome! " << setw(12) << "" << endl;
	cout << "To start the program, please enter" << endl << "1. To quit, please enter 2." << endl;
	cout << ">>";

	cin >> selection;
}

void DataInputScreen() { //setting up basic data input screen for user
	cout << setfill('*') << setw(34) << "" << endl;
	cout << setfill('*') << setw(11) << "" << " Data Input " << setw(11) << "" << endl;
	cout << setfill(' ') << setw(34) << left << "Initial Investment Amount: " << endl;
	cout << setw(34) << left << "Monthly Deposit: " << endl;
	cout << setw(34) << left << "Annual Interest: " << endl;
	cout << setw(34) << left << "Number of Years: " << endl;
}

//outputs user input requests for the data screen
void DataInput(double& investment, double& monthlyDeposit, double& annualInterest, int& numOfYears) {

	cout << "Please enter the starting amount of your investment: " << endl;
	cout << ">>";
	cin >> investment;
	cout << "Please enter your monthly deposit amount: " << endl;
	cout << ">>";
	cin >> monthlyDeposit;
	cout << "Please enter the annual interest amount: " << endl;
	cout << ">>";
	cin >> annualInterest;
	cout << "Please enter the number of years for the investment: " << endl;
	cout << ">>";
	cin >> numOfYears;

	//outputs user inputs
	cout << setfill('*') << setw(34) << "" << endl;
	cout << setfill('*') << setw(11) << "" << " Data Input " << setw(11) << "" << endl;
	cout << setfill(' ') << "Initial Investment Amount:  " << "$" << investment << endl;
	cout << "Monthly Deposit:  " << "$" << monthlyDeposit << endl;
	cout << "Annual Interest:  " << annualInterest << "%" << endl;
	cout << "Number of Years:  " << numOfYears << endl;
}

//outputs balance screen without additional monthly deposits
void BalanceScreenWithout(double& investment, double& monthlyDeposit, double& annualInterest, int& numOfYears) {
	double currentBalance = investment;
	double yearlyInterest;
	
	//print headers
	cout << endl;
	cout << setfill('=') << setw(65) << "" << endl;
	cout << setfill(' ') << setw(4) << "" << "Balance and Interest Without Additional Monthly Deposits" << setw(5) << "" << endl;
	cout << setfill('=') << setw(65) << "" << endl;
	cout << setfill(' ') << setw(2) << "" << "Year" << "      " << "Year End Balance" << "          " << "Year End Earned Interest" << setw(5) << "" << endl;
	cout << setfill('-') << setw(65) << "" << endl;

	cout << fixed << setprecision(2); //for currency output

	//iterate through each year
	for (int i = 1; i <= numOfYears; ++i) {
		yearlyInterest = currentBalance * (annualInterest / 100.0);
		currentBalance = currentBalance + yearlyInterest;

		//output w/ alignment
		cout << setfill(' ') << "  " << i
			<< "         " << "$" << currentBalance
			<< "                   " << "$" << yearlyInterest << endl;
	}
}

//for outputting balance screen with monthly additions
void BalanceScreenWith(double& investment, double& monthlyDeposit, double& annualInterest, int& numOfYears) {
	double currentBalance = investment;
	double monthlyInterestRate = (annualInterest / 100.0) / 12.0;

	//print headers
	cout << endl;
	cout << setfill('=') << setw(65) << "" << endl;
	cout << setfill(' ') << setw(4) << "" << "Balance and Interest With Additional Monthly Deposits" << setw(5) << "" << endl;
	cout << setfill('=') << setw(65) << "" << endl;
	cout << setfill(' ') << setw(2) << "" << "Year" << "      " << "Year End Balance" << "          " << "Year End Earned Interest" << setw(5) << "" << endl;
	cout << setfill('-') << setw(65) << "" << endl;

	cout << fixed << setprecision(2); //for currency output

	//iterate through each year
	for (int i = 1; i <= numOfYears; ++i) {
		double yearlyInterestEarned = 0; //need to reset for each new year

		for (int j = 1; j <= 12; ++j) {
			//add monthly deposit
			currentBalance += monthlyDeposit; 
			//calculate interest for current month
			double monthlyInterest = currentBalance * monthlyInterestRate; 
			//add to running yearly total and whole balance
			yearlyInterestEarned += monthlyInterest;
			currentBalance += monthlyInterest;
		}

		//output after full year
		cout << setfill(' ') << "  " << i
			<< "         " << "$" << currentBalance
			<< "                   " << "$" << yearlyInterestEarned << endl;
	}
}

int main() {
	int selection = 0;
	double investment;
	double monthlyDeposit;
	double annualInterest;
	int numOfYears;

	WelcomeScreen(selection);

	while (selection == 1) {
		DataInputScreen();
		DataInput(investment, monthlyDeposit, annualInterest, numOfYears);
		BalanceScreenWithout(investment, monthlyDeposit, annualInterest, numOfYears);
		BalanceScreenWith(investment, monthlyDeposit, annualInterest, numOfYears);
		break;
	}

	return 0;
}
