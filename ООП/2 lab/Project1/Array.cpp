#include<iostream>
#include<assert.h>
#include "Array.h"

Array::Array(const int size, const int value) {
	if (size < 0) {
		std::cerr << "Array::Array: size is negative, invert...\n";
		m_size = -size;

	}
	else {
		m_size = size;
	}

	m_array = new int[m_size];

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
	std::cout << *this;
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

std::istream& operator>>(std::istream& stream, Array& arr) {
	for (int i = 0; i < arr.Size() - 1; i++) {
		stream >> arr[i];
	}
	return stream;
}

void Array::Resize(int size) {
	if (size < 0) {
		std::cerr << "Array::Array: size is negative, invert...\n";
		size = -size;
	}
	Array res(size);

	int cout = std::min(m_size, size);
	for (int i = 0; i < cout; i++) {
		res.m_array[i] = m_array[i];
	}
	res.Swap(*this);
}

void Array::Sorting() {
	for (int s = (m_size / 2) + 1; s > 0; s /= 2) {
		for (int i = s; i < m_size; ++i) {
			for (int j = i - s; j >= 0 && m_array[j] > m_array[j + s]; j -= s) {
				int temp = m_array[j];
				m_array[j] = m_array[j + s];
				m_array[j + s] = temp;
			}
		}
	}
}

bool Array::Insert(int element, int index) {
	if (index>=0 && index<=m_size) {
		Array res((m_size + 1));

		for (int i = 0; i < index; i++) {
			res.m_array[i] = m_array[i];
		}
		res.m_array[index] = element;
		for (int i = index+1; i < res.m_size; i++) {
			res.m_array[i] = m_array[i-1];
		}
		res.Swap(*this);
		return true;
	}
	else {
		std::cerr << "Index is incorrect\n";
		return false;
	}
}

bool Array::DeleteIndex(int index) {
	if (index>0 &&index < m_size) {
		Array res((m_size-1));

		for (int i = 0; i < index; i++) {
			res.m_array[i] = m_array[i];
		}
		for (int i = index+1; i < m_size; i++) {
			res.m_array[i-1] = m_array[i];
		}
		res.Swap(*this);
		return true;
	}
	else {
		std::cerr << "Index is incorrect\n";
		return false;
	}
}

bool Array::DeleteValue(int element) {
	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == element) {
			Array res((m_size - 1));

			for (int j = 0; j < i; j++) {
				res.m_array[j] = m_array[j];
			}
			for (int j = i + 1; j < m_size; j++) {
				res.m_array[j - 1] = m_array[j];
			}
			res.Swap(*this);
			return true;
		}
	}
	return false;
}

void Array::DeleteAllValue(int element) {
	for (int i = (m_size-1); i >=0; i--) {
		if (m_array[i] == element) {
			Array res(m_size - 1);

			for (int j = res.m_size; j >= i; j--) {
				res.m_array[j] = m_array[j+1];
			}
			for (int j = i-1; j >=0 ; j--) {
				res.m_array[j] = m_array[j];
			}
			res.Swap(*this);
		}
	}
}

int Array::Max() {
	int max = m_array[0];
	for (int i = 1; i < m_size; i++) {
		if (max < m_array[i])
		{
			max =m_array[i];
		}
	}
	return max;
}

int Array::Min() {
	int min = m_array[0];
	for (int i = 1; i < m_size; i++) {
		if (min > m_array[i])
		{
			min = m_array[i];
		}
	}
	return min;
}

Array Array:: operator +(const int value)const
{
	Array tmp_Array(m_size + 1);
	for (int i = 0; i < m_size; ++i)
	{
		tmp_Array.m_array[i] = m_array[i];
	}
	tmp_Array.m_array[m_size] = value;
	return tmp_Array;
}

Array& Array:: operator+=(int value) {
	Array tmp = *this + value;
	Swap(tmp);
	return *this;
}