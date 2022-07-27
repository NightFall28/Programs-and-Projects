// Sample Output:
// Enter your amount for change($): 4.28
// Use: 4 dollars 1 quarters 0 dimes 0 nickels and 3 pennies

#include <iostream>
using namespace std;


int main() {

	double dollar = 0, quarter = 0, dime = 0, nickel = 0, penny = 0;
	double amount;
	cout << "Enter your amount for change($): ";
	cin >> amount;

	while (amount >= 1) {
		amount -= 1;
		dollar++;
	}

	while (amount >= 0.25) {
		amount -= 0.25;
		quarter++;
	}

	while (amount >= 0.10) {
		amount -= 0.10;
		dime++;
	}

	while (amount >= 0.05) {
		amount -= 0.05;
		nickel++;
	}

	while (amount >= 0.01) {
		amount -= 0.01;
		penny++;
	}

	cout << "Use: " << dollar << " dollars " << quarter << " quarters " << dime << " dimes " << nickel << " nickels ";
	cout << "and " << penny << " pennies\n";


	return 0;
}
