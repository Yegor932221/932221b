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

	int GetCountColumns() const;

	int GetCountRows() const;

	void Swap( BoolMatr& other);

	BoolVector& operator[](const int i);

	const BoolVector& operator[](const int i) const;

	friend std::istream& operator >>(std::istream& stream, BoolMatr& matrix);

	friend std::ostream& operator <<(std::ostream& stream, const BoolMatr& matrix);

	int Weight()const;

	BoolVector MatrÑonjunction() const;

	BoolVector MatrDisjunction()const;

	int WeightRow(int j)const;

	void InversElement(int i, int j);

	void InversElementsInRange(int i, int j, int k);

	void Set0(int i, int j);

	void Set1(int i, int j);

	void Set0InRange(int i, int j, int k);

	void Set1InRange(int i, int j, int k);
private:
	BoolVector* m_bool;
	int m_columns;
	int m_rows;
};

