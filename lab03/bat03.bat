@echo off
chcp 1251 > nul

set /p directory=Введіть шлях до каталогу, в якому потрібно шукати підкаталог: 
set /p subdirectory=^Введіть ім'я підкаталога, який потрібно знайти: 

set "fullpath=%directory%\%subdirectory%"

if exist "%fullpath%" (
    echo.
    echo Підкаталог '%subdirectory%' знайдено в каталозі '%directory%'!
) else (
    echo.
    echo Підкаталог '%subdirectory%' не знайдено в каталозі '%directory%'!
)

echo.
pause
