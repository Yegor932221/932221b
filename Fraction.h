#include <iostream>
#pragma once
class Fraction
{
public:
	void Print();
	Fraction Sum(Fraction b);
	Fraction Difference(Fraction b);
	Fraction Multiplication(Fraction b);
	int numerator;
	int denominator;
};

