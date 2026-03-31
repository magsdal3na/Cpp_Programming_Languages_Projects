#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream inFS;	//input file stream
	string city;
	int tempFahrenheit;

	//file opening attempt
	cout << "Opening file: FahrenheitTemperature.txt" << endl;

	inFS.open("FahrenheitTemperature.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file: FahrenheitTemperature.txt" << endl;
		return 1; //error
	}

	//reading and printing input to output
	while (!inFS.eof()) {
		inFS >> city;
		inFS >> tempFahrenheit;

		if (!inFS.fail()) {
			cout << city << " " << tempFahrenheit << endl;
		}
	}

	//closing file once read
	inFS.close();

	return 0;
}
