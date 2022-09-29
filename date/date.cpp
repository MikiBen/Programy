#include <iostream>
#include "date.h"

using namespace std;

ostream& operator<<(ostream& os, const Date& d)
{
    os << d.day << "/" << d.month << "/" << d.year;
    return os;
}
istream& operator>>(istream& is, Date& d)
{
    int year;
    int month;
    int day;
    cout << "\nEnter year:\n";
    is >> year;
    cout << "Enter month:\n";
    is >> month;
    cout << "Enter day:\n";
    is >> day;

    d.setTime(year, month, day);
    d.updateTime();

    return is;
}

int main()
{
    bool result;
    Date A(2003, 1, 7);

    Date B(2003, 2, 5);
    Date C;

    cout << "A: " << A.getDate() << endl;
    cout << "B: " << B.getDate() << endl;
    cout << "C: " << C.getDate() << endl;
    ++C;
    cout << "++C: " << C.getDate() << endl;
    C++;
    cout << "C++: " << C.getDate() << endl;
    --C;
    cout << "--C: " << C.getDate() << endl;
    C--;
    cout << "C--: " << C.getDate() << endl;
    C = C + 10;
    cout << "C = C+10: " << C.getDate() << endl;
    C = C - 10;
    cout << "C = C-10: " << C.getDate() << endl;
    C += 5;
    cout << "C += 5: " << C.getDate() << endl;
    C -= 5;
    cout << "C -= 5: " << C.getDate() << endl;

    result = A < B;
    cout << "A < B : " << result << endl;
    result = A > B;
    cout << "A > B : " << result << endl;
    result = A <= B;
    cout << "A <= B : " << result << endl;
    result = A >= B;
    cout << "A >= B : " << result << endl;
    result = A == B;
    cout << "A == B : " << result << endl;
    result = A != B;
    cout << "A != B : " << result << endl;

    cout << "A:\n";
    cout << A;
    cin >> A;
    cout << "A:\n";
    cout << A;
}