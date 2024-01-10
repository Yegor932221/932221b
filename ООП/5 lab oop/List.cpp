
#include "List.h"
#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>

template <typename ItemType>
List<ItemType>::List(const int length,const ItemType& value) {
	MakeEmptyList();
	for (int i = 0; i < length; i++)
		InsertNode(&this, &value);
}

template <typename ItemType>
List<ItemType>::List(const Array<ItemType>& array) {
	MakeEmptyList();
	for (Node* tmp_ptr = other.m_head->m_next; tmp_ptr != other.m_tail; tmp_ptr = tmp_ptr->m_next)
	{
		PushBack(tmp_ptr->m_value);
	}
	m_countNode = other.m_countNode;
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

