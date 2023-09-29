#include<iostream>
#include <string.h>
#include <time.h>
#include<chrono>
void InputMatrD(int** matr, int m, int n);
void OutputMatrD(int** matr, int m, int n);
void Swap(int* a, int b, int c);
int CostWay(int** matr, int* rearrangement, int numberCities);
void RandomMatr(int** matr, int n);
void Weist(int** matr, int* weist, int numberCities);
bool Cycl(int** ways,int** matr, int k, int numb);

int main() {	
	int first, numberCities, i, j, maxJ, maxI, k=0, cost = 0, lowerCost = 0, full=1;
	int* rearrangement, * cheapest;
	int** matr;
	std::cout << "Enter number of Citiesgg:" << std::endl;
	std::cin >> numberCities;
	std::cout << "Cite start" << std::endl;
	std::cin >> first;

	matr = new int* [numberCities];
	for (i = 0; i < numberCities; i++)
		matr[i] = new int[numberCities];

	rearrangement = new int[numberCities + 1];
	cheapest = new int[numberCities + 1];

	RandomMatr(matr, numberCities);
	std::cout << "Output matr:" << std::endl;
	OutputMatrD(matr, numberCities, numberCities);

	auto start = std::chrono::high_resolution_clock::now();
	rearrangement[0] = first;
	rearrangement[numberCities] = first;
// первая перестановка
	for (i = 1, j = 1; i < numberCities; i++) {
		if (j == first) j++;
		rearrangement[i] = j;
		cheapest[i] = rearrangement[i];
		j++;
	}
	cost = CostWay(matr, rearrangement, numberCities);
	std::cout << std::endl<<"0. ";
	for (i = 0; i < numberCities + 1; i++) std::cout << rearrangement[i] << " ";
	std::cout << std::endl << "cost." << k << ": " << cost << std::endl;
	lowerCost = cost;

	for (i = 1; i < numberCities; i++)full = full * i; //начало полного перебора

		for (k = 1; k < full; k++) {
			maxI = -1; maxJ=-1;

			for (i = 1; i < (numberCities - 1); i++) {
				if (rearrangement[i] < rearrangement[(i + 1)]) maxI = i;
			}

			if (maxI==-1) break;

			for (j =(maxI+1); j <= numberCities - 1; j++) { if (rearrangement[maxI] < rearrangement[j]) maxJ = j; }

			if ( maxJ==-1) break;

			Swap(rearrangement, maxI, maxJ);
			
			j = numberCities - 1;
			i = maxI + 1;

			while (i < j) {
				Swap(rearrangement, i, j);
				i++; j--;
			}
			//следующая перестановка получена
			std::cout << k << ". ";
			for (i = 0; i < numberCities + 1; i++) std::cout << rearrangement[i] << " ";
			cost = CostWay(matr, rearrangement, numberCities);

			std::cout << std::endl << "cost." << k << ": " << cost<<std::endl;

				if (cost < lowerCost) {
					lowerCost = cost;
					for (j = 0; j < numberCities+1; j++)
						cheapest[j] = rearrangement[j];
				}
		}
		auto end = std::chrono::steady_clock::now();
		float time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout << std::endl<<"Time1:"<<time<<std::endl;
	for (i = 0; i < numberCities + 1; i++) std::cout << cheapest[i]<< " ";
	std::cout<<std::endl<<"lowerCost: " << lowerCost;
	std::cout <<std::endl<< "Enter number of Cities: " <<numberCities << std::endl;
	std::cout << "Cite start: " <<first << std::endl;


	OutputMatrD(matr, numberCities, numberCities);
	std::cout << "\n";
	int min,max=0,o=0,ki,kj;
	int cost2 = 0;
	int** shortest;
	shortest = new int*[3];
	for (i = 0; i < 3; i++) {
		shortest[i] = new int[numberCities];
	}

	for (i = 0; i < numberCities; i++)
		for (j = 0; j < numberCities; j++) {
			if (matr[i][j] > max)max = matr[i][j];
		}
	start = std::chrono::high_resolution_clock::now();
	for (k = 0; k < numberCities; k++) {

		min = max;
		shortest[0][k] = 0;
		shortest[1][k] = 0;
		shortest[2][k] = 0;

		for (i = 0; i < numberCities; i++)
			for (j = 0; j < numberCities; j++) {
				if (matr[i][j] != 0 && min > matr[i][j]) {
					shortest[0][k] = i;
					shortest[1][k] = j;
					shortest[2][k] = matr[i][j];
					kj = j;
					ki = i;
					if (Cycl(shortest, matr, k, numberCities) == 1) {
						min = matr[i][j];
						kj = j;
						ki = i;
						shortest[2][k] = matr[i][j];
					}
					else matr[i][j] = 0;
				}
			}
		shortest[0][k] = ki;
		shortest[1][k] = kj;
		for (i = 0,j=0; i < numberCities && j<numberCities;j++, i++)
		{
			matr[ki][i] = 0;
			matr[j][kj] = 0;
		}
		std::cout << "\n" << "min: " << min << "\n";
		OutputMatrD(matr, numberCities, numberCities);
		cost2 += shortest[2][k];
	}
	for(i = 0; i <numberCities;i++)
	{
		std::cout << "(" << shortest[0][i] << "-" << shortest[1][i] << ")\n";
	}
	end = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout << "Cost2: " << cost2;
	std::cout << "\nTime2: " << time;
	std::cout << "\nQuality percentage:" << (lowerCost*100/ cost2) << "%";
	for (i = 0; i < 3; i++) delete[]shortest[i];
	delete[] shortest;
	for (i = 0; i < numberCities; i++) delete[]matr[i];
	delete[] matr;
	delete[] cheapest;
	delete[] rearrangement;
}







void Weist(int** matr,int* weist, int numberCities) {
	for (int i = 0; i < numberCities; i++) {
		int sum = 0;
		for (int j = 0; j < numberCities; j++) {
			sum += matr[i][j];
		}
		weist[i] = sum;
	}
}

void InputMatrD(int** matr, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (i != j) std::cin >> matr[i][j];
			else {
				matr[i][j] = 0;
				printf(" 0 ");
			}
		}
}
void RandomMatr(int** matr, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
	matr[i][j] = 1+(rand() % 20);
	if (i == j)matr[i][j] = 0;
		}
}

int CostWay(int** matr,int* rearrangement, int numberCities) {
	int i,cost=0;
	for (i = 0; i < numberCities; i++) 
		cost += matr[(rearrangement[i]-1)][(rearrangement[i+1]-1)];
	return cost;
}

void OutputMatrD(int** matr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) printf(" %d", matr[i][j]);
		printf("\n");
	}
}

void Swap(int* a, int b, int c) {
	int d = a[b];
	a[b] = a[c];
	a[c] = d;
 }

bool Cycl(int** ways, int** matr, int k ,int numb) {
	if (k == numb) return 1;
	int g=0,d=k;
	/*int y;
	for ( y = 0; y < numb; y++) {
		if (matr[ways[1][k]][y] != 0) break;
	}
	if (y == numb)return 0;*/
	for (int i = 0; i < k; i++) {
		if (ways[1][d] == ways[0][i]) { 
			if (ways[1][i] == ways[0][d]) return 0;
			d = i;
			i = 0; 
			g++; 
		}
		if (g == numb) return 0;
	}
	return 1;
}