@echo off
setlocal EnableDelayedExpansion

for /F %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"

echo %ESC%[35m============================================%ESC%[0m
echo %ESC%[35mBuilding Tiamo.exe...%ESC%[0m
echo %ESC%[35m============================================%ESC%[0m

set COMPILER=g++
set FLAGS=-std=c++20 -Wall -Wextra -O2

set OUT_DIR=build
set EXE_NAME=Tiamo.exe

if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"

set SOURCES=

for %%f in (*.cpp) do (
    echo Found: %%f
    set SOURCES=!SOURCES! "%%f"
)

if "%SOURCES%"=="" (
    echo %ESC%[31mNO .cpp FILES FOUND%ESC%[0m
    pause
    exit /b 1
)

echo.
echo %ESC%[33mCompiling and Linking...%ESC%[0m
%COMPILER% %SOURCES% %FLAGS% -lgdi32 -luser32 -o "%OUT_DIR%\%EXE_NAME%"

if errorlevel 1 (
    echo.
    echo %ESC%[31mBuild FAILED%ESC%[0m
    pause
    exit /b 1
)

echo.
echo %ESC%[32mBuild SUCCESS%ESC%[0m
echo %ESC%[32mOutput: %OUT_DIR%\%EXE_NAME%%ESC%[0m
echo ============================================
pause