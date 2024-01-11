#pragma once
#include<stdint.h>
#include<iostream>
#include"C:\Users\Åãîğ\932221b\ÎÎÏ\3 lab\BoolVector.h"

class Set:BoolVector
{
public:
	Set();
	Set(const char* str);
	Set(const Set& other);
	~Set();
private:
	static const int m_size = 95;
	static const int m_shift = 32;
};

