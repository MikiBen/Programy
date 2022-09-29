#include<iostream>
#include "string.h"

using namespace std;

int main()
{
    String A;

    A.setString("New String\n");

    cout << " String A: " << A.getString();

    String B = A;
    cout << " String B = A: " << B.getString();

    String C;
    C.setString("String\n");

    cout << " String C: " << C.getString();

    A -= C;
    cout << " String A -= C: " << A.getString();
}