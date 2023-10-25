#include<iostream>
#include<stdio.h>
#include"Array.h"
template <typename ItemType>
double calculateAvg(Array<ItemType> arr)
{
	double avg = 0;
	for (int i = 0; i < arr.Size(); ++i)
	{
		avg += arr[i];
	}
	avg /= arr.Size();
	return avg;
}

template <typename ItemType>
int main() {
	srand(time(0));
	Array<int> arr(10, 2), arr2, arr3, arr4, arr5(5), arr6(5), arr7(5);
	arr5[0] = 25;
	arr5[4] = 25;
	std::cout << arr[3] << " " << arr[9] << std::endl;
	arr[0] = 3;
	arr[4] = arr[3];
	std::cout << "Average value " << calculateAvg(arr) << std::endl;
	std::cout << arr;
	std::cout << "index element '3' = " << arr.Search(3) << std::endl;
	std::cin>>arr2;
	std::cout << "arr2 = " << arr2;
	arr.Swap(arr2);
	std::cout << "arr = " << arr;
	std::cout << "arr2 = " << arr2;
	arr2 += arr;
	std::cout<< "+=: arr2 = " << arr2;
	arr2 = arr2 + 100;
	std::cout << "Array + value: arr2 = " << arr2;
	arr2 += 33;
	std::cout << "Array += value: arr2 = " << arr2;
	std::cout << "== and !=\n";
	return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                         