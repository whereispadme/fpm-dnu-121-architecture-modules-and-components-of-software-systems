@echo off
chcp 1251 > nul

set "desktop=%USERPROFILE%\Desktop"

mkdir "%desktop%\Лабораторні\ПЗ-23у-1\Кущевський Андрій Петрович\batch\Прихована папка"
mkdir "%desktop%\Лабораторні\ПЗ-23у-1\Кущевський Андрій Петрович\batch\Не прихована папка"
tree "%desktop%\Лабораторні"

attrib +h "%desktop%\Лабораторні\ПЗ-23у-1\Кущевський Андрій Петрович\batch\Прихована папка"
tree "%desktop%\Лабораторні"

help xcopy
help xcopy > "%desktop%\Лабораторні\ПЗ-23у-1\Кущевський Андрій Петрович\batch\Не прихована папка\copyhelp.txt"
type "%desktop%\Лабораторні\ПЗ-23у-1\Кущевський Андрій Петрович\batch\Не прихована папка\copyhelp.txt"

xcopy "%desktop%\Лабораторні\ПЗ-23у-1\Кущевський Андрій Петрович\batch\Не прихована папка\copyhelp.txt" "%desktop%\Лабораторні\ПЗ-23у-1\Кущевський Андрій Петрович\batch\Прихована папка\copied_copyhelp.txt"
type "%desktop%\Лабораторні\ПЗ-23у-1\Кущевський Андрій Петрович\batch\Прихована папка\copied_copyhelp.txt"

echo.
pause
