#pragma once
#include<iostream>
#include"C:\Users\Åãîð\932221b\ÎÎÏ\3 lab\BoolVector.h"

class BoolMatr
{
public:
	BoolMatr();

	BoolMatr(int colums, int rows, bool value);

	BoolMatr(char** matrix, int rows);

	~BoolMatr();

	BoolMatr(const BoolMatr& other);

	int GetCountColums() const;

	int GetCountRows() const;

	void Swap( BoolMatr& other);

	BoolVector& operator[](const int i);

	const BoolVector& operator[](const int i) const;

	friend std::istream& operator >>(std::istream& stream, BoolMatr& matrix);

	friend std::ostream& operator <<(std::ostream& stream, const BoolMatr& matrix);

	int Weight()const;


private:
	BoolVector* m_bool;
	int m_colums;
	int m_rows;
};

