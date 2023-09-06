#include<iostream>
#include<string>
#include "Fraction.h"

int main() 
{
	Fraction f, g;
	Fraction h;
	f.numerator = 1;
	f.denominator = 2;
	g.numerator = 3;
	g.denominator = 5;
	h=f.Sum(g);
	h.Print();
	h = f.Difference(g);
	h.Print();
	h = f.Multiplication(g);
	h.Print();
}