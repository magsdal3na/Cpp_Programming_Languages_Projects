#ifndef INVESTMENT_H_
#define INVESTMENT_H_

class Investment {
	public:
		//constructor
		Investment();

		//input methods
		void promptForData();
		void displayWithoutDeposits();
		void displayWithDeposits();

	private:
		double m_initialInvestment;
		double m_monthlyDeposit;
		double m_annualInterest;
		int m_numOfYears;
};

#endif
