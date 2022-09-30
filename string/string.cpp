#include<iostream>
#include "string.h"

using namespace std;

ostream& String::operator<<(ostream& os, const String& s)
{
    os << s.word;
    return os;
}
istream& String::operator>>(istream& is, String& s)
{
    string line;
    cout << "Enter the string: \n";
    is >> line;
    s.setString(line);

    return is;
}

int main()
{
    String::String A;
    String::String B;
    String::String C;

    A.setString("first");
    B.setString("Second");
    cout << " String A: " << A.getString()<<endl;
   
    C = A + B;
    cout << C; 
}