#include <iostream>
#include "SrtParser_v3.h"

int main()
{
	SrtParser B;
	string fileName = "TestInput.srt";
	B.readSubtitlesFromFile(fileName);
	B.showSubtitles();
	B.safeSubtitlesToFile();
}

