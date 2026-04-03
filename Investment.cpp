#include <iostream>
#include <iomanip>
#include "Investment.h"
using namespace std;

//sets up constructor information
Investment::Investment() {
	m_initialInvestment = 0.0;
	m_monthlyDeposit = 0.0;
	m_annualInterest = 0.0;
	m_numOfYears = 0;
}

//asks user for initial amounts
void Investment::promptForData() {
    //try/catch block for user input in case there is an issue during input
    try {
        cout << "Initial Investment Amount: $";
        if (!(cin >> m_initialInvestment)) {
            throw runtime_error("Invalid input: Investment must be a number.");
        }

        cout << "Monthly Deposit: $";
        if (!(cin >> m_monthlyDeposit)) {
            throw runtime_error("Invalid input: Deposit must be a number.");
        }

        cout << "Annual Interest: %";
        if (!(cin >> m_annualInterest)) {
            throw runtime_error("Invalid input: Interest must be a number.");
        }

        cout << "Number of Years: ";
        if (!(cin >> m_numOfYears)) {
            throw runtime_error("Invalid input: Years must be a whole number.");
        }

        //checking for negative numbers
        if (m_initialInvestment < 0 || m_monthlyDeposit < 0 || m_annualInterest < 0 || m_numOfYears < 0) {
            throw runtime_error("Invalid input: Values cannot be negative.");
        }
    }
    catch (runtime_error& e) {
        //clear the error flags and flush the buffer
        cin.clear();
        cin.ignore(100, '\n');

        //output specific error message
        cout << "Error: " << e.what() << endl;

        //reset values to default
        m_initialInvestment = 0;
        m_monthlyDeposit = 0;
        m_annualInterest = 0;
        m_numOfYears = 0;
    }
}

//output without monthly deposits
void Investment::displayWithoutDeposits() {
    double currentBalance = m_initialInvestment;
    double yearlyInterest;

    //header
    cout << setfill('-') << setw(65) << "" << endl;
    cout << setfill(' ') << setw(4) << "    Balance and Interest Without Additional Monthly Deposits" << setw(5) << "" << endl;
    cout << setfill('=') << setw(65) << "" << endl;
    cout << setfill(' ') << left << setw(10) << "Year"
        << setw(25) << "Year End Balance"
        << "Year End Earned Interest" << endl;
    cout << setfill('-') << setw(65) << "" << endl;
    cout << setfill(' ') << setw(65) << "" << endl;

    cout << fixed << setprecision(2);

    //calculates yearly interest
    for (int i = 1; i <= m_numOfYears; ++i) {
        yearlyInterest = currentBalance * (m_annualInterest / 100.0);
        currentBalance += yearlyInterest;

        //use setw to align the columns
        cout << left << setw(10) << i
            << "$" << setw(24) << currentBalance
            << "$" << yearlyInterest << endl;
    }
}

//output with monthly deposits
void Investment::displayWithDeposits() {
    double currentBalance = m_initialInvestment;
    //calculates monthly interest rate
    double monthlyInterestRate = (m_annualInterest / 100.0) / 12.0;

    //header
    cout << setfill(' ') << setw(65) << "" << endl;
    cout << setfill('-') << setw(65) << "" << endl;
    cout << setfill(' ') << setw(4) << "    Balance and Interest With Additional Monthly Deposits" << setw(5) << "" << endl;
    cout << setfill('=') << setw(65) << "" << endl;
    cout << setfill(' ') << left << setw(10) << "Year"
        << setw(25) << "Year End Balance"
        << "Year End Earned Interest" << endl;
    cout << setfill('-') << setw(65) << "" << endl;
    cout << setfill(' ') << setw(65) << "" << endl;

    //ensures values will appear with only two numbers after the decimal
    cout << fixed << setprecision(2);

    //calculating yearly interest
    for (int i = 1; i <= m_numOfYears; ++i) {
        double yearlyInterestEarned = 0;

        //calculates the compouding interest for the year
        for (int j = 1; j <= 12; ++j) {
            currentBalance += m_monthlyDeposit;
            double monthlyInterest = currentBalance * monthlyInterestRate;
            yearlyInterestEarned += monthlyInterest;
            currentBalance += monthlyInterest;
        }

        //year end output
        cout << left << setw(10) << i
            << "$" << setw(24) << currentBalance
            << "$" << yearlyInterestEarned << endl;
    }
    cout << setfill(' ') << setw(65) << "" << endl;
    cout << setfill('-') << setw(65) << "" << endl;
}
