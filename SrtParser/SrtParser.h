#pragma once
#include<vector>
#include<string>
#include <fstream>
#include <sstream>
#include<algorithm>

using namespace std;

struct Subtitles
{
	double time_show;
	double time_hide;
	string line;
	bool isIntersecting = false;
	bool isNested = false;
	bool isShowHideWrong = false;
};

class SrtParser
{
private:
	vector<Subtitles> AllSubtitles;
	fstream file;
	fstream fileOutput;
	Subtitles subtitles;

public:
	SrtParser() {}
	~SrtParser()
	{
		if (file.is_open())
			file.close();
		if (fileOutput.is_open())
			fileOutput.close();
	}

	void showSubtitles()
	{
		for (auto i = 0; i < AllSubtitles.size(); i++)
		{
			cout << "Time show: " << AllSubtitles[i].time_show << endl;
			cout << "Time hide: " << AllSubtitles[i].time_hide << endl;
			cout << "Subtitle: " << AllSubtitles[i].line << endl;
			cout << "Is subtitle is intersecting: " << AllSubtitles[i].isIntersecting << endl;
			cout << "Is subtitle is nested: " << AllSubtitles[i].isNested << endl;
			cout << "Is hide/show time is correct: " << AllSubtitles[i].isShowHideWrong << endl << endl;
		}
	}

	void readSubtitlesFromFile(const string name)
	{
		string line;
		file.open(name, ios::in);

		if (file.is_open())
		{
			while (!file.eof())
			{
				getline(file, line);
				subtitles.line = "";
				if (checkSign(line))
				{
					setTime(line);
					getline(file, line);

					while (checkEmptyLine(line))
					{
						subtitles.line = subtitles.line + line + " ";
						getline(file, line);
					}
					AllSubtitles.push_back(subtitles);
				}
			}
		}

		file.close();
		sortByTimeBegin();
		checkIntersectingSubtitles();
		checkNestedSubtitles();
		checkHideShowIsWrong();
		safeSubtitlesToFile();
	}

private:
	void checkHideShowIsWrong()
	{
		for (auto i = 0; i < AllSubtitles.size(); i++)
			if (AllSubtitles[i].time_show >= AllSubtitles[i].time_hide)
				AllSubtitles[i].isShowHideWrong = true;
	}

	void safeSubtitlesToFile()
	{
		fileOutput.open("output.txt", ios::out | ios::app);

		for (auto i = 0; i < AllSubtitles.size(); i++)
		{
			fileOutput << "Time show: " << AllSubtitles[i].time_show << endl;
			fileOutput << "Time hide: " << AllSubtitles[i].time_hide << endl;
			fileOutput << "Subtitle: " << AllSubtitles[i].line << endl;
			fileOutput << "Is subtitle is intersecting: " << AllSubtitles[i].isIntersecting << endl;
			fileOutput << "Is subtitle is nested: " << AllSubtitles[i].isNested << endl;
			fileOutput << "Is hide/show time is correct: " << AllSubtitles[i].isShowHideWrong << endl << endl;
		}
		file.close();
	}

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
		subtitles.time_show = timeBegin(line);
		subtitles.time_hide = timeEnd(line);
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

	void sortByTimeBegin()
	{
		sort(AllSubtitles.begin(), AllSubtitles.end(),
			[](const Subtitles a, const Subtitles b)
			{
				return a.time_show < b.time_show;
			});
	}

	void checkIntersectingSubtitles()
	{
		int j;
		for (auto i = 0; i < AllSubtitles.size() - 1; i++)
		{
			j = 1;
			while (compareTime(i, j))
			{
				AllSubtitles[i + j].isIntersecting = true;
				j++;
			}
		}
	}

	bool compareTime(const int i, const int j)
	{
		if (i + j >= AllSubtitles.size()) return false;
		if (AllSubtitles[i].time_hide > AllSubtitles[i + j].time_show &&
			AllSubtitles[i].time_hide < AllSubtitles[i + j].time_hide)
			return true;
		else return false;
	}

	void checkNestedSubtitles()
	{
		int j;
		for (auto i = 0; i < AllSubtitles.size() - 1; i++)
		{
			j = 1;
			while (compareNestedTime(i, j))
			{
				AllSubtitles[i + j].isNested = true;
				j++;
			}
		}
	}

	bool compareNestedTime(const int i, const int j)
	{
		if (i + j >= AllSubtitles.size()) return false;
		if ((AllSubtitles[i].time_show < AllSubtitles[i + j].time_show) &&
			(AllSubtitles[i].time_hide > AllSubtitles[i + j].time_hide))
			return true;
		else return false;
	}
};
