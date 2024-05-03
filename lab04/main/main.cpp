#include "function.h"
#include "menu.h"

using namespace std;

wstring stringToWideString(const string& str)
{
    wstring wideStr(str.begin(), str.end());
    return wideStr;
}

bool searchSubdirectory()
{
    string directoryName;
    string subdirectoryName;

	bool searchHiddenDirectories;
	bool searchReadOnlyDirectories;

    std::cout << "Введіть шлях до каталогу: ";
    getline(cin, directoryName);

	std::cout << "Введіть ім'я підкаталогу, який потрібно знайти: ";
    getline(cin, subdirectoryName);

	std::cout << std::endl;

	std::cout << "Шукати підкаталоги з встановленим атрибутом 'Тільки для читання'? (1 - Так, 0 - Ні): ";
	std::cin >> searchReadOnlyDirectories;

	std::cout << "Шукати підкаталоги з встановленим атрибутом 'Скритий'? (1 - Так, 0 - Ні): ";
	std::cin >> searchHiddenDirectories;

	std::cout << std::endl;
	string command = "tree /f " + directoryName;
	system(command.c_str());

	string searchPath = directoryName + "\\*";
	if (!searchReadOnlyDirectories)
	{
		searchPath += " /A:R";
	}

	if (!searchHiddenDirectories)
	{
		searchPath += " /A:-H";
	}

    WIN32_FIND_DATAW findData;
	wstring wSearchPath = stringToWideString(searchPath);
	HANDLE hFind = FindFirstFileW(wSearchPath.c_str(), &findData);

    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && wstring(findData.cFileName) == stringToWideString(subdirectoryName))
            {
				setColorText(10);
				std::cout << "Підкаталог '" << subdirectoryName << "' знайдено в каталозі '" << directoryName << "'!" << std::endl;
				setColorText(14);
				FindClose(hFind);
                return true;
            }
        } while (FindNextFileW(hFind, &findData) != 0);

        FindClose(hFind);
    }

	setColorText(12);
	std::cout << "Підкаталог '" << subdirectoryName << "' не знайдено в каталозі '" << directoryName << "'!" << std::endl;
	setColorText(14);
	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"КущевськийАндрiй, ПЗ-23у-1");
	
	std::vector<std::string> vectorString;
	vectorString.push_back("Пошук");
	vectorString.push_back("Завершити роботу програми");

	Menu menu(vectorString, "# Варіант 10. Знайти в каталозі підкаталог з заданим ім'ям");

	while (true)
	{
		switch (menu.showMenu())
		{
		case 0:
			startProcedure();
			searchSubdirectory();
			endProcedure(true);
			break;

		case 1:
			system("cls");
			setColorText(14);
			return false;
		}
	}

	return 0;
}