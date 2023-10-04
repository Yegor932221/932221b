#pragma once
class Array
{
public:
	Array(const int size=10, const int value=0);
	
	Array(const Array& other);

	~Array();

	int &operator[](const int index);

	const int& operator[](const int index) const;

	Array &operator=(const Array& other);

	void Print() const;

	int Size() const;

	int Search(int l);

	Array& operator+(const Array& other) const;

	Array& operator+=(const Array& other);

	Array& operator=( Array&& other);

	void Swap(Array& other);

	Array (Array&& other);


private:
	int *m_array=nullptr;
	int m_size=0;

};

std::ostream& operator<<(std::ostream& stream, const Array& arr);
std::ostream& operator>>(std::ostream& stream, Array& arr);

