#include <iostream> 
#include<vector>

int BMsearch(int* TAB, std::string text, std::string searchText, int start, int end);
int* GenerationTab(std::string text, std::string searchText);
std::vector<int> BMall(int* TAB, std::string text, std::string searchText);
std::vector<int> BMinRange(int* TAB, std::string text, std::string searchText,int start,int end);

int main() {
	int firstEl;
	std::vector<int> All, inRange;
	std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator", searchText = "tor";
	int* TAB;
	TAB=GenerationTab(text,searchText);

	firstEl=BMsearch(TAB, text, searchText, -1, -1);
	if (firstEl < 0) std::cout << "Item not found" << std::endl;
	else std::cout << "The element you are looking for is included under the index:" << firstEl << "\n";

	All = BMall(TAB, text, searchText);
	std::cout << "The required element is the entry under the indices:";
	for (int elements : All)
		std::cout << elements << " ";

	inRange = BMinRange(TAB, text, searchText, 0, 91);
	std::cout <<"\n" << "The required element in the range 0-91 is the entry under the indices:";
	for (int elements : inRange)
		std::cout << elements << " ";

	inRange = BMinRange(TAB, text, searchText, 17,91);
	std::cout <<"\n" << "The required element in the range 17-91 is the entry under the indices:";
	for (int elements : inRange)
		std::cout << elements << " ";

	inRange = BMinRange(TAB, text, searchText, 28, 36);
	std::cout <<"\n"<< "The required element in the range 28-36 is the entry under the indices:";
	for (int elements : inRange)
		std::cout << elements << " ";
	return 0;
}

int BMsearch(int* TAB, std::string text, std::string searchText,int start,int end) {
	int n = text.length();
	if (end<0) end = text.length();

	if (start<0 || start > n) start = 0;

	int k = 0, i, j,m;
	m = searchText.length();
	for (i = m - 1 + start, j = m - 1; i <= end; i = k + TAB[text[k]])
	{
		for (k = i, j = m - 1; j >= 0 && text[k] == searchText[j];) { k = k - 1, j = j - 1; }
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

std::vector<int> BMall(int* TAB, std::string text, std::string searchText) {
	 int s;
	 std::vector<int> Occurrences;
	 int occurrences = BMsearch(TAB, text, searchText, -1, -1);

	 if(occurrences<0) return Occurrences;
	 s = occurrences + 1;
	 for (; occurrences >= 0; s = occurrences + 1) {
		 Occurrences.push_back(occurrences);
		 occurrences = BMsearch(TAB, text, searchText, s, -1);
	 }

	 return Occurrences;
}

std::vector<int> BMinRange(int* TAB, std::string text, std::string searchText,int start,int end) {
	int s;
	std::vector<int> Occurrences;
	int occurrences = BMsearch(TAB, text, searchText, start, end);

	if (occurrences < 0) return Occurrences;
	s = occurrences + 1;
	for (; occurrences >= 0; s = occurrences + 1) {
		Occurrences.push_back(occurrences);
		occurrences = BMsearch(TAB, text, searchText, s, end);
	}

	return Occurrences;
}