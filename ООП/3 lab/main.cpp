#include<string>

#include "BoolVector.h"

int main()
{
	BoolVector v0;
	BoolVector v1(76, 1);
	for (int i = 0; i <= v1.Lenght(); ++i) {
		std::cout << (v1 << i);
	}
	std::cout << "==============================" << std::endl;
	for (int i = 0; i <= v1.Lenght(); ++i) {
		std::cout << (v1 >> i);
	}
	BoolVector v2(v1);
	v2.Set0(1, 1);
	v1.Set1(3, 1);
	v0.Swap(v2);
	std::cout << (v1 << 9);
	std::cout << "==============================" << std::endl;
	for (int i = 0; i <= v0.Lenght(); ++i) {
		std::cout << (v0<<i);
	}
	 v2.Invert();
	 int a = v2.Weight();

	 BoolVector v3(v1);
	 v3.Set1All();
	 v2 =v3 & v1;
	return 0;
}