#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<assert.h>
#include "BoolMatr.h"

BoolMatr::BoolMatr()
{
	m_columns = 8;
	m_rows = 1;
	m_bool = new BoolVector[m_rows];
	BoolVector bool1(m_columns, 1);
	m_bool[0] = bool1;
}

BoolMatr::BoolMatr( int columns, int rows, bool value)
{
	assert(columns > 0 || rows > 0);

	m_bool = new BoolVector[m_rows = rows];

	m_columns = columns;
	for (int i = 0; i < m_rows; i++)
	{
		BoolVector bool1(columns, value);
		m_bool[i] = bool1;
	}
}

BoolMatr::BoolMatr(char** matrix, int rows)
{
	assert(rows > 0);
	m_columns = strlen(matrix[0]);
	m_rows = rows;
	m_bool = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_bool[i] = BoolVector(matrix[i]);
	}
}


BoolMatr::~BoolMatr()
{
	delete[]m_bool;
}

BoolMatr::BoolMatr(const BoolMatr& other)
{
	BoolMatr(other.m_columns, other.m_rows, false);
	m_bool = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_bool[i] = other.m_bool[i];
	}
}

int BoolMatr::GetCountColums() {
	return m_columns;
}

int BoolMatr::GetCountRows() {
	return m_rows;
}

