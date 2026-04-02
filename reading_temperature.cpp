#include <iostream>
#include <fstream>
#include <iomanip> //for formatting decimals after converting
using namespace std;

int main() {
	ifstream inFS;	//input file stream
	ofstream outFS; //output file stream
	string city;
	int tempFahrenheit;
	double tempCelsius; //double to prevent answer of "0" when dividing

	//file opening attempt for input
	cout << "Opening file: FahrenheitTemperature.txt" << endl;

	inFS.open("FahrenheitTemperature.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file: FahrenheitTemperature.txt." << endl;
		return 1; //classifies as an error
	}

	//opening attempt for output
	cout << "Opening CelsiusTemperature.txt." << endl;
	outFS.open("CelsiusTemperature.txt");
	if (!outFS.is_open()) {
		cout << "Could not open file CelsiusTemperature.txt." << endl;
		return 1;
	}

	//reading and printing input to output
	cout << "Converting temperatures from Fahrenheit to Celsius." << endl;
	while (inFS >> city >> tempFahrenheit) {
		//perform conversion of F to C
		tempCelsius = (tempFahrenheit - 32.0) * (5.0 / 9.0);

		//write to new file
		outFS << city << " " << fixed << setprecision(2) << tempCelsius << endl;
	}

	cout << "Values have been updated." << endl << "Please view CelsiusTemperature.txt to see the results." << endl;
	//closing both files once read
	inFS.close();
	outFS.close();

	return 0;
}
