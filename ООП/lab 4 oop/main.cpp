#include<stdio.h>
#include "BoolMatr.h"
int main() {
	BoolMatr matr;
	int a = 5, b = 9;
	BoolMatr second_matr(a, b, true);
	BoolMatr matr3(a, b, true);

	BoolMatr third(3,7,true);
	a=third.GetCountColumns();
	b = second_matr.GetCountRows();
	
	matr.Swap(second_matr);

	std::cout << matr3;

	matr3.MatrDisjunction();

	second_matr.MatrConjunction();
	matr3 = second_matr;
	return 0;
}