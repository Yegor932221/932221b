#include<iostream>
#include<string>
#include "Fraction.h"

int main() 
{
	using std::cout;
		using std::cin;
	Fraction f(1,2), g(3,4);
	int n, d;
	cout << "Enter two Fraction: ";
	cin >> n >> d;
	while (d == 0) {
		cout << "/n" << "Denominator can't be zero!!!! Please enter a valid denominator: ";
		cin >> d;
	}
	Fraction a(n, d);

	cin >> n >> d;
	while (d == 0) {
		cout << "\n" << "Denominator can't be zero!!!! Please enter a valid denominator: ";
		cin >> d;
	}
	Fraction b(n, d);

	if (a.operator==(b))
{
		cout << "Fractions is equal.\n";
	}
	else cout << "Fractions isn't equal.\n";

}