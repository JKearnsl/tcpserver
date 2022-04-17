#include <iostream>
#include <string>

#include "Server.h"
#include "windows.h"


std::string dirFinder(std::string dir)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;

	std::wstring wstr = std::wstring(dir.begin(), dir.end());
	LPCWSTR swDir = wstr.c_str();

	hf = FindFirstFile(swDir, &FindFileData);

	std::string result;

	if (hf != INVALID_HANDLE_VALUE)
	{
		std::wstring buffFilename;
		do
		{
			buffFilename = FindFileData.cFileName;
			std::string strFilename(buffFilename.begin(), buffFilename.end());

			result += strFilename + "\n";

		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
    return result;
}




int main()
{
    setlocale(LC_ALL, "rus");
    startServer(dirFinder, "127.0.0.1", "27015");
    return 0;
}