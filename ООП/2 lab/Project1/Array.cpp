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

Array& Array::operator=(const Array& other)
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
	std::cout << this;
}

int Array::Size() const
{
	return m_size;
}

int Array::Search(int l) {
	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == l) return i;
	}
	return -1;
}


Array& Array::operator+(const Array& other) const {
	Array res(m_size+other.m_size);
	for (int i = 0; i < m_size; i++) {
		res.m_array[i] = m_array[i];
	}
	for (int i = 0; i < other.m_size; i++) {
		res.m_array[m_size + i] = other.m_array[i];
	}
	return res;
}

Array &Array::operator+=(const Array& other) {
	Array tmp = *this + other;
	this->Swap(tmp);
	return *this;
}

Array& Array::operator=(Array&& other) {
	Swap(other);
	return *this;
}

void Array::Swap(Array& other) {
	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);
}

//Array::Array(Array&& other) {
// m_size==0;m_array==nullptr
//}

std::ostream& operator<<(std::ostream& stream, const Array& arr) {
	std::cout << '[';
	for (int i = 0; i <arr.Size() - 1; i++) {
		stream << arr[i] << ' ';
	}
	stream << arr[arr.Size() - 1] << "]\n";

	return stream;
}

std::ostream& operator>>(std::ostream& stream, Array& arr) {
	for (int i = 0; i < arr.Size() - 1; i++) {
		stream >> arr[i];
	}

	return stream;
}