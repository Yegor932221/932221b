#include<iostream>
#include<string>
#include <random>
#include<time.h>
#include<vector>
#include<fstream>
#include<chrono>
void RandMasAny(int b, int c, int n, FILE* mass);
void OutputMus(int a[], int n);
void Shell1(int* array, int size);
void Shell2(int* array, int size);
void Shell3(int* array, int size);


int main(){
	std::vector<int> arr;
	int i;
	FILE* mass;
	
	for (int range = 10; range <= 100'000; range *=100) {
		for (int size = 10'000; size <= 1'000'000; size *=10) {
			std::string name = "Shell" + std::to_string(size) + "_in_range_" + std::to_string(range) +".txt";
			const char* file = name.c_str();
			fopen_s(&mass,file, "r");
			if (mass == NULL)
			{
				perror("error opening file");
				getchar();
				exit(-1);
			}
			for (int i = 0; i < size; i++) {
				fgets()
			}
		}
	}
	return 0;
}


void RandMasAny(int b, int c, int n, FILE* mass)
{
	std::random_device rd;   
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(b,c);
	for (int i = 0; i < n; i++) {
		fprintf(mass, "%d ", dist(gen));
	}
}

void OutputMus(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d  ", a[i]);
}

void Shell1(int* array, int size) {
	for (int s = size / 2; s > 0; s /= 2) {
		for (int i = s; i < size; ++i) {
			for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
				int temp = array[j];
				array[j] = array[j + s];
				array[j + s] = temp;
			}
		}
	}
}


void Shell2(int* array, int size) {
	for (int s = (size / 2)+1; s > 0; s /= 2) {
		for (int i = s; i < size; ++i) {
			for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
				int temp = array[j];
				array[j] = array[j + s];
				array[j + s] = temp;
			}
		}
	}
}

void Shell3(int* array, int size) {
	int s = size,m;
	for (; s > 0;) {
		for (int i = s; i < size; ++i) {
			for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
				int temp = array[j];
				array[j] = array[j + s];
				array[j + s] = temp;
			}
		}
		if (s == 1)break;
		m = (s*5 - 1) / 11;
		s = std::max(m, 1);
	}
}