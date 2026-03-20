#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//int MilitaryHour(double hour) {
	//if (hour > 12) {
		//hour = hour - 12;
	//}
//}

void CurrentTime(double hour, double minutes, double seconds, double militaryHour) {
	cout << "*************************" << "   " << "*************************" << endl;
	cout << "*     " << "12-Hour Clock" << setw(6) << "*" << "   " << "*     " << "24-Hour Clock" << setw(6) << "*" << endl;
	cout << "*        " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes << ":";
	cout << setw(2) << setfill('0') << seconds << "       *" << "   ";
	cout << "*        " << setw(2) << setfill('0') << militaryHour << ":" << setw(2) << setfill('0') << minutes << ":";
	cout << setw(2) << setfill('0') << seconds << "       *" << endl;
	cout << "*************************" << "   " << "*************************" << endl;
}

void Menu() {
	cout << setfill(' ') << "Please select 1 - 4: " << endl;
	cout << "*************************" << endl;
	cout << setw(13) << left << "* 1 - Add One Hour" << setw(7) << right << "*" << endl;
	cout << setw(13) << left << "* 2 - Add One Minute" << setw(5) << right << "*" << endl;
	cout << setw(13) << left << "* 3 - Add One Second" << setw(5) << right << "*" << endl;
	cout << setw(13) << left << "* 4 - Menu" << setw(12) << right << "*" << endl;
	cout << setw(13) << left << "* 5 - Exit Program" << setw(7) << right << "*" << endl;
}


int main() {
	double hour;
	double minutes;
	double seconds;
	double militaryHour = 00;
	double tempHour = 00;
	int selection = 4;

	cout << "Please enter the current time in hours, minutes, and seconds: " << endl;

	cin >> hour;
	cin >> minutes;
	cin >> seconds;

	CurrentTime(hour, minutes, seconds, militaryHour);
	
	while (selection != 5) {
		if (selection == 4) {
			cout << setfill(' ') << "Please select 1 - 4: " << endl;
			cout << "*************************" << endl;
			cout << setw(13) << left << "* 1 - Add One Hour" << setw(7) << right << "*" << endl;
			cout << setw(13) << left << "* 2 - Add One Minute" << setw(5) << right << "*" << endl;
			cout << setw(13) << left << "* 3 - Add One Second" << setw(5) << right << "*" << endl;
			cout << setw(13) << left << "* 4 - Menu" << setw(12) << right << "*" << endl;
			cout << setw(13) << left << "* 5 - Exit Program" << setw(7) << right << "*" << endl;

			cin >> selection;
		}

		else if (selection == 1) {
			hour = hour + 1;
			if (hour > 12) {
				tempHour = hour;
				militaryHour = hour;
				hour = militaryHour - 12;
			}
			CurrentTime(hour, minutes, seconds, militaryHour);
			cout << "Please select 1 - 5 from the menu: " << endl;

			cin >> selection;
		}

		else if (selection == 2) {
			minutes = minutes + 1;
			CurrentTime(hour, minutes, seconds, militaryHour);
			cout << "Please select 1 - 5 from the menu: " << endl;

			cin >> selection;
		}

		else if (selection == 3) {
			seconds = seconds + 1;
			CurrentTime(hour, minutes, seconds, militaryHour);
			cout << "Please select 1 - 5 from the menu: " << endl;

			cin >> selection;
		}

		else if (selection == 5) {
			cout << "Quitting program" << endl;
			break;
		}
	}
	return 0;
}
