#include <iostream>
#pragma once
class Fraction
{
public:

	Fraction();
	Fraction(const int numerator, const int denominator);
	~Fraction() = default;
	void Print() const;
	Fraction Sum(const Fraction &b) const;
	Fraction Difference(const Fraction &b) const;
	Fraction Multiplication(const Fraction &b) const;
	Fraction Division(const Fraction &b) const;
	Fraction Reduction();
	bool operator>(const Fraction& other)const;
	bool operator<(const Fraction& other)const;

	void SetNumerator(const int value);

	void SetDenominator(int value);

	int GetNumerator() const;//или можно назвать int numerator();

	int GetDenominator() const;//или можно назвать int denominator();

	bool operator==(const Fraction &other) const;
	bool operator!=(const Fraction &other) const;

	int Whole();//unique method 1

	Fraction& operator=(const Fraction& other);//unique method 2	
	void Input();
private:

	int m_numerator=0;//Вторая очередь
	int m_denominator=1;//Вторая очередь
};

