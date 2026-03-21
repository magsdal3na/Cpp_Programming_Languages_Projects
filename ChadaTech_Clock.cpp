#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//outputs and configures current time
void CurrentTime(double hour, double minutes, double seconds, char& amPm) {
	string amPmOutput;
	double displayHour;

	/*handles whether or not the time is in AM/PM and
	  keeps the time in between 00 - 24 for 24-hour
	  time and 12 - 12 for 12-hour time*/
	if (hour == 0) {
		displayHour = 12;
		amPm = 'A'; //if it's midnight, it's AM
	}
	else if (hour == 12) {
		displayHour = 12;
		amPm = 'P'; //noon is PM
	}
	else if ((hour > 12) && (hour <= 23)) {
		displayHour = hour - 12;
		amPm = 'P'; //1 - midnight is PM
	}
	else if (hour >= 24) {
		hour = 0;
		displayHour = 12;
		amPm = 'A'; //rolls over the clock to 00 for 24-hour time
	}
	else {
		displayHour = hour;
		amPm = 'A'; //everything else (1 - 11) is AM
	}

	//initialized after to display AM/PM at correct time
	if (toupper(amPm) == 'P') {
		amPmOutput = "PM";
	}
	else {
		amPmOutput = "AM";
	}

	cout << "*************************" << "   " << "*************************" << endl;
	// 12-hour side of the display (uses displayHour)
	cout << "*     " << "12-Hour Clock" << setw(6) << "*" << "   " << "*     " << "24-Hour Clock" << setw(6) << "*" << endl;
	cout << "*      " << setw(2) << setfill('0') << displayHour << ":" << setw(2) << setfill('0') << minutes << ":";
	cout << setw(2) << setfill('0') << seconds << " " << amPmOutput << "      *" << "   ";
	//24-hour side of the display (uses hour)
	cout << "*        " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes << ":";
	cout << setw(2) << setfill('0') << seconds << "       *" << setfill(' ') << endl;
	cout << "*************************" << "   " << "*************************" << endl;
}

//outputs the menu. Program starts at the menu by default
void Menu() {
	cout << setfill(' ') << "Please select 1 - 5: " << endl;
	cout << "*************************" << endl;
	cout << setw(13) << left << "* 1 - Add One Hour" << setw(7) << right << "*" << endl;
	cout << setw(13) << left << "* 2 - Add One Minute" << setw(5) << right << "*" << endl;
	cout << setw(13) << left << "* 3 - Add One Second" << setw(5) << right << "*" << endl;
	cout << setw(13) << left << "* 4 - Menu" << setw(12) << right << "*" << endl;
	cout << setw(13) << left << "* 5 - Exit Program" << setw(7) << right << "*" << endl;
	cout << "*************************" << endl;
}


int main() {
	double hour;
	double minutes;
	double seconds;
	int selection = 4;
	char amPm;

	//initial setup for CurrentTime
	cout << "Please enter the current time in hours, minutes, and seconds" << endl;
	cout << "as three separate entries: " << endl;

	cin >> hour;
	cin >> minutes;
	cin >> seconds;

	cout << "Please enter whether it is currently AM or PM using 'A' or 'P': " << endl;

	cin >> amPm;

	//checks user time if == 12 and preps internal time to 24-hour 
	if ((hour == 12) && toupper(amPm) == 'A') {
		hour = 0;
	}
	else if ((hour < 12) && (toupper(amPm) == 'P')) {
		hour += 12;
	}

	CurrentTime(hour, minutes, seconds, amPm);

	//handles selections from menus until the user exits the program
	while ((selection != 5) && (hour > -1) && (minutes > -1) && (seconds > -1) && (hour < 25) && (minutes < 60) && (seconds < 60)) {

		if (selection == 1) { //adds 1 hour
			hour = hour + 1;
			CurrentTime(hour, minutes, seconds, amPm);
			Menu();
			cout << ">>";

			cin >> selection;
		}

		else if (selection == 2) { //adds 1 minute
			minutes = minutes + 1;
			if (minutes > 59) { //updates all time slots if rolls over to next hour
				minutes = 0;
				seconds = 0;
				hour = hour + 1;
			}
			CurrentTime(hour, minutes, seconds, amPm);
			Menu();
			cout << ">>";

			cin >> selection;
		}

		else if (selection == 3) { //adds 1 second
			seconds = seconds + 1;
			if (seconds > 59) { //updates all variables if minutes/seconds roll over to next hour
				seconds = 0;
				minutes = minutes + 1;
				if (minutes > 59) {
					minutes = 0;
					hour = hour + 1;
					if (hour == 12) {
						if (toupper(amPm) == 'A') {
							amPm = 'P';
						}
						else {
							amPm = 'A';
						}
					}
					else if (hour >= 24) {
						hour = 00;
					}
				}
				
			}
			CurrentTime(hour, minutes, seconds, amPm);
			Menu();
			cout << ">>";

			cin >> selection;
		}

		else if (selection == 4) { //displays the menu. needed for initialization
			Menu();

			cin >> selection;
		}

		else {
			cout << "Error occurred. Quitting program..." << endl; //handles if input is out of bounds
			break;
		}
	}

	if ((hour < -1) || (minutes < -1) || (seconds < -1) || (hour > 23) || (minutes > 59) || (seconds > 59)) {
		cout << "Invalid time. Please run the program again." << endl; //handles if time is out of bounds
	}

	cout << "Quitting Program..." << endl; //end of program output

	return 0;
}
