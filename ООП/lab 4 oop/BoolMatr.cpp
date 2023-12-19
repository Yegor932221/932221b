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
	m_matrix = new BoolVector[m_rows];
	BoolVector bool1(m_columns, 1);
	m_matrix[0] = bool1;
}

BoolMatr::BoolMatr( int colums, int rows, bool value)
{
	assert(colums > 0 && rows > 0);

	m_matrix = new BoolVector[m_rows = rows];

	m_columns = colums;
	for (int i = 0; i < m_rows; i++)
	{
		BoolVector row(colums, value);
		m_matrix[i].Swap(row);
	}
}

BoolMatr::BoolMatr(char** matrix, int rows)
{
	assert(rows > 0);
	m_columns = strlen(matrix[0]);
	m_rows = rows;
	m_matrix = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_matrix[i] = BoolVector(matrix[i]);
	}
}


BoolMatr::~BoolMatr()
{
	delete[]m_matrix;
}

BoolMatr::BoolMatr(const BoolMatr& other)
{
	m_matrix = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_matrix[i] = other.m_matrix[i];
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
	std::swap(m_matrix, other.m_matrix);
}

BoolVector& BoolMatr::operator[](const int i)
{
	assert(i >= 0 && i < m_rows);
	return m_matrix[i];
}

const	BoolVector& BoolMatr::operator[](const int i) const
{
	assert(i >= 0 && i < m_rows);
	return m_matrix[i];
}

std::istream& operator >>(std::istream& stream, BoolMatr& matrix) {
	for (int i = 0; i < matrix.GetCountRows(); i++) {
		stream >> matrix[i];
	}
	return stream;
}

std::ostream& operator <<(std::ostream& stream,const BoolMatr& matrix) {
	for (int i = 0; i < matrix.GetCountRows(); i++) {
		stream << matrix[i];
	}
	return stream;
}

int BoolMatr::Weight()const {
	int weight=0;
	for (int i = 0; i < m_rows; i++)
	{
		weight+=m_matrix[i].Weight();
	}
	return weight;
}

BoolVector BoolMatr::MatrÑonjunction()const {
	BoolVector answer(m_matrix[0]);
	for (int i = 1; i < m_rows; i++)
	{
		answer &= m_matrix[i];
	}
	return answer;
}

BoolVector BoolMatr::MatrDisjunction()const {
	BoolVector answer(m_matrix[0]);
	for (int i = 1; i < m_rows; i++)
	{
		answer |= m_matrix[i];
	}
	return answer;
}

int BoolMatr::WeightRow(int j)const {
	return m_matrix[j].Weight();
}

void BoolMatr::InvertElement(int row, int col) {
	assert(col > 0 && row > 0 && col < m_columns && row < m_rows);
	m_matrix[row].InvertElement(col);
}

void BoolMatr::InvertElementsInRange(int row, int col, int count) {
	assert(col >= 0 && col < m_columns && row >= 0 && row < m_rows && (count + col) < m_columns);
	for(int i=0;i<count;i++)
		m_matrix[row].InvertElement(col+i);
}

void BoolMatr::Set(int row, int col, bool value) {
	assert(col > 0 && row > 0 && col<m_columns && row<m_rows);
	m_matrix[row][col] = value;
}

void BoolMatr::SetInRange(int row, int col, int count, bool value) {
	assert(col >= 0 && col < m_columns && row >= 0 && row < m_rows && (count + col) < m_columns);
	for (int f = 0; f < count; f++)
	m_matrix[row][col+f] = value;
}

BoolMatr& BoolMatr::operator=(const BoolMatr& other)
{
	if (m_matrix == other.m_matrix)
		return *this;

	if (m_rows != other.m_rows)
	{
		m_rows = other.m_rows;
		delete[] m_matrix;
		m_matrix = new BoolVector[m_rows];
	}

	m_columns = other.m_columns;
	for (int i = 0; i < m_rows; i++)
	{
		m_matrix[i] = other.m_matrix[i];
	}
	return *this;
}

BoolMatr BoolMatr::operator&(const BoolMatr& other)const
{
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	BoolMatr answer(*this);
	for (int i = 0; i < m_rows; i++)
	{
		answer.m_matrix[i] &= other.m_matrix[i];
	}
	return answer;
}

BoolMatr BoolMatr::operator&=(const BoolMatr& other)
{
	BoolMatr answer = *this & other;
	Swap(answer);
	return *this;
}

BoolMatr BoolMatr::operator|(const BoolMatr& other)const
{
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	BoolMatr answer(*this);
	for (int i = 0; i < m_rows; i++)
	{
		answer.m_matrix[i] |= other.m_matrix[i];
	}
	return answer;
}

BoolMatr BoolMatr::operator|=(const BoolMatr& other)
{
	BoolMatr answer = *this | other;
	Swap(answer);
	return *this;
}

BoolMatr BoolMatr::operator^(const BoolMatr& other)const
{
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	BoolMatr answer(*this);
	for (int i = 0; i < m_rows; i++)
	{
		answer.m_matrix[i] ^= other.m_matrix[i];
	}
	return answer;
}

BoolMatr BoolMatr::operator^=(const BoolMatr& other)
{
	BoolMatr answer = *this ^ other;
	Swap(answer);
	return *this;
}

BoolMatr BoolMatr::operator~() const {
	BoolMatr answer = *this;
	for (int i = 0; i < m_rows; i++)
	{
		answer.m_matrix[i].Invert();
	}
	return answer;
}