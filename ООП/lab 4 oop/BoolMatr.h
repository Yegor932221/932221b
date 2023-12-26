#pragma once
#include<iostream>
#include"stdio.h"
#include <vector>
#include"C:\Users\Åãîğ\932221b\ÎÎÏ\3 lab\BoolVector.h"

class BoolMatr
{
public:
	BoolMatr();

	BoolMatr(int colums, int rows, bool value);

	BoolMatr(char** matrix, int rows);

	BoolMatr(std::vector<std::vector<bool>>& vec);

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

	BoolVector MatrConjunction() const;

	BoolVector MatrDisjunction()const;

	int WeightRow(int j)const;

	void InvertElement(int row, int col);

	void InvertElementsInRange(int row, int col, int count);

	void Set(int row, int col, bool value);

	void SetInRange(int row, int col, int count, bool value);

	BoolMatr& operator=(const BoolMatr& other);

	BoolMatr operator&(const BoolMatr& other)const;

	BoolMatr operator&=(const BoolMatr& other);

	BoolMatr operator|(const BoolMatr& other)const;

	BoolMatr operator|=(const BoolMatr& other);

	BoolMatr operator^(const BoolMatr& other)const;

	BoolMatr operator^=(const BoolMatr& other);

	BoolMatr operator~() const;
private:
	BoolVector* m_matrix;
	int m_columns;
	int m_rows;
};

