@echo off
chcp 1251 > nul

set /p filepath=Введіть шлях до файлу зі звітом: 

if exist "%filepath%" (
    start "" "%filepath%"
) else (
    echo.
    echo Файл із зазначеним шляхом не знайдено.
)

echo.
pause