@echo off
chcp 1251 > nul

set /p directory=������ ���� �� ��������, � ����� ������� ������ ���������: 
set /p subdirectory=^������ ��'� ����������, ���� ������� ������: 

set "fullpath=%directory%\%subdirectory%"

if exist "%fullpath%" (
    echo.
    echo ϳ�������� '%subdirectory%' �������� � ������� '%directory%'!
) else (
    echo.
    echo ϳ�������� '%subdirectory%' �� �������� � ������� '%directory%'!
)

echo.
pause
