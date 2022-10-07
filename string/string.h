#ifndef __STRING_H__
#define __STRING_H__

#pragma once
#include <iostream>

using namespace std;

namespace String
{
	class String
	{
	private:
		size_t size;
		char* word;

	public:
		String()
		{
			word = nullptr;
			size = 0;
		}

		String(const String& str) 
		{
			size = str.size;
			if (!size)
			{
				word = nullptr;
			}
			else
			{
				word = new char[size];
				for (auto i = 0; i < size; i++)
					word[i] = str.word[i];
			}
		}

		~String()
		{
			if (word != nullptr)
				delete[] word;
		}

		//overloading +
		String& operator+(const String& str)
		{
			size_t newSize = size + str.size;

			char* temporaryWord = new char[size];

			for (auto i = 0; i < size;i++)
				temporaryWord[i] = word[i];

			delete[] word;
			word = new char[newSize + 1];
			for (auto i = 0; i < size; i++)
				word[i] = temporaryWord[i];
			for (auto i = 0; i < str.size; i++)
				word[i + size] = str.word[i];

			size = newSize;
			word[size] = NULL;

			return *this;
		}
		
		void setString( const char* str)
		{
			int newSize=0;
				while (str[newSize] != '\0')
					newSize++;

				delete[] word;
				size = newSize;
				word = new char[newSize +1];

				for (int i = 0; i < size; i++)
				{
					word[i] = str[i];
				}
				word[newSize] = NULL;
		}
		
		const char* getString()
		{
			return word;
		}

		const char& operator[](const int index)
		{
			if (index < size)
				return word[index];
			else throw "This index is not exist: ";
		}

		friend ostream& operator<<(ostream& os, const String& s);
		friend istream& operator>>(istream& is, String& s);
	};
}

ostream& String::operator<<(ostream& os, const String& s)
{
	os << s.word;
	return os;
}

istream& String::operator>>(istream& is, String& s)
{
	string line;
	char* newWord;
	cout << "Enter the string: \n";
	is >> line;

	newWord = new char[line.size() + 1];
	for (int i = 0; i < line.size(); i++) {
		newWord[i] = line[i];
	}
		
	newWord[line.size()] = NULL;
	s.setString(newWord);
	delete[] newWord;
	return is;
}

#endif /* __STRING_H__ */