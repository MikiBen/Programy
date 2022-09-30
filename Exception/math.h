#pragma once

using namespace std;

namespace matematicExceptions
{
	class Math
	{
	private:
		static int howManyDigits(int a)
		{
			if (a < 0)
				a = a * (-1);
			return (int)log10(a) + 1;
		}
	public:
		static void basicLogFunction(int x)
		{
			if (x < 0)
				throw "Base is lower than 0 \n";
		}
		static void divideByZero(int a)
		{
			if (a == 0)
				throw "Divede by Zero \n";
		}
		static void overflowInt(int a, int b, int result)
		{
			long long int aa = a;
			long long int bb = b;
			long long int c = aa * bb;

			if ((howManyDigits(a) + howManyDigits(b)) > 11)
				throw "over flow int limit\n";

			if (result != c)
				throw "over flow int limit\n";
		}
		static void checkIndex(int i, int size)
		{
			if (i > size)
				throw "Array index is out of range\n";
		}
	};

}