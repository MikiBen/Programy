#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    try {
        Vector::Vector A;
        Vector::Vector B;
        Vector::Vector C;
        A.addElement(10);
        A.addElement(11);
        A.addElement(14);

        B.addElement(9);
        B.addElement(7);
        B.addElement(174);

        A += B;

        A.showVector();
        cout << endl;
        cout << A.sum() << endl;
        cout << A.average();
        cout << endl << "A[2]";
        cout << A[12];
        cout << endl << "coutA";
        cout << A;
    }
    catch (const char* str)
    {
        cout << "Exception: " << str;
    }

}