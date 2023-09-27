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

	
private:
	int *m_array=nullptr;
	int m_size=0;

};

