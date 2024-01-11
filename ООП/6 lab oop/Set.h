#pragma once
#include<stdint.h>
#include<iostream>
#include"C:\Users\����\932221b\���\3 lab\BoolVector.h"

class Set : BoolVector
{
public:
	Set();
	Set(const char* str);
	Set(const Set& other);
	~Set();
	friend std::ostream& operator<<(std::ostream& stream, const Set& set);
	friend std::istream& operator>>(std::istream& stream, Set& set);
private:
	static const int m_size = 95;
	static const int m_shift = 32;
};

