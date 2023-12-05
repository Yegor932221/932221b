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
	BoolVector(UI length, const bool value);
	~BoolVector();
	int BoolLenght();
	BoolVector(const BoolVector& other);
	void Set1(const int cell, const int pos_cell);
	void Set0(const int cell, const int pos_cell);
	BoolVector(const char* str);
	void Swap(BoolVector& other);
	BoolVector operator<<(const int count)const;
	BoolVector operator>>(const int count)const;
	void Invers();
	void InversElement(int index);
	void Set1InRange(int index, const int range);
	void Set0InRange(int index, const int range);
	void Set1All();
	void Set0All();
	int Weight();

	class BoolRank;
	BoolVector::BoolRank operator[](const int index);

	BoolVector operator&(const BoolVector& other)const;
	BoolVector operator&=(const BoolVector& other);

	BoolVector operator^(const BoolVector& other)const;
	BoolVector operator^=(const BoolVector& other);

	BoolVector operator|(const BoolVector& other)const;
	BoolVector operator|=(const BoolVector& other);

	BoolVector operator<<=(const int count);
	BoolVector operator>>=(const int count);

	BoolVector operator ~()const;

	BoolVector& operator=(const BoolVector& other);
};

class BoolVector::BoolRank
{
private:
	uint8_t* m_cell = nullptr;
	uint8_t m_mask = 1 << 7;
public:
	BoolRank(UC* cell, const int mask);
};