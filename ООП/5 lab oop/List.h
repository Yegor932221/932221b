#include<assert.h>
#include<string.h>
#include<string>
#include<stdint.h>
#include<iostream>
#include<assert.h>
#include"C:\Users\Åãîð\932221b\ÎÎÏ\2 lab\Project1\Array.h"

template <typename ItemType>
class List
{
public:
	template<typename IT, typename LT>
	class TmpIterator;
	using Iterator = TmpIterator<ItemType, List>;
	using ConstIterator = TmpIterator<const ItemType, const List>;

	class Node;
	List(const int length=0,const ItemType& value=ItemType());
	List(const Array<ItemType>& array);
	List(const List& other);
	~List();


	void PushBack(const ItemType& value);
	Iterator End();
	Iterator Begin();
	ConstIterator End() const;
	ConstIterator Begin() const;
	void DeleteNode(Iterator& it);
	void Clear();
	bool Empty()const;
	void PopBack();
	int Size()const;
	void Swap(List& other);
	Iterator Search(const ItemType& value);
	void PushFront(const ItemType& value);
	void PushPosition(const int pos, const ItemType& value);
	void PushAfterKey(const ItemType& key, const ItemType& value);
	void PopFront();
	void PopPosition(const int pos);
	void PopAfterKey(const ItemType& key);
	ItemType Min()const;
	ItemType Max()const;
	void Sorting();
	const ItemType& operator[](const int index)const;
	List<ItemType>& operator=(const List& other);
	bool operator==(const List& other)const;
	bool operator!=(const List& other)const;
	List<ItemType>& operator+=(const List& other)const;
	List<ItemType> operator+(const List& other)const;
private:
	void InsertNode(Iterator& it, const ItemType& value);
	void MakeEmptyList();

	Node* m_head=nullptr;
	Node* m_tail=nullptr;
	int m_length=0;
};


template<typename ItemType>
std::ostream& operator<<(std::ostream& stream, const List<ItemType>& list);
template<typename ItemType>
std::istream& operator>>(std::istream& stream, List<ItemType>& list);


template <typename ItemType>
class  List<ItemType>::Node {
	friend List;
private:
	Node* m_befor=nullptr;
	Node* m_after=nullptr;
	ItemType m_value;
};

template <typename ItemType>
template<typename IT, typename LT>
class List<ItemType>::TmpIterator {
	friend List;
public:
	TmpIterator& operator--();
	TmpIterator(LT* list = nullptr, Node* node = nullptr);
private:
	LT* m_list=nullptr;
	Node* m_node=nullptr;
};

template <typename ItemType>
List<ItemType>::List(const int length, const ItemType& value) {
	MakeEmptyList();
	for (int i = 0; i < length; ++i)
		PushBack(value);
}

template <typename ItemType>
List<ItemType>::List(const Array<ItemType>& array) {
	MakeEmptyList();
	for (int i = 0; i < array.Size(); ++i)
	{
		PushBack(array[i]);
	}
	m_length = array.Size();
}

template <typename ItemType>
List<ItemType>::List(const List& other) {
	MakeEmptyList();
	for (Node* tmp_ptr = other.m_head->m_after; tmp_ptr != other.m_tail; tmp_ptr = tmp_ptr->m_after)
	{
		PushBack(tmp_ptr->m_value);
	}
	m_length = other.m_length;
}

template<typename ItemType>
List<ItemType>::~List()
{
	Clear();
	delete m_tail;
	delete m_head;
}


template <typename ItemType>
void List<ItemType>::PushBack(const ItemType& value) {
	auto it = End();
	InsertNode(it, value);
}

template <typename ItemType>typename
List<ItemType>::Iterator List<ItemType>::End() {
	return Iterator(this, m_tail);
}

template <typename ItemType>typename
List<ItemType>::Iterator List<ItemType>::Begin() {
	return Iterator(this, m_head->m_next);
}

template <typename ItemType>typename
List<ItemType>::ConstIterator List<ItemType>::End() const {
	return ConstIterator(this, m_tail);
}

template <typename ItemType>typename
List<ItemType>::ConstIterator List<ItemType>::Begin() const {
	return ConstIterator(this, m_head->m_next);
}

template<typename ItemType>
void List<ItemType>::DeleteNode(Iterator& it)
{
	it.m_node->m_after->m_befor = it.m_node->m_befor;
	it.m_node->m_befor->m_after = it.m_node->m_after;
	delete it.m_node;
	--m_length;
}

template<typename ItemType>
void List<ItemType>::Clear()
{
	while (!Empty())
	{
		PopBack();
	}
}

template<typename Type>
bool List<Type>::Empty()const
{
	if (m_head->m_after == m_tail)
		return true;
	else
		return false;
}

template<typename Type>
void List<Type>::PopBack()
{
	if (!Empty())
	{
		auto it = End();
		--it;
		DeleteNode(it);
	}
}

template<typename Type>
int List<Type>::Size()const {
	return m_length;
}

template<typename Type>
void List<Type>::Swap(List& other)
{
	std::swap(m_head, other.m_head);
	std::swap(m_tail, other.m_tail);
	std::swap(m_length, other.m_length);
}

