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
	cout << setw(34) << left << "Press 1 to continue. . ." << endl;
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
	cout << setw(34) << left << "Press 1 to continue. . ." << endl;
}

//outputs balance screen without additional monthly deposits
void BalanceScreenWithout(double& investment, double& monthlyDeposit, double& annualInterest, int& numOfYears) {
	vector<double> yearsVec(numOfYears);
	unsigned int i;

	for (i = 1; i < yearsVec.size(); ++i) {
		yearsVec.at(i);
	}
	
	cout << setfill(' ') << setw(4) << "" << "Balance and Interest Without Additional Monthly Deposits" << setw(5) << "" << endl;
	cout << setfill('=') << setw(65) << "" << endl;
	cout << setfill(' ') << setw(2) << "" << "Year" << "      " << "Year End Balance" << "          " << "Year End Earned Interest" << setw(5) << "" << endl;
	cout << setfill('-') << setw(65) << "" << endl;
	cout << setfill(' ') << setw(2) << "" << yearsVec.at(0) << "      " << endl;
	cout << setfill(' ') << setw(2) << "" << yearsVec.at(1) << "      " << endl;
	cout << monthlyDeposit << endl;
	cout << annualInterest << endl;
	cout << numOfYears << endl;
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
		break;
	}

	return 0;
}
