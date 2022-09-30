#pragma once
#include "../student/student.h"
#include <iostream>
#include <vector>

using namespace std;
namespace SoU = StudentOfUniversity;

namespace GroupOfStudents
{

	class GroupStudents
	{
	private:
		string name;
		string gender;
		int age;
		int phoneNumber;
	public:
		vector <SoU::Student> group;
		GroupStudents() {}
		GroupStudents(string _name, string _gender, int _age, int _phoneNumber)
		{
			name = _name;
			gender = _gender;
			age = _age;
			phoneNumber = _phoneNumber;

			SoU::Student student;
			student.setName(name);
			student.setGender(gender);
			student.setAge(age);
			student.setPhoneNumber(phoneNumber);

			group.push_back(student);
		}
		GroupStudents(const SoU::Student& p1)
		{
			this->name = p1.name;
			this->gender = p1.gender;
			this->age = p1.age;
			this->phoneNumber = p1.phoneNumber;

			SoU::Student student;
			student.setName(name);
			student.setGender(gender);
			student.setAge(age);
			student.setPhoneNumber(phoneNumber);

			this->group.push_back(student);
		}

		~GroupStudents()
		{
			group.clear();
		}
		//overloading =
		GroupStudents operator=(GroupStudents& gr)
		{
			this->group.clear();
			for (auto i = 0; i < gr.group.size(); i++)
			{
				name = gr.group[i].getName();
				gender = gr.group[i].getGender();
				age = gr.group[i].getAge();
				phoneNumber = gr.group[i].getPhoneNumber();

				add_Student_to_gruop(name, gender, age, phoneNumber);
			}
			return *this;
		}

		//overloading +
		GroupStudents operator+(GroupStudents& gr)
		{
			for (auto i = 0; i < gr.group.size(); i++)
			{
				name = gr.group[i].getName();
				gender = gr.group[i].getGender();
				age = gr.group[i].getAge();
				phoneNumber = gr.group[i].getPhoneNumber();

				add_Student_to_gruop(name, gender, age, phoneNumber);
			}
			return *this;
		}

		//overloading +=
		GroupStudents operator+=(GroupStudents& gr)
		{
			for (auto i = 0; i < gr.group.size(); i++)
			{
				name = gr.group[i].getName();
				gender = gr.group[i].getGender();
				age = gr.group[i].getAge();
				phoneNumber = gr.group[i].getPhoneNumber();

				add_Student_to_gruop(name, gender, age, phoneNumber);
			}
			return *this;
		}

		//overloading ++(groupStudent)
		GroupStudents operator++()
		{
			add_Student_to_gruop();
			return *this;
		}

		//overloading (groupStudent)++
		GroupStudents operator++(int)
		{
			add_Student_to_gruop();
			return *this;
		}

		//overloading --(groupStudent)
		GroupStudents operator--()
		{
			this->group.pop_back();
			return *this;
		}

		//overloading (groupStudent)--
		GroupStudents operator--(int)
		{
			this->group.pop_back();
			return *this;
		}

		//Overloading opeator >  /to check which group is bigger
		bool operator>(const GroupStudents& gr)
		{
			return this->group.size() > gr.group.size();
		}

		//Overloading opeator < /to check which group is bigger
		bool operator<(const GroupStudents& gr)
		{
			return this->group.size() < gr.group.size();
		}

		void add_Student_to_gruop()
		{
			SoU::Student student;
			cout << "Write student name: \n";
			cin >> name;
			student.setName(name);

			cout << "Write student gender: \n";
			cin >> gender;
			student.setGender(gender);

			cout << "Write student age: \n";
			cin >> age;
			student.setAge(age);

			cout << "Write student phoneNumber: \n";
			cin >> phoneNumber;
			student.setPhoneNumber(phoneNumber);

			group.push_back(student);
		}

		void add_Student_to_gruop(string _name, string _gender, int _age, int _phoneNumber)
		{
			SoU::Student student;
			student.setName(_name);
			student.setGender(_gender);
			student.setAge(_age);
			student.setPhoneNumber(_phoneNumber);

			group.push_back(student);
		}

		void showAllStudent()
		{
			cout << endl << "Student list: " << endl;
			for (auto i = 0; i < group.size(); i++)
			{
				cout << "Student number: " << i + 1 << endl;
				cout << "Name: " << group[i].getName() << endl;
				cout << "Gender: " << group[i].getGender() << endl;
				cout << "Age: " << group[i].getAge() << endl;
				cout << "Phone number: " << group[i].getPhoneNumber() << endl << endl;
			}
		}

		void updatePhoneNumber(int index, int phoneNumber)
		{
			if (index < 0 || index >= group.size())
				throw "Index is out range";
			group[index - 1].setPhoneNumber(phoneNumber);
		}

		void updateName(int index, string name)
		{
			if (index < 0 || index >= group.size())
				throw "Index is out range";
			group[index - 1].setName(name);
		}

		friend ostream& operator<<(ostream& os, GroupStudents& gr);
		friend void operator>>(istream& is, GroupStudents& gr);
	};
}