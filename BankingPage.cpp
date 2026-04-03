#include <iostream>
#include <iomanip>
#include "Investment.h"
using namespace std;

int main() {
	Investment myAccount; //constructor
	int selection = 0;

	//sets up intro to program
	cout << setfill('*') << setw(36) << "" << endl;
	cout << setfill('*') << setw(13) << "" << " Welcome! " << setw(13) << "" << endl;
	cout << "This program calculates interest based" << endl << "on user input values." << endl;
	cout << "To start the program, please enter 1." << endl << "To quit the program, please enter 2." << endl;
	cout << ">>";
	cin >> selection;

	//while loop that runs program while user selects "continue"
	while (selection == 1) {
		myAccount.promptForData();
		myAccount.displayWithoutDeposits();
		myAccount.displayWithDeposits();
		
		cout << "Press 1 to continue with new amounts or 2 to quit." << endl;
		cin >> selection;
	}
	cout << "Quitting program. . ." << endl;

	return 0;
}
