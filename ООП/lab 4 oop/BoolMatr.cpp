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

BoolMatr::BoolMatr( int colums, int rows, bool value)
{
	assert(colums > 0 || rows > 0);

	m_bool = new BoolVector[m_rows = rows];

	m_columns = colums;
	for (int i = 0; i < m_rows; i++)
	{
		BoolVector bool1(colums, value);
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

int BoolMatr::GetCountColumns() const{
	return m_columns;
}

int BoolMatr::GetCountRows() const{
	return m_rows;
}

void BoolMatr::Swap( BoolMatr& other) {
	std::swap(m_rows, other.m_rows);
	std::swap(m_columns, other.m_columns);
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
	for (int i = 0; i < matrix.GetCountColumns(); i++) {
		stream >> matrix[i];
	}
	return stream;
}

std::ostream& operator <<(std::ostream& stream,const BoolMatr& matrix) {
	for (int i = 0; i < matrix.GetCountColumns(); i++) {
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

BoolVector BoolMatr::MatrÑonjunction()const {
	BoolVector answer(m_bool[0]);
	for (int i = 1; i < m_rows; i++)
	{
		answer &= m_bool[i];
	}
	return answer;
}

BoolVector BoolMatr::MatrDisjunction()const {
	BoolVector answer(m_bool[0]);
	for (int i = 1; i < m_rows; i++)
	{
		answer |= m_bool[i];
	}
	return answer;
}

int BoolMatr::WeightRow(int j)const {
	return m_bool[j].Weight();
}

void BoolMatr::InversElement(int i, int j) {
	m_bool[j].InversElement(i);
}

void BoolMatr::InversElementsInRange(int i, int j,int k) {
	for(int f=0;f<k;f++)
	m_bool[j].InversElement(i+f);
}

void BoolMatr::Set0(int i, int j) {
	m_bool[j][i] = 0;
}

void BoolMatr::Set1(int i, int j) {
	m_bool[j][i] = 1;
}

void BoolMatr::Set0InRange(int i, int j, int k) {
	for (int f = 0; f < k; f++)
	m_bool[j][i+f] = 0;
}

void BoolMatr::Set1InRange(int i, int j, int k) {
	assert(i >= 0 && i < m_columns && j >= 0 && j < m_rows && (k + i) < m_columns);
	for (int f = 0; f < k; f++)
	m_bool[j][i+f] = 1;
}

