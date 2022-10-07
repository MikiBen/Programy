#include<iostream>
#include "string.h"

using namespace std;

int main()
{
    String::String A;
    String::String B;
    String::String C;

    B.setString("AAA");
   A.setString("BBsdsdsdaB");
    A = A + B;
    cout<< A.getString();
    cout << B.getString();
  cout << " String A: " << A.getString()<<endl;
    cout << endl;
    cin >> A;
    cout << A.getString();
}