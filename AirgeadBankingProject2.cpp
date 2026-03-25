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

void DataInput() {
	cout << setfill('*') << setw(34) << "" << endl;
	cout << setfill('*') << setw(10) << "" << " Data Input " << setw(10) << "" << endl;
}

int main() {
	int selection = 0;

	WelcomeScreen(selection);

	while (selection == 1) {
		Test();
		DataInput();
		break;
	}

	return 0;
}
