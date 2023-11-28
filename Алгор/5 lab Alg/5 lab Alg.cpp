#include<iostream>
#include<string>
#include <random>
#include<time.h>
#include<vector>
#include<fstream>
#include<chrono>
void CopyArrayFromFile(const char* name, std::vector<int>& arr);
bool ArrayCheck(std::vector<int>& arr);
void HoarSort(std::vector<int>& arr, int l, int r);


int main() {
	std::vector<int> arr;
	for (int range = 10; range <= 100000; range *= 100)
	{
		for (int size = 10000; size <= 1000000; size *= 10)
		{
			float time = 0;
			FILE* mass;
			std::string name = "Shell" + std::to_string(size) + "_in_range_" + std::to_string(range) + ".txt";
			const char* file = name.c_str();
			fopen_s(&mass, file, "r");
			if (mass == NULL)
			{
				perror("error opening file");
				getchar();
				exit(-1);
			}
			CopyArrayFromFile(file, arr);
			for (int k = 3; k != 0; k--) {
				auto start = std::chrono::high_resolution_clock::now();
				HoarSort(arr,0,(arr.size()-1));
				auto end = std::chrono::high_resolution_clock::now();
				float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
				if (!ArrayCheck(arr))
				{
					std::cerr << "Don't sorted";
					break;
				}
				time += time1;
				std::cout << size << " elements in range +/-" << range << " time=" << time1 << " millisecond" << std::endl << std::endl;
			}
			time /= 3;
			std::cout << size << " elements in range +/-" << range << " MidlTime=" << time << " millisecond" << std::endl << std::endl;
			std::cout << std::endl;
			_fcloseall();
		}
	}
}

void CopyArrayFromFile(const char* name, std::vector<int>& arr) {
	std::ifstream fin(name);
	int n;
	if (!fin.good())
		std::cout << "File not found!" << std::endl;
	else
	{
		while (fin >> n)
			arr.push_back(n);
	}
	fin.close();
}

bool ArrayCheck(std::vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void HoarSort(std::vector<int>& arr, int l, int r) {
	if (l >= r)
		return;
	int i = l;
	int j = r;
	int x = arr[(l+r)/2	];
	while (i <= j) {
		while (arr[i] < x) i++;
			while (arr[j] > x) j--;
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}		
	}
	HoarSort(arr, l, j);
	HoarSort(arr, i, r);
}