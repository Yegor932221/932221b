#include<iostream>
#include<stdio.h>
#include"Array.h"

double calculateAvg(Array arr) {

	if (arr.Size() == 0) {
		return 0;
	}

	double avg = 0;

	for (int i = 0; i < arr.Size(); ++i) {
		avg += arr[i];
	}

	avg /= arr.Size();
	return avg;
}

int main() {
	Array arr( 10, 1 );
	std::cout << arr[1] << ' ' << arr[4] << std::endl;
	arr[6] = 5;
	arr[1] = 4;
	arr[4] = 4;
	arr[9] = 4;
	arr[3] = 9;
	arr.Insert(222, 2);

	arr.Print();
	return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                         