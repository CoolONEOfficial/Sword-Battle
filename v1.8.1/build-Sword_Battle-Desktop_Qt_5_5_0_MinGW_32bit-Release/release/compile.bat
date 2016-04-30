@echo off
set /p exeName = "Enter .exe name:"
echo Really?
pause

copy "C:\Qt\5.5\mingw492_32\bin\libstdc++-6.dll" "%CD%"
copy "C:\Qt\5.5\mingw492_32\bin\libwinpthread-1.dll" "%CD%"
copy "C:\Qt\5.5\mingw492_32\bin\libgcc_s_dw2-1.dll" "%CD%"

C:\Qt\5.4\mingw491_32\bin\windeployqt.exe --release %CD%\%exeName%