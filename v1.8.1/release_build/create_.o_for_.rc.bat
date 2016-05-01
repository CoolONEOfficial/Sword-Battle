@echo off
set /p rcName = "Enter .rc name:"
echo Really?
pause
C:\Qt\Tools\mingw492_32\bin\windres.exe -J rc -i %rcName%.rc -o %rcName%.o