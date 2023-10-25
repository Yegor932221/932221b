#include<iostream>
#include<string>
#include <random>
#include<time.h>
#include<vector>
#include<fstream>
#include<chrono>
void Shell1(std::vector<int> &array);
void Shell2(std::vector<int> &array);
void Shell3(std::vector<int> &array);
void CopyArrayFromFile(const char* name, std::vector<int> &arr);
void InsertWithStep(std::vector<int>& arr, int s);
bool ArrayCheck(std::vector<int> &arr);


int main(){
	for (int j = 0; j < 3; j++)
	{
			std::vector<int> arr;
			FILE* mass;
			float time = 0;
			for (int range = 10; range <= 100'000; range *= 100)
			{
				for (int size = 10'000; size <= 1'000'000; size *= 10) 
				{
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
					switch (j)
					{
						case 0:
						Shell1(arr);
						break;

						case 1:
						Shell2(arr);
						break;

						case 2:
						Shell3(arr);
						break;

						default:
						break;
					}
					if (ArrayCheck(arr) == 0)
					{
						std::cerr << "Don't sorted";
						break;
					}
					auto end = std::chrono::high_resolution_clock::now();
					float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
					time += time1;
				}
			}
		std::cout << time;
		switch (j)
		{
		case 0:
			std::cout << "\n" << "Sorting Time Shell1 (n/2):" << time << "\n";
			break;
		case 1:
			std::cout << "\n" << "Sorting Time Shell2 ((n/2)+1):" << time << "\n";
			break;
		case 2:
			std::cout << "\n" << "Sorting Time Shell3 ((n*5 - 1) / 11):" << time << "\n";
			break;
		default:
			break;
		}
	}
	return 0;
}

void Shell1(std::vector<int> &array) {
	for (int s = array.size() / 2; s > 0; s /= 2) {
		InsertWithStep(array, s);
	}
}


void Shell2(std::vector<int> &array) {
	for (int s = (array.size() / 2)+1; s > 0; s /= 2) {
		InsertWithStep(array, s);
	}
}

void Shell3(std::vector<int> &array) {
	int s = array.size(),m;
	for (; s > 0;) {
		InsertWithStep(array, s);
		if (s == 1)break;
		m = (s*5 - 1) / 11;
		s = std::max(m, 1);
	}
}

void CopyArrayFromFile(const char* name, std::vector<int> &arr) {
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

void InsertWithStep(std::vector<int>& arr, int s)
{
	int i, j, k, key;
	for (i = 0; i < s; i++)
	{
		for (j = i + s; j<arr.size(); j += s)
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
	for(int i=0;i<arr.size()-1;i++)
		{
		if (arr[i] > arr[i + 1])
			return false;
		}
	return true;
}
