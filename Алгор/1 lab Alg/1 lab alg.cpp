#include<iostream>
void InputMatrD(int** matr, int m, int n);
void OutputMatrD(int** matr, int m, int n);

int main(){
	int start, numberCities, i,j,k;
	int* answer;
	int** matr;
	std::cout << "Enter number of Cities:" << std::endl;
	std::cin >> numberCities;
	std::cout << "Cite start" << std::endl;
	std::cin >> start;

	matr = new int* [numberCities]; 
	for (i = 0; i < numberCities; i++) 
		matr[i] = new int[numberCities];

	answer = new int [numberCities+1];

		answer[0] = start;
		answer[numberCities] = start;

	/*std::cout << "Enter matr:" << std::endl;
	InputMatrD(matr, numberCities, numberCities);

	std::cout << "Output matr:" << std::endl;
	OutputMatrD(matr, numberCities, numberCities);*/

	for (i = 1,j=1; i < numberCities; i++) {
		if (j == start) j++;
		answer[i] = j;
		j++;
	}
	for (i = 0; i < numberCities + 1; i++) std::cout << answer[i]<< " ";

	std::cout <<std::endl<< "Enter number of Cities:" <<numberCities << std::endl;
	std::cout << "Cite start:" <<start << std::endl;
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
