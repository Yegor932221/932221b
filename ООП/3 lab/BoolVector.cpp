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