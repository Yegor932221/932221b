#pragma once
#include<iostream>
#include"C:\Users\����\932221b\���\3 lab\BoolVector.h"

class BoolMatr
{
public:
	BoolMatr();

	BoolMatr(int columns, int rows, bool value);

	BoolMatr(char** matrix, int rows);

	~BoolMatr();

	BoolMatr(const BoolMatr& other);
private:
	BoolVector* m_bool;
	int m_columns;
	int m_rows;
};

