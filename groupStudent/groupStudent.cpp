#include <iostream>
#include "groupStudent.h"

using namespace std;

//overloading <<
ostream& GroupOfStudents::operator<<(ostream& os, GroupStudents& gr)
{
    for(auto i=0;  i< gr.group.size();i++)
    {
        os << "Student number: " << i + 1 << endl;
        os << "Name: " << gr.group[i].getName() << endl;
        os << "Gender: " << gr.group[i].getGender() << endl;
        os << "Age: " << gr.group[i].getAge() << endl;
        os << "Phone number: " << gr.group[i].getPhoneNumber() << endl << endl;
    }
        return os;
}

//overloading >>
void GroupOfStudents::operator>>(istream& is, GroupStudents& gr)
{
    gr.add_Student_to_gruop();
}

int main()
{
    try {
        GroupOfStudents::GroupStudents A("John", "Male", 23, 888);
        A.add_Student_to_gruop("Marta", "Female", 33, 987987);

        GroupOfStudents::GroupStudents B = A;

        cout << "Group A: " << endl;
        A.showAllStudent();
        //cout << endl << "Group B = A: " << endl;
        B.showAllStudent();

        GroupOfStudents::GroupStudents C("Mike", "Male", 43, 757575);
        GroupOfStudents::GroupStudents D;
        //C.add_Student_to_gruop("Andrew", "Male", 32, 100000);
       // cout << endl << "Group C: " << endl;
       // C.showAllStudent();
        
    }
    catch (const char* str)
    {
        cout <<"Error message: " <<  str;
    }
}