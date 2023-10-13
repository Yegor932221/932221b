#include<iostream>
void RandMasAny(int a[], int b, int c, int n);
void OutputMus(int a[], int n);


//3 massiv 10/-10
int* mass_10_10thou = new int[10000], * mass_1000_10thou = new int[10000], * mass_100000_10thou = new int[10000];
//3 massiv 1000/-1000
int* mass_10_100th = new int[100000], * mass_1000_100th = new int[100000], * mass_100000_100th = new int[100000];
//3 massiv 100000/-100000
int* mass_10_mil = new int[1000000], * mass_1000_mil = new int[1000000], * mass_100000_mil = new int[1000000];

int main(){

	//rand 3 massiv 10000
	RandMasAny(mass_10_10thou[10000], -10, 10, 10000);
	RandMasAny(mass_1000_10thou[10000], -1000, 1000, 10000);
	RandMasAny(mass_100000_10thou[10000], -100000, 100000, 10000);
	
	//rand 3 massiv 100000
	RandMasAny(mass_10_100th[100000], -10, 10, 100000);
	RandMasAny(mass_1000_100th[100000], -1000, 1000, 100000);
	RandMasAny(mass_100000_100th[100000], -100000, 100000, 100000);

	//rand 3 massiv 1000000
	RandMasAny(mass_10_mil[1000000], -10, 10, 1000000);
	RandMasAny(mass_1000_mil[1000000], -1000, 1000, 1000000);
	RandMasAny(mass_100000_mil[1000000], -100000, 100000, 1000000);

	OutputMus(mass_10_10thou, 10000);
}


void RandMasAny(int &a, int b, int c, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % (c - b + 1) + b;
}

void OutputMus(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d  ", a[i]);
}