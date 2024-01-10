
#include "List.h"
#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>

template <typename ItemType>
List<ItemType>::List(const int length,const ItemType& value) {
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
	for (Node* tmp_ptr = other.m_head->m_next; tmp_ptr != other.m_tail; tmp_ptr = tmp_ptr->m_next)
	{
		PushBack(tmp_ptr->m_value);
	}
	m_length = other.m_countNode;
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
List<ItemType>::Iterator List<ItemType>::End(){
	return Iterator(this, m_tail);
}

template <typename ItemType>typename
List<ItemType>::Iterator List<ItemType>:: Begin(){
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
	it.m_node->m_next->m_prev = it.m_node->m_prev;
	it.m_node->m_prev->m_next = it.m_node->m_next;
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
	if (m_head->m_next == m_tail)
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

template <typename ItemType>
void List<ItemType>::InsertNode(Iterator& it, const ItemType& value) {
	Node* q = new Node;
	q->m_value = value;
	q->m_next = it.m_pos;
	q->m_before = it.m_pos->m_prev;
	it.m_pos->m_prev->m_next = q;
	it.m_pos->m_prev = q;
	m_length++;
}

template<typename Type>
void List<Type>::MakeEmptyList()
{
	m_head = new Node;
	m_tail = new Node;
	m_head->m_next = m_tail;
	m_head->m_prev = nullptr;
	m_tail->m_next = nullptr;
	m_tail->m_prev = m_head;
}

