#include "iostream"
#include "stdio.h"
#include <vector>
#include <C:\Users\Åãîð\932221b\ÎÎÏ\3 lab\BoolVector.cpp>
#include <C:\Users\Åãîð\932221b\ÎÎÏ\lab 4 oop\BoolMatr.cpp>
#include <C:\Users\Åãîð\932221b\ÎÎÏ\3 lab\BoolVector.h>
#include <C:\Users\Åãîð\932221b\ÎÎÏ\lab 4 oop\BoolMatr.h>

int main() {

	std::vector<std::vector<bool>> vec = { {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 0, 1, 0}
};

	BoolMatr matr(vec);
	std::vector<int> arr;
	BoolVector vector1(matr.GetCountColumns(), false);
	BoolVector vector2(matr.GetCountColumns(), false);
	for (; vector1.Weight()!= matr.GetCountColumns();) {
		vector2 = ~matr.MatrDisjunction();
		vector1 =vector1 | vector2;

		if (vector2.Weight() == 0) {
			std::cout << "Circly Graph";
			return 0;
		}

		for (int i = 0; i<vector2.Lenght(); i++) {
			if (vector2[i] == 1) {
				matr[i].Set0InRange(0,matr.GetCountColumns());
				arr.push_back(i);
			}
				matr[i] |= vector2;
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		std::cout<< (arr[i]+1)<<" ";
	}
	return 1;
}

///*std::vector<std::vector<bool>> vec = {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
//, { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 }
//, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
//, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
//, { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 }
//, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
//, { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 }
//, { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
//, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
//, { 1, 0, 0, 1, 0, 0, 0, 0, 1, 0 }};*/


//{0, 1, 0, 0, 0},
//{ 0, 0, 0, 0, 0 },
//{ 0, 1, 0, 0, 1 },
//{ 0, 1, 0, 0, 0 },
//{ 1, 0, 0, 0, 0 }


//{0, 1, 0, 1, 0},
//{0, 0, 0, 1, 0},
//{1, 0, 0, 0, 1},
//{0, 0, 1, 0, 1},
//{0, 0, 0, 0, 0}



//{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
//{1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
//{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
//{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//{0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
//{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
//{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
//{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//{0, 0, 0, 1, 0, 0, 0, 0, 1, 0}
