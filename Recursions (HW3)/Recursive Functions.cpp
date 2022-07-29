#include <iostream>
using namespace std;

// One Binary Number
void binary_print(ostream& outs, unsigned int n)
{
	if (n < 2) {
		outs << n;
	}
	else {
		binary_print(outs, n / 2);
		outs << (n % 2);
	}
}


// Triangle Pattern
void triangle(ostream& outs, unsigned int m, unsigned int n)
{
	if (m <= n) {
		
		for (int i = 0; i < m; i++) {
			outs << "*";
		}
		outs << endl;

		triangle(outs, m+1, n);

		for (int i = 0; i < m; i++) {
			outs << "*";
		}
		outs << endl;
		
	}
}

// Pow Function
double power(double x, int n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return power(x, n / 2) * power(x, n / 2);
	else
		return x * power(x, n / 2) * power(x, n / 2);
}

//  Repeated and Indented Sentences
void indented_sentences(size_t m, size_t n)
{
	
	if (m > n) 
		return;

	else {
		for (int i = 1; i < m; i++)
			cout << " ";
		cout << "This was written by calling number " << m << ".\n";
		
		indented_sentences(m + 1, n);
		for (int i = 1; i < m; i++) 
			cout << " ";
		cout << "This was ALSO written by calling number " << m << ".\n";
	}
}

// Testing Codes
int main() {

	binary_print(cout,27);
	cout << endl << endl;

	triangle(cout, 3, 5);
	cout << endl;

	cout << power(4, 4) << endl << endl;

	indented_sentences(1, 4);
}
