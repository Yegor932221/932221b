#include "Fraction.h"

void Fraction::Print()const {
	std::cout << m_numerator << '/' << m_denominator << std::endl;
}

Fraction Fraction::Sum(const Fraction &b)const {
	Fraction c;
	c.m_numerator = (m_numerator * b.m_denominator) + (b.m_numerator * m_denominator);
	c.m_denominator = m_denominator * b.m_denominator;
	return c;
}

Fraction Fraction::Difference(const Fraction &b)const {
	Fraction c;
	c.m_numerator = (m_numerator * b.m_denominator) - (b.m_numerator * m_denominator);
	c.m_denominator = m_denominator * b.m_denominator;
	return c;
}

Fraction Fraction::Multiplication(const Fraction &b) const {
	Fraction c;
	c.m_numerator = (m_numerator * b.m_numerator);
	c.m_denominator = (b.m_denominator * m_denominator);
	return c;
}

Fraction Fraction::Division(const Fraction &b) const {
	Fraction c;
	c.m_numerator = (m_numerator * b.m_denominator);
	c.m_denominator = (b.m_numerator * m_denominator);
	return c;
}

Fraction::Fraction() {
	m_numerator = 0;
	m_denominator = 1;
}

Fraction::Fraction(const int numerator, const int denominator)
//Первая очередь
// :numerator(numerator)
//,denominator(denominator)
{
	m_numerator = numerator;//Третья очередь

	if (denominator == 0) {
		std::cerr << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.\n";
		m_denominator = 1;
	}
	else  m_denominator = denominator;//Третья очередь

	if (denominator < 0) {
		m_denominator *= -1;
		m_numerator *= -1;
	}
}
//Вторая очередь в .h

void Fraction::SetNumerator(const int value) {
	m_numerator = value;
}


void Fraction::SetDenominator(const int value) {
	if (value == 0) {
		std::cerr << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.\n";
		m_denominator = 1;
	}
	else {
		m_denominator = value;
	}
} 

int Fraction::GetNumerator()const {
	return m_numerator;
}

int Fraction::GetDenominator()const {
	return m_denominator;
}

bool Fraction::operator==(const Fraction &other)const {
	return(m_numerator == other.m_numerator && m_denominator == other.m_denominator);
}

bool Fraction::operator!=(const Fraction &other)const {
	return !operator==(other);
}