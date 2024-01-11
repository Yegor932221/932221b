#include<iostream>
#include"Set.h"

int main()
{
	Set first("Let try");
	std::cout<< first;
	std::cout<<"Min=" << first.Min() << std::endl;
	std::cout<<"Max=" << first.Max() << std::endl;
	Set second("Wrong");
	if (first == second) std::cout << "same" << std::endl;
	else std::cout << "different" << std::endl;
	second = first;
	if (first == second) std::cout << "same" << std::endl;
	else std::cout << "different" << std::endl;
	return 0;
}