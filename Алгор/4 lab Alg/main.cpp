#include<iostream>
#include<string>
#include <random>
#include<time.h>
#include<vector>
#include<fstream>
#include<chrono>
void CopyArrayFromFile(const char* name, std::vector<int>& arr);
void InsertWithStep(std::vector<int>& arr, int s, int n);
bool ArrayCheck(std::vector<int>& arr);
void ShellClassic(std::vector<int>& array, int n);



int main() {
		std::vector<int> arr;
		for (int range = 10; range <= 100'000; range *= 100)
		{
			for (int size = 10'000; size <= 1'000'000; size *= 10)
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
				auto start = std::chrono::high_resolution_clock::now();

				if (ArrayCheck(arr) == 0)
				{
					std::cerr << "Don't sorted";
					break;
				}
				auto end = std::chrono::high_resolution_clock::now();
				float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
				time += time1;
				std::cout << size << " elements in range +/-" << range << " time=" << time << " millisecond" << std::endl;
				_fcloseall();
			}
		}
	return 0;
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

void InsertWithStep(std::vector<int>& arr, int s, int n)
{
	int i, j, k, key;
	for (i = n; i < s; i++)
	{
		for (j = i + s; j < arr.size(); j += s)
		{
			key = arr[j];
			k = j - s;
			while (k >= 0 && arr[k] > key)
			{
				arr[k + s] = arr[k];
				k -= s;
			}
			arr[k + s] = key;
		}
	}
}

bool ArrayCheck(std::vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void HeapSort(const char* name, std::vector<int>& arr) {
	int i = (arr.size()/2)-1;
	ShellClassic(arr, i);
	for (int k = 0; k <= arr.size(); k++) {
		for (int j = i * 2 + 1; j < arr.size();) {
			if (j + 1 < arr.size()) break;
			if()
		}

	}
}

void ShellClassic(std::vector<int>& array, int n) {
	int step = array.size() / 2;
	for (; step > 0; step /= 2)
		InsertWithStep(array, step, n);

}