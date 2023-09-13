#include<iostream>
#include<string>
#include "Fraction.h"

int main() 
{
	Fraction f, g;
	f.Print();
	Fraction h;
	f.numerator = 1;
	f.denominator = 2;
	g.numerator = 1;
	g.denominator = 4;
	h=f.Sum(g);
	h.Print();
	h = f.Difference(g);
	h.Print();
	h = f.Multiplication(g);
	h.Print();
	h = f.Division(g);
	h.Print();
}