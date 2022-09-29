#include<iostream>
#include "string.h"

using namespace std;

ostream& operator<<(ostream& os, const String& s)
{
    os << s.word;
    return os;
}
istream& operator>>(istream& is, String& s)
{
    string line;
    cout << "Enter the string: \n";
    is >> line;
    s.setString(line);

    return is;
}

int main()
{
    String A,B,C;

    A.setString("Pierwszt");
    B.setString("Drugi");
    cout << " String A: " << A.getString()<<endl;
   
    C = A + B;
    cout << C; 
}