#ifndef __STUDENT_H__
#define __STUDENT_H__

#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace StudentOfUniversity
{
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
				return this->name == s.name &&
				this->gender == s.gender &&
				this->age == s.age &&
				this->phoneNumber == s.phoneNumber;
		}

		//overloading !=
		bool operator!=(const Student& s)
		{
			return !(*this == s);
		}

		void setName(string const _name) { name = _name; }
		void setGender(string const _gender) { gender = _gender; }
		void setAge(int const _age) { age = _age; }
		void setPhoneNumber(int _phoneNumber) { phoneNumber = _phoneNumber; }

		const string getName() { return name; }
		const string getGender() { return gender; }
		const int getAge() { return age; }
		const int getPhoneNumber() { return phoneNumber; }

		friend ostream& operator<<(ostream& os, const Student& s);
		friend istream& operator>>(istream& is, Student& s);
	};
}

//overloading <<
ostream& StudentOfUniversity::operator<<(ostream& os, const Student& s)
{
	os << "Name: " << s.name << "\n"
		<< "Gender: " << s.gender << "\n"
		<< "Age: " << s.age << "\n"
		<< "Phone Number: " << s.phoneNumber << "\n";
	return os;
}

//overloading >>
istream& StudentOfUniversity::operator>>(istream& is, Student& s)
{
	string name;
	string gender;
	int age;
	int phoneNumber;

	cout << "Enter name: ";
	is >> name;
	cout << "Enter gender: ";
	is >> gender;
	cout << "Enter age: ";
	is >> age;
	cout << "Enter phone Number: ";
	is >> phoneNumber;

	s.setName(name);
	s.setGender(gender);
	s.setAge(age);
	s.setPhoneNumber(phoneNumber);

	return is;
}

#endif /* __STUDENT_H__ */