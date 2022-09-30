#include <iostream>
#include "area.h"

using namespace std;
namespace CGA = CalculateGeometricArea;

int CGA::Area::count = 0;

int main()
{
	cout << CGA::Area::triangle(3, 3) << endl;
	cout << CGA::Area::rectangle(3, 3) << endl;
	cout << CGA::Area::square(3) << endl;
	cout << CGA::Area::rombus(3, 3) << endl;

	cout << CGA::Area::getCount();
}