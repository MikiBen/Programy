#pragma once
#include<vector>
#include<string>
#include <fstream>
#include <sstream>
#include<algorithm>

using namespace std;

class SrtParser
{
private:
	vector <pair<double, string>> AllSubtitles;
	fstream file;
	fstream fileOutput;
	double timeShow;
	double timeHide;
	string subtitles;

public:
	SrtParser() {}
	~SrtParser()
	{
		if (file.is_open())
			file.close();
		if (fileOutput.is_open())
			fileOutput.close();
	}

	void readSubtitlesFromFile(const string name)
	{
		string line;
		file.open(name, ios::in);

		if (file.is_open())
		{
			while (!file.eof())
			{
				line = "";
				getline(file, line);

				if (checkSign(line))
				{
					setTime(line);
					getline(file, line);

					subtitles = "";
					while (checkEmptyLine(line))
					{
						subtitles = subtitles + line + "\n";
						getline(file, line);
					}
					addLine();
				}
			}
		}
		file.close();
	}

	void showSubtitles()
	{
		string line;
		for (auto i = 0; i < AllSubtitles.size(); i++)
		{
			line = "";
			sortVector();
			if (AllSubtitles[i].second != "")
			{
				line = AllSubtitles[i].second;
				line.replace(line.size() - 1, 1, "");
			}
			cout << "at " << AllSubtitles[i].first << " show '" << line << "'"<<endl;
		}
	}

	void safeSubtitlesToFile()
	{
		fileOutput.open("output.txt", ios::out | ios::app);

		string line;
		for (auto i = 0; i < AllSubtitles.size(); i++)
		{
			line = "";
			sortVector();
			if (AllSubtitles[i].second != "")
			{
				line = AllSubtitles[i].second;
				line.replace(line.size() - 1, 1, "");
			}
			fileOutput << "at " << AllSubtitles[i].first << " show '" << line << "'" << endl;
		}
		file.close();
	}

private:
	bool checkEmptyLine(const string line)
	{
		if (line != "")
			return true;
		else return false;
	}

	bool checkSign(const string line)
	{
		string character = "-->";
		if (line.find(character) == -1)
			return false;
		else return true;
	}

	void setTime(string& line)
	{
		removeSign(line, ' ');
		removeSign(line, ':');
		replaceSign(line);
		timeShow = timeBegin(line);
		timeHide = timeEnd(line);
	}

	void removeSign(string& line, const char sign)
	{
		while (line.find_first_of(sign) != -1)
		{
			line.erase(line.find_first_of(sign), 1);
		}
	}

	void replaceSign(string& line)
	{
		while (line.find_first_of(",") != -1)
		{
			line.replace(line.find_first_of(","), 1, ".");
		}
	}

	double timeBegin(string line)
	{
		line = line.substr(0, line.find_first_of("-"));
		return stringToDouble(line);
	}

	double timeEnd(string line)
	{
		line = line.substr(line.find_first_of(">") + 1, line.size());
		return stringToDouble(line);
	}

	double stringToDouble(string& line)
	{
		double number;
		istringstream(line) >> number;
		return number;
	}

	void addLine()
	{
		if (AllSubtitles.size() == 0)
		{
			addPair();
		}
		else
		{
			if (checkTimeStart())
			{
				addPair();
			}
			else
			{
				addSubtitles();
			}
		}
	}

	bool checkTimeStart()
	{
		return timeShow > AllSubtitles[AllSubtitles.size() - 1].first;
	}

	void addPair()
	{
		AllSubtitles.push_back(make_pair(timeShow, subtitles));
		AllSubtitles.push_back(make_pair(timeHide, ""));
	}

	void addSubtitles()
	{
		int size = AllSubtitles.size();
		if (timeHide > AllSubtitles[size - 1].first)
		{
			addInterSubtitles();
		}
		if (timeHide <= AllSubtitles[size - 1].first)
		{
			addNestedSubtitles();
		}
	}

	void addNestedSubtitles()
	{
		string line = subtitles;
		int size = AllSubtitles.size();

		addTimeHideLower();

		for (auto i = 1; i < AllSubtitles.size(); i++)
		{
			if (timeShow < AllSubtitles[size-i].first && timeHide > AllSubtitles[size-i].first)
			{
				AllSubtitles[size-i].second = AllSubtitles[size-i].second + subtitles;
			}
			size = AllSubtitles.size();
			if (timeShow < AllSubtitles[size-i].first && timeShow > AllSubtitles[size-i-1].first)
			{
				line = AllSubtitles[size-i-1].second + line;
				AllSubtitles.push_back(make_pair(timeShow, line));
				i++;
			}
		}
		sortVector();
	}

	void addTimeHideLower()
	{
		string line;
		int size = AllSubtitles.size();

		for (auto i = 1; i < AllSubtitles.size(); i++)
		{
			line = "";
			sortVector();
			size = AllSubtitles.size();
			if (timeHide < AllSubtitles[size-i].first && timeHide > AllSubtitles[size-i-1].first)
			{
				line = AllSubtitles[size-i-1].second;

				AllSubtitles.push_back(make_pair(timeHide, line));
				i++;
				sortVector();
			}
		}
	}

	void addInterSubtitles()
	{
		string line = subtitles;
		int size = AllSubtitles.size();
		for (auto i = 1; i < AllSubtitles.size(); i++)
		{
			size = AllSubtitles.size();
			if (timeShow < AllSubtitles[size-i].first)
			{
				line = AllSubtitles[size-i-1].second + line;

				AllSubtitles[size-1].second = subtitles;
				AllSubtitles.push_back(make_pair(timeShow, line));
				AllSubtitles.push_back(make_pair(timeHide, ""));
				i++;
				sortVector();
			}
		}

		if (timeShow == AllSubtitles[size-1].first)
		{
			AllSubtitles[size-1].second = subtitles;
			AllSubtitles.push_back(make_pair(timeHide, ""));
		}
	}

	void sortVector()
	{
		sort(AllSubtitles.begin(), AllSubtitles.end(), []
		(const pair<double, string>a, const pair<double, string>b)
			{
				return a.first < b.first;
			});
	}

};