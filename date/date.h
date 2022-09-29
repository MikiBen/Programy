#pragma once
#pragma warning(disable : 4996)

#include <ctime> 
#include <conio.h>      
#include <iostream>
#include <string>

using namespace std;

class Date
{
private:

	time_t timer;
	tm* tim;
	int year, month, day;

	void setTime(const int year, const int month, const int day)
	{
		tm t{ };
		t.tm_year = year - 1900;
		t.tm_mon = month - 1;
		t.tm_mday = day;
		t.tm_hour = 0;
		t.tm_min = 0;
		t.tm_sec = 0;
		t.tm_isdst = -1;
		timer = mktime(&t);
	}
public:
	Date(const int _year, const int _month, const int _day)
	{
		setTime(_year, _month, _day);
		updateTime();
	}
	Date()
	{
		timer = time(NULL);
		updateTime();
	}

	void updateTime()
	{
		tim = localtime(&timer);

		year = 1900 + tim->tm_year;
		month = 1 + tim->tm_mon;
		day = tim->tm_mday;
	}

	//Overloading opeator ()++ /add day
	Date& operator++(int)
	{
		this->timer = this->timer + 24 * 3600;
		updateTime();
		return *this;
	}
	//Overloading opeator ++() /add day
	Date& operator++()
	{
		this->timer = this->timer + 24 * 3600;
		updateTime();
		return *this;
	}
	//Overloading opeator ()-- /subtract a day
	Date& operator--(int)
	{
		this->timer = this->timer - 24 * 3600;
		updateTime();
		return *this;
	}
	//Overloading opeator --() /subtract a day
	Date& operator--()
	{
		this->timer = this->timer - 24 * 3600;
		updateTime();
		return *this;
	}
	//Overloading opeator -  /date - number of days
	Date& operator-(const int& d)
	{
		this->timer = this->timer - (24 * d) * 3600;
		updateTime();
		return *this;
	}
	//Overloading operator - /date - date
	int operator-(const Date& d)
	{
		this->timer = this->timer - d.timer;
		int differnce = this->timer / 86400;

		return differnce;
	}
	//Overloading opeator + /date + number of days
	Date& operator+(const int& d)
	{
		this->timer = this->timer + (24 * d) * 3600;
		updateTime();
		return *this;
	}
	//Overloading opeator += /date += number of days
	Date& operator+=(const int& d)
	{
		this->timer = this->timer + (24 * d) * 3600;
		updateTime();
		return *this;
	}
	//Overloading opeator -=  /date -= number of days
	Date& operator-=(const int& d)
	{
		this->timer = this->timer - (24 * d) * 3600;
		updateTime();
		return *this;
	}
	//Overloading opeator <  /to compare two dates
	bool operator<(const Date& d)
	{
		return this->timer < d.timer;
	}
	//Overloading opeator >  /to compare two dates
	bool operator>(const Date& d)
	{
		return this->timer > d.timer;
	}
	//Overloading opeator >=  /to compare two dates
	bool operator>=(const Date& d)
	{
		return this->timer >= d.timer;
	}
	//Overloading opeator <=  /to compare two dates
	bool operator<=(const Date& d)
	{
		return this->timer <= d.timer;
	}
	//Overloading opeator ==  /to compare two dates
	bool operator==(const Date& d)
	{
		return this->timer == d.timer;
	}
	//Overloading opeator !=  /to compare two dates
	bool operator!=(const Date& d)
	{
		return this->timer != d.timer;
	}

	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	
	string getDate()
	{
		string date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
		return date;
	}

	friend ostream& operator<<(ostream& os,const Date& d);
	friend istream& operator>>(istream& is, Date& d);
};