@echo off
chcp 1251 > nul

set /p filepath=������ ���� �� ����� � �����: 

if exist "%filepath%" (
    start "" "%filepath%"
) else (
    echo.
    echo ���� �� ���������� ������ �� ��������.
)

echo.
pause