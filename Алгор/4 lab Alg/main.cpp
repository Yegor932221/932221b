#include<iostream>
#include<string>
#include <random>
#include<time.h>
#include<vector>
#include<fstream>
#include<chrono>
void CopyArrayFromFile(const char* name, std::vector<int>& arr);
void HeapSort(std::vector<int>& arr);
bool ArrayCheck(std::vector<int>& arr);
void CreateHeap(std::vector<int>& arr);
void Sifting(std::vector<int>& arr, int size, int index);



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
					HeapSort(arr);
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
				std::cout<< std::endl;
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

bool ArrayCheck(std::vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void HeapSort( std::vector<int>& arr) {
	CreateHeap(arr);
	for (int j = arr.size() - 1; j > 0; j--)
	{
		std::swap(arr[0], arr[j]);
		Sifting(arr, j, 0);
	}
}

void CreateHeap(std::vector<int>& arr)
{
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; i--)
		Sifting(arr,n, i);
}

void Sifting(std::vector<int>& arr,int size, int index)
{
	int flag = 1, tmp = arr[index];
	for(int descendant = 2 * index + 1;descendant < size && flag;)
	{
		if ((descendant + 1) < size)
		{
			if (arr[descendant + 1] > arr[descendant])
				descendant++;
		}
		if (arr[descendant] > tmp)
		{
			arr[index] = arr[descendant];
			index = descendant;
			descendant = 2 * index + 1;
		}
		else
			flag = 0;
	}
	arr[index] = tmp;
}