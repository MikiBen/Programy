#include <iostream>
#include "student.h"

using namespace std;

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

    cout << endl<<"Student B=A: \n";
    cout << B;

    cin >> A;
    cout << A;
}