#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<assert.h>
#include "BoolMatr.h"

BoolMatr::BoolMatr()
{
	m_colums = 8;
	m_rows = 1;
	m_bool = new BoolVector[m_rows];
	BoolVector bool1(m_colums, 1);
	m_bool[0] = bool1;
}

BoolMatr::BoolMatr( int colums, int rows, bool value)
{
	assert(colums > 0 || rows > 0);

	m_bool = new BoolVector[m_rows = rows];

	m_colums = colums;
	for (int i = 0; i < m_rows; i++)
	{
		BoolVector bool1(colums, value);
		m_bool[i] = bool1;
	}
}

BoolMatr::BoolMatr(char** matrix, int rows)
{
	assert(rows > 0);
	m_colums = strlen(matrix[0]);
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
	BoolMatr(other.m_colums, other.m_rows, false);
	m_bool = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_bool[i] = other.m_bool[i];
	}
}

int BoolMatr::GetCountColums() const{
	return m_colums;
}

int BoolMatr::GetCountRows() const{
	return m_rows;
}

void BoolMatr::Swap( BoolMatr& other) {
	std::swap(m_rows, other.m_rows);
	std::swap(m_colums, other.m_colums);
	std::swap(m_bool, other.m_bool);
}

BoolVector& BoolMatr::operator[](const int i)
{
	assert(i >= 0 || i < m_rows);
	return m_bool[i];
}

const	BoolVector& BoolMatr::operator[](const int i) const
{
	assert(i >= 0 || i < m_rows);
	return m_bool[i];
}

std::istream& operator >>(std::istream& stream, BoolMatr& matrix) {
	for (int i = 0; i < matrix.GetCountColums(); i++) {
		stream >> matrix[i];
	}
	return stream;
}

std::ostream& operator <<(std::ostream& stream,const BoolMatr& matrix) {
	for (int i = 0; i < matrix.GetCountColums(); i++) {
		stream << matrix[i];
	}
	return stream;
}

int BoolMatr::Weight()const {
	int weight=0;
	for (int i = 0; i < m_rows; i++)
	{
		weight+=m_bool[i].Weight();
	}
	return weight;
}
