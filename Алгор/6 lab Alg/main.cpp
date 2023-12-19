#include<iostream>
#include<string>
#include <random>
#include<time.h>
#include<vector>
#include<fstream>
#include<chrono>

void CopyArrayFromFile(const char* name, std::vector<int>& arr);
bool ArrayCheck(std::vector<int>& arr);
void BitSorting(std::vector<int>& arr);
void Breakdown(std::vector<int>& arr, int l, int r, int k);
int Max(std::vector<int> arr);

int main() {
	for (int range = 10; range <= 100000; range *= 100)
	{
		for (int size = 10000; size <= 1000000; size *= 10)
		{
			float time = 0;
			FILE* mass;
			std::vector<int> arr;
			std::string name = "Shell" + std::to_string(size) + "_in_range_" + std::to_string(range) + ".txt";
			const char* file = name.c_str();
			fopen_s(&mass, file, "r");
			if (mass == NULL)
			{
				perror("error opening file");
				getchar();
				exit(-1);
			}
			CopyArrayFromFile(file,arr);
			int max =Max(arr);
			for (int k = 3; k != 0; k--) {
				std::vector<int> copy = arr;
				auto start = std::chrono::high_resolution_clock::now();
				BitSorting(copy);
				auto end = std::chrono::high_resolution_clock::now();
				float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
				if (!ArrayCheck(copy))
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

	return 0;
}

void CopyArrayFromFile(const char* name, std::vector<int>& arr){
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



void Breakdown(std::vector<int>& arr, int l, int r, int k)
{
	if (l >= r || k < 0) return;
	int i = l, j = r;
	int mask = 1 << k;
	while (i <= j)
	{
		while (i <= j && (arr[i] & mask)== 0) i++;
		while (i <= j && (arr[j] & mask)!= 0) j--;
		if (i < j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	Breakdown(arr, l, j, k - 1);
	Breakdown(arr, i, r, k - 1);
}


void BitSorting(std::vector<int>& arr)
{
	int max = Max(arr);
	int k = 0;
	while (max) {
		max >>= 1;
		k++;
	}
	int i = 0;
	int j = arr.size() - 1;
	while (i <= j)
	{
		while (arr[i] < 0) i++;
		while (arr[j] >= 0) j--;
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	Breakdown(arr, 0, j, k);
	Breakdown(arr, i, arr.size() - 1, k);
}

int Max(std::vector<int> arr)
{
	int max = arr[0];
	for (int i = 1; i < arr.size() - 1; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}