template<typename ItemType>typename
List<ItemType>::Iterator List<ItemType>::Search(const ItemType& value)
{
	auto it = Begin();
	while (it != End())
	{
		if (*it == value)
			return it;
		++it;
	}
	return it;
}

template<typename ItemType>
void List<ItemType>::PushFront(const ItemType& value)
{
	auto it = Begin();
	InsertNode(it, value);
}

template<typename ItemType>
void List<ItemType>::PushPosition(const int pos, const ItemType& value)
{
	assert(pos < m_length);
	auto it = Begin();
	for (int i = 1; i < pos; ++i)
	{
		++it;
	}
	InsertNode(it, value);
}

template<typename ItemType>
void List<ItemType>::PushAfterKey(const ItemType& key, const ItemType& value)
{
	auto it = Search(key);
	it++;
	if (it != End())
	{
		InsertNode(it, value);
	}
}

template<typename ItemType>
void List<ItemType>::PopFront()
{
	auto it = Begin();
	DeleteNode(it);
}

template<typename ItemType>
void List<ItemType>::PopPosition(const int pos)
{
	assert(pos < m_length);
	auto it = Begin();
	for (int i = 1; i < pos; ++i)
	{
		++it;
	}
	DeleteNode(it);
}

template<typename ItemType>
void List<ItemType>::PopAfterKey(const ItemType& key)
{
	auto it = Search(key);
	it++;
	if (it != End())
	{
		DeleteNode(it);
	}
}

template<typename ItemType>
ItemType List<ItemType>::Min()const
{
	assert(m_length > 0);
	ItemType min = m_head->m_next->m_value;
	Node* tmp_it = m_head->m_next;
	while (tmp_it != m_tail)
	{
		if (tmp_it->m_value < min)
			min = tmp_it->m_value;
		tmp_it = tmp_it->m_next;
	}
	return min;
}

template<typename ItemType>
ItemType List<ItemType>::Max()const
{
	assert(m_length > 0);
	ItemType max = m_head->m_next->m_value;
	Node* tmp_it = m_head->m_next;
	while (tmp_it != m_tail)
	{
		if (tmp_it->m_value > max)
			max = tmp_it->m_value;
		tmp_it = tmp_it->m_next;
	}
	return max;
}

template<typename ItemType>
void List<ItemType>::Sorting()
{
	for (auto it = Begin(); it != End(); ++it)
		for (auto jt = Begin(); jt != End(); ++jt)
			if (*it < *jt)
				std::swap(it.m_node->m_value, jt.m_node->m_value);
}

template<typename ItemType>
std::ostream& operator<<(std::ostream& stream, const List<ItemType>& list)
{
	for (int i = 0; i < list.Size(); ++i)
	{
		stream << list[i] << "<=>";
	}
	return stream;
}

template<typename ItemType>
std::istream& operator>>(std::istream& stream, List<ItemType>& list)
{
	for (int i = 0; i < list.Size(); ++i)
	{
		stream >> list[i];
	}
	return stream;
}

template<typename Type>
const Type& List<Type>::operator[](const int index)const
{
	assert(index < m_length);
	Node* tmp_it = m_head->m_next;
	for (int i = 0; i < index; ++i)
	{
		tmp_it = tmp_it->m_next;
	}
	return tmp_it->m_value;
}

template<typename ItemType>
List<ItemType>& List<ItemType>::operator=(const List& other)
{
	if (m_head == other.m_head)
		return *this;
	Clear();
	for (const ItemType& value : other)
	{
		PushBack(value);
	}
	return *this;
}

template<typename ItemType>
bool List<ItemType>::operator==(const List& other)const
{
	if (m_length == other.m_length)
		return false;
	else if (m_head == other.m_head)
		return true;
	else
	{
		for (auto it = Begin(), jt = other.Begin(); it != End() && jt != other.End(); ++it, ++jt)
		{
			if (*it != *jt)
				return false;
		}
		return true;
	}
}

template<typename Type>
bool List<Type>::operator!=(const List& other)const
{
	return !(*this == other);
}

template<typename ItemType>
List<ItemType>& List<ItemType>::operator+=(const List& other)const {

	for (auto it = other.Begin(); it != other.End(); ++it)
	{
		PushBack(*it);
	}
	return *this;

}

template<typename ItemType>
List<ItemType> List<ItemType>::operator+(const List& other)const
{
	List res(*this);
	res += other;
	return res;
}

template <typename ItemType>
void List<ItemType>::InsertNode(Iterator& it, const ItemType& value) {
	Node* q = new Node;
	q->m_value = value;
	q->m_after = it.m_node;
	q->m_befor = it.m_node->m_befor;
	it.m_node->m_befor->m_after = q;
	it.m_node->m_befor = q;
	m_length++;
}

template<typename Type>
void List<Type>::MakeEmptyList()
{
	m_head = new Node;
	m_tail = new Node;
	m_head->m_after = m_tail;
	m_head->m_befor = nullptr;
	m_tail->m_after = nullptr;
	m_tail->m_befor = m_head;
}

template<typename ItemType>
template<typename IT, typename LT>
List<ItemType>::TmpIterator<IT, LT>& List<ItemType>::TmpIterator<IT, LT>::operator--()
{
	m_node = m_node->m_befor;
	return *this;
}