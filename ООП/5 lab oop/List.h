
#include<stdint.h>
#include<iostream>
#include<assert.h>
#include"C:\Users\����\932221b\���\2 lab\Project1\Array.h"

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
	TmpIterator(LT* list = nullptr, Node* node = nullptr);
private:
	LT* m_list=nullptr;
	Node* m_node=nullptr;
};
