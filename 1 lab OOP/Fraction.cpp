#include "Fraction.h"

void Fraction::Print() {
	std::cout << numerator << '/' << denominator << std::endl;
}

Fraction Fraction::Sum(Fraction b) {
	Fraction c;
	c.numerator = (numerator * b.denominator) + (b.numerator * denominator);
	c.denominator = denominator * b.denominator;
	return c;
}

Fraction Fraction::Difference(Fraction b) {
	Fraction c;
	c.numerator = (numerator * b.denominator) - (b.numerator * denominator);
	c.denominator = denominator * b.denominator;
	return c;
}

Fraction Fraction::Multiplication(Fraction b) {
	Fraction c;
	c.numerator = (numerator * b.denominator);
	c.denominator = (b.numerator * denominator);
	return c;
}
