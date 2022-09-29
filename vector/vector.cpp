#include <iostream>
#include "vector.h"

using namespace std;

ostream& operator<<(ostream& os, const Vector& v)
{
    for (auto i = 0; i < v.arr.size(); i++)
        os << v.arr[i] << ", ";
        
    return os;
}
istream& operator>>(istream& is, Vector& v)
{
    int value;

    cout << "Enter new value: \n";
    is >> value;
    v.arr.push_back(value);

    return is;
}

int main()
{
    Vector A;
    Vector B;
    Vector C;
    A.addElement(10);
    A.addElement(11);
    A.addElement(14);

    B.addElement(9);
    B.addElement(7);
    B.addElement(174);

    cout << "Vector A: " << endl;
    A.showVector();
    cout << endl << "Vector B: " << endl;
    B.showVector();
    C = A + B;

    cin >> C;
    cout << endl << "Vector C: " << endl;
    cout << C;

}