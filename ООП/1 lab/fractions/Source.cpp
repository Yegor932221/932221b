#include<iostream>
#include<string>
#include "Fraction.h"

int main() 
{
	using std::cout;
		using std::cin;
	Fraction f(1,2), g(3,4);
	int n, d, k;
	cout << "Enter two Fraction: ";

	cin >> n >> d;
	Fraction a(n, d);

	cin >> n >> d;
	Fraction b(n, d);

	std::cout << "\ng: ";
	g.Print();
	
	std::cout << "\nf: ";
	f.Print();

	Fraction sum=(a.Sum(g));
	std::cout << "\na+g: ";
	sum.Print();

	Fraction dif=g.Difference(b);
	std::cout << "\ng-b: ";
	dif.Print();

	Fraction mul=f.Multiplication(a);
	std::cout << "\nf*a: ";
	mul.Print();

	Fraction div=b.Division(f);
	std::cout << "\nb/f: ";
	div.Print();

	if (a > b) {
		std::cout << "\na>b";
	}
	else std::cout << "\na!>b";

	if (a < b) {
		std::cout << "\na<b";
	}
	else std::cout << "\na!<b";


	if (a.operator==(b))
{
		cout << "\nFractions a&b is equal.\n";
	}
	else cout << "\nFractions a&b isn't equal.\n";
	a = b;

	std::cout << "\nafter a=b";
	if (a.operator==(b))
	{
		cout << "\nFractions a&b is equal.\n";
	}
	else cout << "\nFractions a&b isn't equal.\n";

	k = a.Whole();
	std::cout << std::endl << "\nWhole part a: " << k;

	a.SetDenominator(9);
	std::cout << "\na after Set denominator=9:";
	a.Print();

	b.SetNumerator(3);
	std::cout << "\nb after Set numerator=3:";
	b.Print();

	int den = b.GetDenominator();
	std::cout << "\nDenominator b"<<den;

	int num = a.GetNumerator();
	std::cout << "\nNumerator a"<<num;

	a.Reduction();
	std::cout << "\na after reduction: ";
	a.Print();
}