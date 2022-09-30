#pragma once

using namespace std;

namespace String
{
	class String
	{
	private:
		string word;

	public:
		String()
		{
			this->word = "";
		}
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

		//overloading +
		String& operator+(const String& str)
		{
			this->word = this->word + " " + str.word;

			return *this;
		}

		void setString(const string str)
		{
			word = str;
		}

		string getString()
		{
			return word;
		}

		friend ostream& operator<<(ostream& os, const String& s);
		friend istream& operator>>(istream& is, String& s);
	};
}