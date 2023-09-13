#include <iostream>
#pragma once
class Fraction
{
public:
	Fraction();
	Fraction(int numerator, int denominator);
	~Fraction() = default;
	void Print();
	Fraction Sum(Fraction b);
	Fraction Difference(Fraction b);
	Fraction Multiplication(Fraction b);
	Fraction Division(Fraction b);
public:
	int numerator;
	int denominator;
};

