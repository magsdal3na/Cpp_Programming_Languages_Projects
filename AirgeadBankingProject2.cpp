#include <iostream>
#include <iomanip>
#include <vector> //might not be needed

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
	cout << setw(34) << left << "Press 1 to continue. . ." << endl;
}

void DataInput() {
	double investment;
	double monthlyDeposit;
	double annualInterest;
	int numOfYears;

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

	cout << setfill('*') << setw(34) << "" << endl;
	cout << setfill('*') << setw(11) << "" << " Data Input " << setw(11) << "" << endl;
	cout << setfill(' ') << "Initial Investment Amount:  " << "$" << investment << endl;
	cout << "Monthly Deposit:  " << "$" << monthlyDeposit << endl;
	cout << "Annual Interest:  " << annualInterest << "%" << endl;
	cout << "Number of Years:  " << numOfYears << endl;
	cout << setw(34) << left << "Press 1 to continue. . ." << endl;
}

void BalanceScreenWithout() {
	cout << setfill(' ') << setw(4) << "" << "Balance and Interest Without Additional Monthly Deposits" << setw(5) << "" << endl;
	cout << setfill('=') << setw(65) << "" << endl;
}

int main() {
	int selection = 0;

	WelcomeScreen(selection);

	while (selection == 1) {
		DataInputScreen();
		//DataInput();
		BalanceScreenWithout();
		break;
	}

	return 0;
}
