#include<iostream>
void InputMatrD(int** matr, int m, int n);
void OutputMatrD(int** matr, int m, int n);
void Swap(int* a, int b, int c);

int main() {
	int start, numberCities, i, j, l, m, k, cost = 0, lowerCost = 0, full=1;
	int* rearrangement, * cheapest;
	int** matr;
	std::cout << "Enter number of Cities:" << std::endl;
	std::cin >> numberCities;
	std::cout << "Cite start" << std::endl;
	std::cin >> start;

	matr = new int* [numberCities];
	for (i = 0; i < numberCities; i++)
		matr[i] = new int[numberCities];

	rearrangement = new int[numberCities + 1];
	cheapest = new int[numberCities + 1];

	rearrangement[0] = start;
	rearrangement[numberCities] = start;

	std::cout << "Enter matr:" << std::endl;
	InputMatrD(matr, numberCities, numberCities);

	std::cout << "Output matr:" << std::endl;
	OutputMatrD(matr, numberCities, numberCities);

	for (i = 1, j = 1; i < numberCities; i++) {
		if (j == start) j++;
		rearrangement[i] = j;
		cheapest[i] = rearrangement[i];
		j++;
	}

	std::cout << std::endl;
	for (i = 0; i < numberCities; i++) {
		k = rearrangement[i] - 1;
		l = rearrangement[i + 1] - 1;
		lowerCost += matr[k][l];
	}

	for (i = 1; i < numberCities; i++)full *= i; 

		for (k = 1; k <= full; k++) {
			for (i = 1; i < (numberCities - 1); i++)
				if (rearrangement[i] < rearrangement[i + 1])m = i;

			for (j = m + 1; rearrangement[m] < rearrangement[j] && j < numberCities; j++);

			Swap(rearrangement, i, j);

			for (m += 1; m < numberCities - 1; m++) if (rearrangement[m] > rearrangement[m + 1]) {
				Swap(rearrangement, m, m + 1);
				m--;
			}

			for (m = 0, cost = 0; m < numberCities; m++) {
				k = rearrangement[m] - 1;
				l = rearrangement[m + 1] - 1;
				cost =cost+ matr[k][l];

				if (cost < lowerCost) {
					lowerCost = cost;
					for (m = 1; m < numberCities; m++)
						cheapest[m] = rearrangement[m];
				}
			}
		}
	


	std::cout << std::endl;

	for (i = 0; i < numberCities + 1; i++) std::cout << cheapest[i]<< " ";
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