#include<iostream>
#include "List.h"
#include<list>

int main() {
	List<int> first(15, 100);
	List<int> second(first);
	second.PopBack();
	
}