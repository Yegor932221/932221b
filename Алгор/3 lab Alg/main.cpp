#include<iostream>
#include<string>
#include <random>
#include<time.h>
#include<vector>
#include<fstream>
#include<chrono>
void ShellClassic(std::vector<int> &array);
void ShellFrankLazarus(std::vector<int> &array);
void ShellGonneBaezaYates(std::vector<int>& array);
void CopyArrayFromFile(const char* name, std::vector<int> &arr);
void InsertWithStep(std::vector<int>& arr, int step);
bool ArrayCheck(std::vector<int> &arr);


int main(){
	for (int j = 0; j < 3; j++)
	{
		switch (j)
		{
		case 0:
			std::cout << "\n" << "Sorting Time Shell Classic (n/2):" << "\n";
			break;
		case 1:
			std::cout << "\n" << "Sorting Time Shell Frank & Lazarus ((n/2)+1):" << "\n";
			break;
		case 2:
			std::cout << "\n" << "Sorting Time Shell Gonnet & Baeza-Yates((n*5 - 1) / 11):" << "\n";
			break;
		default:
			break;
		}
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
					for (int k = 0; k < 3; k++)
					{
						auto start = std::chrono::high_resolution_clock::now();
					switch (j)
					{
					case 0:
						ShellClassic(arr);
						break;

					case 1:
						ShellFrankLazarus(arr);
						break;

					case 2:
						ShellGonneBaezaYates(arr);
						break;

					default:
						break;
					}
					auto end = std::chrono::high_resolution_clock::now();
					float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
					if (!ArrayCheck(arr))
					{
						std::cerr << "Don't sorted";
						break;
					}
					std::cout << size << " elements in range +/-" << range << " time=" << time1 << " millisecond" << std::endl;
					time += time1;
					_fcloseall();
					}

					time =time/3;
					std::cout << std::endl << size << " elements in range +/-" << range << " MIDLtime=" << time << " millisecond" << std::endl << std::endl;
				}
			}
	}
	return 0;
}

void ShellClassic(std::vector<int> &array) {
	for (int step = array.size()/2 ; step > 0; step /= 2)
		InsertWithStep(array, step);

}


void ShellFrankLazarus(std::vector<int> &array) {
	for (int step = 2*(array.size() / 4) + 1; step > 0; step /= 2) {
		InsertWithStep(array, step);
	}
}

void ShellGonneBaezaYates(std::vector<int> &array) {
	int step = array.size(),m;
	step = (step * 5 - 1) / 11;
	for (; step > 0;) {
		InsertWithStep(array, step);
		if (step == 1)break;
		m = (step*5 - 1) / 11;
		step = std::max(m, 1);
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

void InsertWithStep(std::vector<int>& arr, int step)
{
	for (int i = 0; i < step; i++)
	{
		for (int j = i + step; j < arr.size(); j += step)
		{
			int key = arr[j];
			int k = j - step;
			while (k >= 0 && arr[k] > key)
			{
				arr[k + step] = arr[k];
				k -= step;
			}
			arr[k + step] = key;
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
