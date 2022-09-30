#pragma once

using namespace std;

namespace CalculateGeometricArea
{
	class Area
	{
	private:
		static int count;
	public:
		static double triangle(int a, int h)
		{
			++count;
			return 1.0 * a * h / 2;
		}
		static int rectangle(int a, int b)
		{
			++count;
			return a * b;
		}
		static int square(int a)
		{
			++count;
			return a * a;
		}
		static double rombus(int e, int f)
		{
			++count;
			return 1.0 * e * f / 2;
		}
		static int getCount()
		{
			return count;
		}
	};
}