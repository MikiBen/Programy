#ifndef __VECTOR_H__
#define __VECTOR_H__

#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace Vector
{
	class Vector
	{
	private:
		size_t size;
		int* data;

	public:
		Vector() : size{ 0 }, data{ nullptr } {}
		Vector(const Vector& p1)
		{
			size = p1.size;
			if (!size)
			{
				data = nullptr;
			}
			else
			{
				data = new int[size];
				for (auto i = 0; i < p1.size; i++)
					data[i] = p1.data[i];
			}
		}

		~Vector()
		{
			if (data != nullptr)
				delete[] data;
		}
		
		//overloading +=
		Vector& operator+=(const Vector& v)
		{
			if (v.size == 0)
				return *this;
			else
			{
				int* temporaryData = new int[size];
				for (auto i = 0; i < size; i++)
				{
					temporaryData[i] = data[i];
				}
				delete[] data;

				data = new int[size + v.size];
				for (auto i = 0; i < size; i++)
				{
					data[i] = temporaryData[i];
				}

				delete[] temporaryData;
				for (auto i = 0 ; i < size + v.size; i++)
				{
					data[size + i] = v.data[i];
				}
				size = size + v.size;
			}
			return *this;
		}

		//overloading []
		const int& operator[](const int index)
		{
			if (index < size)
				return data[index];
			else throw "This index is not exist: ";
		}

		//overloading +
		Vector& operator+(const Vector& v)
		{
			if (v.size == 0)
				return *this;
			else
			{
				int* temporaryData = new int[size];
				for (auto i = 0; i < size; i++)
				{
					temporaryData[i] = data[i];
				}
				delete[] data;

				data = new int[size + v.size];
				for (auto i = 0; i < size; i++)
				{
					data[i] = temporaryData[i];
				}

				delete[] temporaryData;
				for (auto i = 0 ; i < size + v.size; i++)
				{
					data[size + i] = v.data[i];
				}
				size = size + v.size;
			}
			return *this;
		}

		//overloading <
		bool operator<(Vector& v)
		{
			return this->sum() < v.sum();
		}

		//overloading >
		bool operator>(Vector& v)
		{
			return this->sum() > v.sum();
		}

		//overloading ==
		bool operator==(const Vector& v)
		{
			if (size == v.size)
				for (auto i = 0; i < size; i++)
					if (data[i] != v.data[i])
						return false;
			else return false;
			return true;
		}
		
		void addElement(const int number)
		{
			if (!size)
			{
				data = new int[1];
				data[0] = number;
				size = 1;
			}
			else
			{
				int* temporaryData = new int[size];
				for (auto i = 0; i < size; i++)
				{
					temporaryData[i] = data[i];
				}
				delete[] data;

				data = new int[size + 1];
				for (auto i = 0; i < size; i++)
				{
					data[i] = temporaryData[i];
				}
				size = size + 1;
				data[size-1] = number;
				delete[] temporaryData;
			}
		}

		void showVector()
		{
			for (auto i = 0; i < size; i++)
				cout << data[i] << ", ";
		}

		const int sum()
		{
			int sum = 0;
			for (auto i = 0; i < size; i++)
				sum = sum + data[i];

			return sum;
		}

		const double average()
		{
			return 1.0 * sum() / size;
		}

		friend ostream& operator<<(ostream& os, const Vector& v);
		friend istream& operator>>(istream& is, Vector& v);
	};
}

	ostream& Vector::operator<<(ostream& os, const Vector& v)
	{
		for (auto i = 0; i < v.size; i++)
			os << v.data[i] << ", ";

		return os;
	}
	istream& Vector::operator>>(istream& is, Vector& v)
	{
		int value;

		cout << "Enter new value: \n";
		is >> value;
		v.addElement(value);

		return is;
	}

#endif /* __VECTOR_H__ */