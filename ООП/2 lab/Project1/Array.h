#pragma once
template <typename ItemType>
class Array
{
public:
	//template<typename IT, typename AT>
	//class Iterator;
	//typedef Iterator<ItemType, Array> TmpIterator;
	//typedef Iterator<const ItemType, const Array> TmpConstIterator;

	Array(const int size = 10, const ItemType &value = 0);
	
	Array(const Array& other);

	Array(Array&& other);

	~Array();

	ItemType &operator[](const int index);

	const ItemType& operator[](const int index) const;

	Array &operator=(const Array& other);

	Array& operator=(Array&& other);

	void Print() const;

	int Size() const;

	int Search(ItemType l);

	Array& operator+(const Array& other) const;

	Array& operator+=(const Array& other);

	void Swap(Array& other);

	void Resize(int size);

	void Sorting();

	bool Insert(const ItemType& element, int index);

	bool DeleteIndex(int index);

	bool DeleteValue(const ItemType element);

	void DeleteAllValue(const ItemType element);

	ItemType Max() const;

	ItemType Min() const;

	Array operator +(const ItemType value)const;

	Array& operator+=(const ItemType& value);

	
private:
	ItemType*m_array=nullptr;
	int m_size=0;

};
template <typename ItemType>
std::ostream& operator<<(std::ostream& stream, const Array<ItemType>& arr);
template <typename ItemType>
std::istream& operator>>(std::istream& stream, Array<ItemType>& arr);