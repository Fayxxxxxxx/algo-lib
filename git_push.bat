@echo off
cd /d C:\algo

echo.
echo  ================================
echo    Git Push Helper
echo  ================================
echo.
echo  Files changed:
git status --short
echo.
echo  --------------------------------
echo  [1] Push ALL (recommended)
echo  [2] Push ONE file
echo  [3] Push ONE folder
echo  [0] Exit
echo  --------------------------------
set /p choice="Choose (0/1/2/3): "

if "%choice%"=="0" exit /b
if "%choice%"=="1" goto all
if "%choice%"=="2" goto one
if "%choice%"=="3" goto folder
echo Invalid choice. Bye!
pause
exit /b

:all
git add .
set /p msg="Commit message: "
git commit -m "%msg%"
git push
echo.
echo Done! Press any key to close...
pause >nul
exit /b

:one
echo.
echo All .cpp files:
dir /b /s *.cpp 2>nul
echo.
set /p file="File name (or path): "
git add "%file%"
set /p msg="Commit message: "
git commit -m "%msg%"
git push
echo.
echo Done! Press any key to close...
pause >nul
exit /b

:folder
set /p dir="Folder name: "
git add "%dir%/"
set /p msg="Commit message: "
git commit -m "%msg%"
git push
echo.
echo Done! Press any key to close...
pause >nul
exit /b
