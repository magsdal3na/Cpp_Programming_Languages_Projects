#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	double hour;
	double minutes;
	double seconds;
	int selection = 4;

	//int hourClock24;
	//int minutesClock24;
	//int secondsClock24;

	cout << "Please enter the current time in hours, minutes, and seconds: " << endl;

	cin >> hour;
	cin >> minutes;
	cin >> seconds;

	cout << "*************************" << "   " << "*************************" << endl;
	cout << "Current time: " << setw(2) << setfill('0') << hour << ":";
	cout << setw(2) << setfill('0') << minutes << ":";
	cout << setw(2) << setfill('0') << seconds << endl;
	cout << "*************************" << "   " << "*************************" << endl;

	while (selection == 4) {
		cout << setfill(' ') << "Please select 1 - 4: " << endl;
		cout << "*************************" << endl;
		cout << setw(13) << left << "* 1 - Add One Hour" << setw(7) << right << "*" << endl;
		cout << setw(13) << left << "* 2 - Add One Minute" << setw(5) << right << "*" << endl;
		cout << setw(13) << left << "* 3 - Add One Second" << setw(5) << right << "*" << endl;
		cout << setw(13) << left << "* 4 - Menu" << setw(12) << right << "*" << endl;
		cout << setw(13) << left << "* 5 - Exit Program" << setw(7) << right << "*" << endl;

		cin >> selection;
	}

	while (selection == 1) {
		hour = hour + 1;
		cout << "*************************" << "   " << "*************************" << endl;
		cout << "Current time: " << setw(2) << setfill('0') << hour << ":";
		cout << setw(2) << setfill('0') << minutes << ":";
		cout << setw(2) << setfill('0') << seconds << endl;
		cout << endl;
		cout << "*************************" << "   " << "*************************" << endl;
		break;
	}

	while (selection == 2) {
		minutes = minutes + 1;
		cout << "*************************" << "   " << "*************************" << endl;
		cout << "Current time: " << setw(2) << setfill('0') << hour << ":";
		cout << setw(2) << setfill('0') << minutes << ":";
		cout << setw(2) << setfill('0') << seconds << endl;
		cout << endl;
		cout << "*************************" << "   " << "*************************" << endl;
		break;
	}

	while (selection == 3) {
		seconds == seconds + 1;
		cout << "*************************" << "   " << "*************************" << endl;
		cout << "Current time: " << setw(2) << setfill('0') << hour << ":";
		cout << setw(2) << setfill('0') << minutes << ":";
		cout << setw(2) << setfill('0') << seconds << endl;
		cout << endl;
		cout << "*************************" << "   " << "*************************" << endl;
		break;
	}

	while (selection == 5) {
		cout << "Quitting program" << endl;
		break;
	}

	return 0;
}
