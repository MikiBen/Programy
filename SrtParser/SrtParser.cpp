#include <iostream>
#include "SrtParser.h"

int main()
{
	SrtParser B;
	string fileName = "Friends.srt";
	B.readSubtitlesFromFile(fileName);
	//B.showSubtitles();
}

