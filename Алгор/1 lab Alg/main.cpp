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
bool Cycl(int** ways, int** matr, int k, int numb);
void WayBust(int numberCities, int first, int* cheapest, int** matr);
int Evr(int numberCities, int** matr);

int main() {
	int first, numberCities, i, lowerCost = 0, cost2;;
	int* cheapest;
	int** matr;
	std::cout << "Enter number of Citiesgg:" << std::endl;
	std::cin >> numberCities;
	std::cout << "Cite start" << std::endl;
	std::cin >> first;

	matr = new int* [numberCities];
	for (i = 0; i < numberCities; i++) matr[i] = new int[numberCities];

	cheapest = new int[numberCities + 1];

	RandomMatr(matr, numberCities);
	std::cout << "Output matr:" << std::endl;
	OutputMatrD(matr, numberCities, numberCities);

	auto start = std::chrono::high_resolution_clock::now();

	WayBust(numberCities, first, cheapest, matr);

	auto end = std::chrono::steady_clock::now();
	float time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	std::cout << std::endl << "First decision time:" << time << std::endl;

	for (i = 0; i < numberCities + 1; i++) std::cout << cheapest[i] << " ";
	lowerCost = CostWay(matr, cheapest, numberCities);

	std::cout << std::endl << "lowerCost: " << lowerCost;

	start = std::chrono::high_resolution_clock::now();

	cost2 = Evr(numberCities, matr);

	end = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout << "Cost evristics: " << cost2;
	std::cout << "\nEvristics decision time: " << time;
	std::cout << "\nQuality percentage:" << (lowerCost * 100 / cost2) << "%";
	for (i = 0; i < numberCities; i++) delete[]matr[i];
	delete[] matr;
	delete[] cheapest;
}







void Weist(int** matr, int* weist, int numberCities) {
	for (int i = 0; i < numberCities; i++) {
		int sum = 0;
		for (int j = 0; j < numberCities; j++) {sum += matr[i][j];}
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
			matr[i][j] = 1 + (rand() % 20);
			if (i == j)matr[i][j] = 0;
		}
}

int CostWay(int** matr, int* rearrangement, int numberCities) {
	int i, cost = 0;
	for (i = 0; i < numberCities; i++) cost += matr[(rearrangement[i] - 1)][(rearrangement[i + 1] - 1)];
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

bool Cycl(int** ways, int** matr, int k, int numb) {
	if (k == numb) return 1;
	int g = 0, d = k;
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

void WayBust(int numberCities, int first, int* cheapest, int** matr) {
	int i, j, k, full=1, cost, maxI, maxJ, lowerCost;
	int* rearrangement;

	rearrangement = new int[numberCities + 1];
	rearrangement[0] = first;
	rearrangement[numberCities] = first;

	for (i = 1; i < numberCities; i++)full = full * i; //начало полного перебора

	for (i = 1, j = 1; i < numberCities; i++) {
		if (j == first) j++;
		rearrangement[i] = j;
		cheapest[i] = rearrangement[i];
		j++;
	}
	cost = CostWay(matr, rearrangement, numberCities);
	lowerCost = cost;

	for (k = 1; k < full; k++) {
		maxI = -1; maxJ = -1;

		for (i = 1; i < (numberCities - 1); i++) { if (rearrangement[i] < rearrangement[(i + 1)]) maxI = i;}

		if (maxI == -1) break;

		for (j = (maxI + 1); j <= numberCities - 1; j++) { if (rearrangement[maxI] < rearrangement[j]) maxJ = j; }

		if (maxJ == -1) break;

		Swap(rearrangement, maxI, maxJ);

		j = numberCities - 1;
		i = maxI + 1;

		while (i < j) {
			Swap(rearrangement, i, j);
			i++; j--;
		}
		//следующая перестановка получена

		cost = CostWay(matr, rearrangement, numberCities);



		if (cost < lowerCost) {
			lowerCost = cost;
			for (j = 0; j < (numberCities + 1); j++) cheapest[j] = rearrangement[j];
		}

	}
	delete[] rearrangement;
	//return cheapest;
}

int Evr(int numberCities, int** matr) {
	int min, max = 0, o = 0, ki, kj, i, j, k;
	int cost2 = 0;
	int** shortest;
	shortest = new int* [3];
	for (i = 0; i < 3; i++) {shortest[i] = new int[numberCities];}

	for (i = 0; i < numberCities; i++)
		for (j = 0; j < numberCities; j++) {if (matr[i][j] > max)max = matr[i][j];}

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
		for (i = 0, j = 0; i < numberCities && j < numberCities; j++, i++)
		{
			matr[ki][i] = 0;
			matr[j][kj] = 0;
		}
		cost2 += shortest[2][k];
	}
	for (i = 0; i < numberCities; i++)
	{
		std::cout << "(" << shortest[0][i] << "-" << shortest[1][i] << ")\n";
	}
	for (i = 0; i < 3; i++) delete[]shortest[i];
	delete[] shortest;
	return cost2;
}