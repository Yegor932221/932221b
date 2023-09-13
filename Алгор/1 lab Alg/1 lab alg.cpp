#include<iostream>
#include <time.h>
void InputMatrD(int** matr, int m, int n);
void OutputMatrD(int** matr, int m, int n);
void Swap(int* a, int b, int c);
int CostWay(int** matr, int* rearrangement, int numberCities);
void RandomMatr(int** matr, int n);

int main() {	
	int start, numberCities, i, j, maxJ, maxI, k, cost = 0, lowerCost = 0, full=1;
	int* rearrangement, * cheapest;
	int** matr;
	std::cout << "Enter number of Citiesgg:" << std::endl;
	std::cin >> numberCities;
	std::cout << "Cite start" << std::endl;
	std::cin >> start;

	matr = new int* [numberCities];
	for (i = 0; i < numberCities; i++)
		matr[i] = new int[numberCities];

	rearrangement = new int[numberCities + 1];
	cheapest = new int[numberCities + 1];

	RandomMatr(matr, numberCities);
	std::cout << "Output matr:" << std::endl;
	OutputMatrD(matr, numberCities, numberCities);

	rearrangement[0] = start;
	rearrangement[numberCities] = start;

	for (i = 1, j = 1; i < numberCities; i++) {
		if (j == start) j++;
		rearrangement[i] = j;
		cheapest[i] = rearrangement[i];
		j++;
	}

	std::cout << std::endl<<"0. ";
	for (i = 0; i < numberCities + 1; i++) std::cout << rearrangement[i] << " ";
	std::cout << std::endl;
	lowerCost = CostWay(matr, rearrangement, numberCities);

	for (i = 1; i < numberCities; i++)full = full * i; 

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
			
			std::cout << k << ". ";
			for (i = 0; i < numberCities + 1; i++) std::cout << rearrangement[i] << " ";
			std::cout << std::endl;
			cost = CostWay(matr, rearrangement, numberCities);

				if (cost < lowerCost) {
					lowerCost = cost;
					for (j = 1; j < numberCities; j++)
						cheapest[j] = rearrangement[j];
				}
			}
		



	lowerCost = CostWay(matr, rearrangement, numberCities);
	std::cout << std::endl;
	for (i = 0; i < numberCities + 1; i++) std::cout << rearrangement[i]<< " ";
	std::cout<<std::endl<<"lowerCost: " << lowerCost;
	std::cout <<std::endl<< "Enter number of Cities: " <<numberCities << std::endl;
	std::cout << "Cite start: " <<start << std::endl;
	for (i = 0; i < numberCities; i++) delete[]matr[i];
	delete[] matr;
	delete[] cheapest;
	delete[] rearrangement;
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