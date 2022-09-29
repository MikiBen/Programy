#pragma once

using namespace std;
class String
{
private:
	string word;

public:
	String() {}
	String(const String& str) {

		this->word = str.word;
	}

	//overloading -=
	String& operator-=(const String& str)
	{
		int location;
		location = this->word.find(str.word);

		if (location >= 0)
			this->word.erase(location, str.word.size());

		return *this;
	}

	void setString(string str)
	{
		word = str;
	}

	string getString()
	{
		return word;
	}

};