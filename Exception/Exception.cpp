#include<iostream>
#include<cmath>
#include"math.h"
#include<fstream>
#include"file.h"

using namespace std;

int main()
{
	namespace ME = matematicExceptions;
	namespace FE = fileExceptions;

	int result;
	int a = -99999;
	int b = 989;
	int arr[6] = { 1,2,3,4,5,6 };
	FE::File file;

	try
	{
		//multiplication
		result = a * b;
		ME::Math::overflowInt(a, b, result);
	}
	catch (const char* str)
	{
		cout << "Exception: " << str;
	}

	try
	{
		//divide
		b = 0;
		ME::Math::divideByZero(b);
		result = a / b;
	}
	catch (const char* str)
	{
		cout << "Exception: " << str;
	}

	try
	{
		//logarithm
		ME::Math::basicLogFunction(a);
	}
	catch (const char* str)
	{
		cout << "Exception: " << str;
	}

	try
	{
		//Array Index
		for (auto i = 0; i < 6; i++)
		{
			ME::Math::checkIndex(i, sizeof(arr) / sizeof(arr[0]));
		}
	}
	catch (const char* str)
	{
		cout << "Exception: " << str;
	}

	try
	{
		file.checkOpenFile("output.txt");
		file.closeFile();
	}
	catch (const char* str)
	{
		cout << "Exception: " << str;
	}
}
