#include <iostream>
#include "student.h"

using namespace std;

//overloading <<
ostream& StudentOfUniversity::operator<<(ostream& os, const Student& s)
{
    os << "Name: " << s.name << "\n"
        << "Gender: " << s.gender << "\n"
        << "Age: " << s.age << "\n"
        << "Phone Number: " << s.phoneNumber<< "\n";
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

int main()
{
    StudentOfUniversity::Student A;
    StudentOfUniversity::Student B;

    A.setName("Mike");
    A.setGender("Male");
    A.setAge(55);
    A.setPhoneNumber(987987);

    B.setName("Marta");
    B.setGender("Female");
    B.setAge(66);
    B.setPhoneNumber(123456);

    cout << "Student A:  \n";
    cout << A;
    cout << "Studen B:  \n";
    cout << B;

    B = A;

    cout << "Student B=A: \n";
    cout << B;

    cin >> A;
    cout << A;
}