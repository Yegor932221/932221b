#include "BoolVector.h"
#include<iostream>
#include<assert.h>


BoolVector::BoolVector()
{
	m_length = 8;
	m_cellCount = 1;
	m_cells = new UC[m_cellCount];
	m_cells[0] = false;
}

BoolVector::BoolVector(UI length, const bool value)
{
	assert(length >= 0);
	m_length = length;
	m_cellCount = length / 8 + bool(length % 8);
	m_insignificantRankCount = (m_cellCount * m_cellSize) - m_length;
	m_cells = new UC[m_cellCount];
	uint8_t mask = 0;
	if (value)
	{
		mask = ~mask;
	}
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = mask;
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

BoolVector:: ~BoolVector()
{
	delete[] m_cells;
}

int BoolVector::BoolLenght()
{
	return m_length;
}

BoolVector::BoolVector(const BoolVector& other)
	:m_length(other.m_length)
{
	m_cellCount = other.m_cellCount;
	m_cells = new UC[m_cellCount];
	m_insignificantRankCount = (m_cellCount * m_cellSize) - m_length;
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = other.m_cells[i];
	}
}

void BoolVector::Set1(const int cell, const int pos_cell)
{
	assert(cell >= 0 || cell < m_cellCount || pos_cell < m_cellSize);
	uint8_t mask = 1;
	mask = mask << 7 - pos_cell;
	m_cells[cell] = m_cells[cell] | mask;
}

void BoolVector::Set0(const int cell, const int pos_cell)
{
	assert(cell >= 0 || cell < m_cellCount || pos_cell < m_cellSize);
	uint8_t mask = 1;
	mask = mask << 7 - pos_cell;
	m_cells[cell] = m_cells[cell] & ~mask;

}

BoolVector::BoolVector(const char* str)
{
	m_length = strlen(str);
	m_cellCount = m_length / 8 + bool(m_length % 8);
	m_insignificantRankCount = (m_cellCount * m_cellSize) - m_length;
	m_cells = new UC[m_cellCount];
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '1')
			Set1(i / 8, i % 8);
		else
			Set0(i / 8, i % 8);
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

void BoolVector::Swap(BoolVector& other)
{
	std::swap(m_cellCount, other.m_cellCount);
	std::swap(m_cells, other.m_cells);
	std::swap(m_length, other.m_length);
	std::swap(m_insignificantRankCount, other.m_insignificantRankCount);
}

BoolVector BoolVector::operator<<(const int count)const
{
	assert(count >= 0);
	BoolVector other(*this);
	if (count / m_cellSize == 0)
	{
		other.m_cells[0] <<= count;
		for (int i = 1; i < other.m_cellCount; i++)
		{
			UI mask = 0;
			mask |= other.m_cells[i];
			mask >>= m_cellSize - count;
			other.m_cells[i - 1] |= mask;
			other.m_cells[i] <<= count;
		}
	}
	else
	{
		for (int i = 0; i < other.m_cellCount; i++)
		{
			if (i + count / other.m_cellSize < other.m_cellCount)
			{
				other.m_cells[i] = m_cells[i + (count / other.m_cellSize)];
				other.m_cells[i + (count / other.m_cellSize)] = 0;
			}
			else
			{
				other.m_cells[i] = 0;
			}
		}
		other.m_cells[0] <<= count % m_cellSize;
		for (int i = 1; i < other.m_cellCount; i++)
		{
			UI mask = 0;
			mask |= other.m_cells[i];
			mask >>= m_cellSize - count % m_cellSize;
			other.m_cells[i - 1] |= mask;
			other.m_cells[i] <<= count % m_cellSize;
		}
	}

	other.m_cells[m_cellCount - 1] >>= m_insignificantRankCount;
	other.m_cells[m_cellCount - 1] <<= m_insignificantRankCount;
	return other;
}

BoolVector BoolVector::operator>>(const int count)const
{
	assert(count >= 0);
	BoolVector other(*this);
	if (count / m_cellSize > 0)
	{
		for (int i = other.m_cellCount - 1; i >= 0; i--)
		{
			if (i - count / other.m_cellSize >= 0)
			{
				other.m_cells[i] = m_cells[i - (count / other.m_cellSize)];
				other.m_cells[i - (count / other.m_cellSize)] = 0;
			}
			else
				other.m_cells[i] = 0;
		}
	}
	other.m_cells[m_cellCount - 1] >>= count % m_cellSize;
	for (int i = other.m_cellCount - 2; i >= 0; i--)
	{
		UI mask = 0;
		mask |= other.m_cells[i];
		mask <<= m_cellSize - count % m_cellSize;
		other.m_cells[i + 1] |= mask;
		other.m_cells[i] >>= count%m_cellSize;
	}
	return other;
}

void BoolVector::Invers()
{
	for (int i = 0; i < m_cellCount; i++){
		m_cells[i] =~ m_cells[i];
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}