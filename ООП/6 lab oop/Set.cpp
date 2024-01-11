
#include<iostream>
#include<string>
#include "Set.h"

Set::Set()
	:BoolVector(m_size)
{
}

Set::Set(const char* str)
	:BoolVector(m_size)
{
	for (int i = 0; i < strlen(str); ++i)
	{
		if ((int)str[i] < (m_size + m_shift) && (int)str[i] >= m_shift)
		{
			Set1InRange((int)str[i] - m_shift);
		}
	}
}

Set::Set(const Set& other) 
	:BoolVector(other)
{
}

Set::~Set()
{}

std::ostream& operator<<(std::ostream& stream, const Set& set)
{
	for (int i = 0; i < Set::m_size; ++i)
	{
		if (set[i] > 0)
			stream << (char)(i + Set::m_shift) << "(" << i + Set::m_shift << ")" << " ";
	}
	stream << std::endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, Set& set)
{
	set.Set0All();
	std::string str;
	std::getline(stream, str);
	for (int i = 0; i < str.size(); ++i)
	{
		if ((int)str[i] < (Set::m_size + Set::m_shift) && (int)str[i] >= Set::m_shift)
		{
			set.Set1InRange((int)str[i] - Set::m_shift);
		}
	}
	return stream;
}

bool Set::Attend(const char value)const
{

	if ((int)value >= m_shift || (int)value < m_size)
		return false;
	else
		return (operator[]((int)value - m_shift));
}

char Set::Max() const
{
	char max = '~';
	if (BoolVector::operator[](m_size - 1))
	{
		max = (char)((m_size - 1) + m_shift);
		return max;
	}
	else
	{
		for (int i = m_size - 2; i >= 0; --i)
		{
			if ((BoolVector::operator[](i)))
			{
				max = (char)(i + m_shift);
				return max;
			}
		}
	}
	return max;

}


char Set::Min() const 
{
	char min = '0';
	if (BoolVector::operator[](0))
		return min = (char)(m_shift);
	else
	{
		for (int i = 1; i < m_size; ++i)
		{
			if ((BoolVector::operator[](i)))
			{
				min = (char)(i + m_shift);
				return min;
			}
		}
	}
	return min;
}