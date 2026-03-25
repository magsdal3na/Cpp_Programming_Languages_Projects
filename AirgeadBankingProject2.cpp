#include <iostream>
#include <iomanip>
#include <vector> //might not be needed

using namespace std;

void Test() {
	cout << "Test block" << endl;
}

void WelcomeScreen() { //sets up the welcome screen
	int selection;

	cout << setfill('*') << setw(34) << "" << endl;
	cout << setfill('*') << setw(12) << "" << " Welcome! " << setw(12) << "" << endl;
	cout << "To start the program, please enter" << endl << "1. To quit, please enter 2." << endl;
	cout << ">>";

	cin >> selection;
}

int main() {
	int selection = 0;

	WelcomeScreen();

	while (selection == 1) {
		Test();
		break;
	}

	return 0;
}
