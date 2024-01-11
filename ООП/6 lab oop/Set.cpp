
#include<iostream>
#include<string>
#include "Set.h"

Set::Set()
	:BoolVector(m_size, false)
{
}

Set::Set(const char* str)
	:BoolVector(m_size, false)
{
	for (int i = 0; i < strlen(str); ++i)
	{
		if ((int)str[i] < (m_size + m_shift) && (int)str[i] >= m_shift)
		{
			Set1InRange((int)str[i] - m_shift,1);
		}
	}
}

Set::Set(const Set& other) 
	:BoolVector(other)
{
}

Set::~Set()
{}

