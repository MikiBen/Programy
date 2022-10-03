#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	int x = 4;
	int y = 5;

	Matrix<double> M(x, y);
	Matrix<double> M2(x, y);

	try {
		cout << "M" << endl;
		M.showMatrix();
		cout << "M2" << endl;
		M2.showMatrix();

		Matrix<double> M3 = M * M2;

		cout << "M3 = M * M2" << endl;
		M3.showMatrix();
		cout << "M" << endl;
		M.showMatrix();
		cout << "M2" << endl << endl;
		M2.showMatrix();

		Matrix<double> M4 = M3 / M2;

		cout << "M4 = M3 / M2" << endl;
		M4.showMatrix();
		cout << "M" << endl;
		M.showMatrix();
		cout << "M2" << endl;
		M2.showMatrix();
	}
	catch (const char* str)
	{
		cout << str;
	}

	return 0;
}