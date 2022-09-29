#pragma once
#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
	string name;
	string gender;
	int age;
	int phoneNumber;
		
	Student()
	{
		name = "No name";
		gender = "";
		age = 0;
		phoneNumber = 0;
	}

	Student(const Student& p1)
	{
		this->name = p1.name;
		this->gender = p1.gender;
		this->age = p1.age;
		this->phoneNumber = p1.phoneNumber;
	}
	
	//overloading =
	Student& operator=(const Student& s)
	{
		if (this == &s)
		{
			return *this;
		}

		this->name = s.name;
		this->gender = s.gender;
		this->age = s.age;
		this->phoneNumber = s.phoneNumber;

		return *this;
	}

	//overloading ==
	bool operator==(const Student& s)
	{
		return this == &s;
	}

	//overloading !=
	bool operator!=(const Student& s)
	{
		return this != &s;
	}
	
	void setName(string const _name) { name = _name; }
	void setGender(string const _gender) { gender = _gender; }
	void setAge(int const _age) { age = _age; }
	void setPhoneNumber(int _phoneNumber) { phoneNumber = _phoneNumber; }

	string getName() { return name; }
	string getGender() { return gender; }
	int getAge() { return age; }
	int getPhoneNumber() { return phoneNumber; }

	friend ostream& operator<<(ostream& os, const Student& s);
	friend istream& operator>>(istream& is, Student& s);
};