#pragma once
#include<fstream>
#include<string>
#include<iostream>

using namespace std;

namespace fileExceptions
{
	class File
	{
	private:
		fstream file;
	public:
		~File()
		{
			closeFile();
		}
		void checkOpenFile(string name)
		{
			file.open(name, ios::out | ios::app);
			if (!file.is_open())
				throw "Problem with opended File\n";

			File::checkFile();
		}
		void checkFile()
		{
			if (!file.good())
			{
				throw "Problem with file\n";
			}
		}
		void closeFile()
		{
			file.close();
		}
	};

}