#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <iostream>  
int BMsearch(int* TAB, std::string text, std::string searchText, int start, int end);
int* GenerationTab(std::string text, std::string searchText);

int main() {
	std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator", searchText = "tor";
	int* TAB;
	TAB=GenerationTab(text,searchText);
	BMsearch(TAB, text, searchText, 0, -1);
}

int BMsearch(int* TAB, std::string text, std::string searchText,int start,int end) {
	if (end<0 || end>text.length()) end = text.length();

	if (start<0 || start>text.length()) start = 0;

	int k = 0, i, j,m;
	m = searchText.length();
	for (i = m - 1 + start, j = m - 1; i < end; i = k + TAB[text[k]])
	{
		for (k = i, j = m - 1; j >= 0;) {
			if (text[k] == searchText[j]) { k = k - 1, j = j - 1; }
			else { break; }
		}
		if (j < 0) { return k + 1; }
		if (k >= end) return-1;
	}

	if (j < 0) return k + 1;

	return -1;
}

int* GenerationTab(std::string text, std::string searchText) {
	int i, m;
	int* TAB=new int[256];

	m = searchText.length();

	for (i = 0; i < 256; i++) TAB[i]= m;

	for (i = 0; i < m - 1; i++) TAB[searchText[i]]= m - 1 - i;
	return TAB;
}
