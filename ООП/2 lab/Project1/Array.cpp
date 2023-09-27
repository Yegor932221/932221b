#include<iostream>
#include<assert.h>
#include "Array.h"

Array::Array(const int size, const int value)
{
	if (size < 0) {
	std::cerr << "Array::Array: size is negative, invert...\n";
		m_size = -m_size;
	}
	else m_size = size;
	m_array = new int[m_size];
		std::cout << m_array << '/n';
	for (int i = 0; i < m_size; i++) {
		m_array[i] = value;
	}
}

Array::Array(const Array& other)
	: m_size(other.m_size)
{
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.m_array[i];
	}
}

Array::~Array()
{
	delete[] m_array;
}

int& Array::operator[](const int index) 
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

const int& Array::operator[](const int index) const
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

Array &Array::operator=(const Array& other)
{
	if (this==&other) {
		return *this;
	}
	if (m_size != other.m_size) {
		m_size = other.Size();
		delete[]m_array;
		m_array = new int[m_size];
	}
	for (int i = 0; i < m_array[i]; ++i) {
		m_array[i] = other.m_array[i];
	}
	return *this;
}

void Array::Print() const 
{
	std::cout << '[';
	for (int i = 0; i < m_size-1; i++) {
		std::cout << m_array[i]<<' ';
	}
	std::cout << m_array[m_size - 1] << "]\n";
}

int Array::Size() const
{
	return m_size;
}

