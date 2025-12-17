@echo off
setlocal EnableDelayedExpansion

echo ============================================
echo Building RainfrogQuest
echo ============================================

set COMPILER=g++
set FLAGS=-std=c++20 -Wall -Wextra -O2

set OUT_DIR=bin
set EXE_NAME=RainfrogQuest.exe

if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"

set SOURCES=

for %%f in (*.cpp) do (
    echo Found: %%f
    set SOURCES=!SOURCES! "%%f"
)

if "%SOURCES%"=="" (
    echo ❌ NO .cpp FILES FOUND
    pause
    exit /b 1
)

echo.
echo Compiling and Linking...
%COMPILER% %SOURCES% %FLAGS% -lgdi32 -luser32 -o "%OUT_DIR%\%EXE_NAME%"

if errorlevel 1 (
    echo.
    echo ❌ Build FAILED
    pause
    exit /b 1
)

echo.
echo ✅ Build SUCCESS
echo Output: %OUT_DIR%\%EXE_NAME%
echo ============================================
pause