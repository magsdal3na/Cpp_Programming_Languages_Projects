/*
 * Calculator.cpp
 *
 *  Date: 3/12/26
 *  Author: Maggie Voigts
 */

#include <iostream>

using namespace std;

int main()																			//changed void to int to run module properly
{
	//char statement[100]{}; removed variable because it's not needed
	double op1, op2;																//changed type to double for added accuracy
	char operation; 
	char answer;																	//added semicolon to finish line and removed char assignment

	cout << "Please enter y/Y to start program. " << endl;							//added explanatory statements to beginning of program
	cout << "Press n/N to exit. " << endl;

	cin >> answer;																	//included input to start the while loops
	
		while (tolower(answer) == 'y')												//added 'tolower' to statement to take both capital and lowercase 'y'
		{
			cout << "Enter an expression by entering the first number," << endl;	//added clarifying instructions
			cout << "followed by the operator (+,-,*,/) and then the" << endl;
			cout << "second number." << endl;

			cin >> op1;																//split up these inputs
			cin >> operation;
			cin >> op2; 

			if (operation == '+') {													//added braces to statement and changes "" to '' around + and removed ; after parentheses
				cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;			//flipped >> to << because for a cout statement, arrows should point left
			}
			else if (operation == '-') {											//added else since statement continues and braces and removed ; after parentheses
				cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;			//flipped first >> to << for cout statement
			}
			else if (operation == '*') {											//added braces and else statement
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;			//added semicolon after endl and made sure program showed multiplication properly
			}
			else if (operation == '/') {											//added braces and else statement
				cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;			//made sure the program showed division properly
			}

			cout << "Do you wish to evaluate another expression? " << endl;
			cout << "Please enter y/n to continue. " << endl;						//added text for clarification
			
			cin >> answer;
		}

		while (tolower(answer) == 'n') {											//added "Program Finished" text if user selects n/N
			cout << "Program Finished." << endl;

			return 0;
		}
}
