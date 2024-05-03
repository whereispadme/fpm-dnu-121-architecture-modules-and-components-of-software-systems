#pragma once

#include "function.h"

constexpr auto UP = 72;
constexpr auto DOWN = 80;
constexpr auto ENTER = 13;

class Menu
{

protected:
	std::vector<std::string> vectorString;
	std::string title;

private:
	void cursorStrMenu(std::string str, int color, bool flag)
	{
		std::string cursor = ">  ";
		setColorText(color);

		if (flag)
		{
			str = cursor + str;
			std::cout << str;
		}
		else
		{
			std::cout << str;
			for (int i = 0; i < 100; ++i)
				std::cout << " ";
		}
	}

public:
	Menu(std::vector<std::string> vectorString, std::string title) { this->vectorString = vectorString; this->title = title; }
	~Menu() {}

	unsigned int showMenu()
	{
		short x = 0;
		short y = 0;

		int key = 0;
		int activeMenu = 0;

		unsigned int count = 0;

		while (true)
		{
			gotoxy(10, 0);
			setColorText(14);
			std::cout << title << std::endl << std::endl;
			setCursorState(false);

			x = 10;
			y = 3;

			for (int i = 0; i < this->vectorString.size(); ++i)
			{
				if (i == activeMenu)
				{
					gotoxy(x, ++y);
					cursorStrMenu(vectorString[i], 10, true);
				}
				else
				{
					gotoxy(x, ++y);
					cursorStrMenu(vectorString[i], 14, false);
				}
			}

			key = _getch();

			switch (key)
			{

			case UP:
				(activeMenu > 0) ? --activeMenu : activeMenu = this->vectorString.size() - 1;
				break;

			case DOWN:
				(activeMenu < this->vectorString.size() - 1) ? ++activeMenu : activeMenu = 0;
				break;

			case ENTER:
				return activeMenu;
			}
		}
	}

};