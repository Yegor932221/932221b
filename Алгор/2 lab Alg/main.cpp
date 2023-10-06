#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <iostream>  

int main() {
	int TAB[256], i, j, m, n, k;
	std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator", searchText = "tor";
	n = text.length() ; m =searchText.length();

	for (i = 0; i < 256; i++) TAB[i] = m;

	for (i = 0; i < m - 1; i++) TAB[searchText[i]] = m - 1 - i;

	for (i = m - 1, j = m - 1; i < n; i = k + TAB[text[k]]	)
	{
		for (k = i, j = m - 1; j >= 0;) {
			if (text[k] == searchText[j]) { k = k - 1, j = j - 1; }
			else { break; }
		}
		if (j < 0) {return k + 1;}
		if (k >= n) return-1;
	}

	if (j < 0) return k + 1;

	return -1;
}
