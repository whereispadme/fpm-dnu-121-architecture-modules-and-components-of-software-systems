#pragma once

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <string>
#include <regex>
#include <ctime>
#include <Windows.h>

using namespace std;

void clearCinBuff()
{
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

void setCursorState(bool flag)
{
	_CONSOLE_CURSOR_INFO info;
	info.bVisible = flag;
	info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void setColorText(short item)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), item);
}

void setErrorColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}

void setDefaultColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}

void startProcedure()
{
	system("cls");
	clearCinBuff();
	setCursorState(true);
	setColorText(14);
}

void endProcedure(bool isAfterInput)
{
	clearCinBuff();
	if (isAfterInput)
		std::cout << std::endl;
	else
		std::cout << std::endl << std::endl;
	system("pause");
	setCursorState(false);
	setColorText(14);
	system("cls");
}

void gotoxy(short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}