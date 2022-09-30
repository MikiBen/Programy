#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace Vector
{
	class Vector
	{
	public:
		vector <int> arr;

		Vector() {}
		Vector(const Vector& p1)
		{
			for (auto i = 0; i < p1.arr.size(); i++)
				this->arr.push_back(p1.arr[i]);
		}

		~Vector()
		{
			arr.clear();
		}

		//overloading +=
		Vector& operator+=(const Vector& v)
		{
			for (auto i = 0; i < v.arr.size(); i++)
				arr.push_back(v.arr[i]);

			return *this;
		}

		//overloading +
		Vector& operator+(const Vector& v)
		{
			for (auto i = 0; i < v.arr.size(); i++)
				arr.push_back(v.arr[i]);

			return *this;
		}

		//overloading --
		Vector& operator--()
		{
			this->arr.pop_back();
			return *this;;
		}

		//overloading --
		Vector& operator--(int)
		{
			this->arr.pop_back();
			return *this;;
		}

		//overloading <
		bool operator<(const Vector& v)
		{
			return this->arr.size() < v.arr.size();
		}

		//overloading >
		bool operator>(const Vector& v)
		{
			return this->arr.size() > v.arr.size();
		}

		//overloading ==
		bool operator==(const Vector& v)
		{
			if (this->arr.size() == v.arr.size())
			{
				for (auto i = 0; i < this->arr.size(); i++)
					if (this->arr[i] != v.arr[i])
						return false;
			}
			else return false;

			return true;
		}

		void addElement(const int number)
		{
			arr.push_back(number);
		}

		void showVector()
		{
			for (auto i = 0; i < arr.size(); i++)
				cout << arr[i] << ", ";
		}

		int sum()
		{
			int sum = 0;
			for (auto i = 0; i < arr.size(); i++)
				sum = sum + arr[i];

			return sum;
		}

		double average()
		{
			return 1.0 * sum() / arr.size();
		}

		friend ostream& operator<<(ostream& os, const Vector& v);
		friend istream& operator>>(istream& is, Vector& v);
	};
}