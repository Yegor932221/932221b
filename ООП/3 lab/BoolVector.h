#pragma once
#include<stdint.h>
#include<iostream>
class BoolVector
{
	using UI = unsigned int;
	using UC = unsigned char;

private:
	UI m_length = 0;
	UI m_cellCount = 0;
	uint8_t m_insignificantRankCount = 0;
	UC* m_cells = nullptr;
	static const uint8_t m_cellSize = 8;

public:
	BoolVector();
	BoolVector (UI length, const bool value);
	~BoolVector();
};

