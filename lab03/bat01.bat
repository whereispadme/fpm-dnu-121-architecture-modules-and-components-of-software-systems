@echo off
chcp 1251 > nul

set "desktop=%USERPROFILE%\Desktop"

mkdir "%desktop%\����������\��-23�-1\���������� ����� ��������\batch\��������� �����"
mkdir "%desktop%\����������\��-23�-1\���������� ����� ��������\batch\�� ��������� �����"
tree "%desktop%\����������"

attrib +h "%desktop%\����������\��-23�-1\���������� ����� ��������\batch\��������� �����"
tree "%desktop%\����������"

help xcopy
help xcopy > "%desktop%\����������\��-23�-1\���������� ����� ��������\batch\�� ��������� �����\copyhelp.txt"
type "%desktop%\����������\��-23�-1\���������� ����� ��������\batch\�� ��������� �����\copyhelp.txt"

xcopy "%desktop%\����������\��-23�-1\���������� ����� ��������\batch\�� ��������� �����\copyhelp.txt" "%desktop%\����������\��-23�-1\���������� ����� ��������\batch\��������� �����\copied_copyhelp.txt"
type "%desktop%\����������\��-23�-1\���������� ����� ��������\batch\��������� �����\copied_copyhelp.txt"

echo.
pause
