:: This script is used to make an executable
:: for the CPPFun project using LLVM and clang++

:: To install LLVM with Chocolatey in PowerShell:
:: choco install llvm -y

@ECHO OFF

:: NOTE: Clear the terminal screen
CLS
SET EXE_NAME=CPPFun.exe
ECHO Starting...

@ECHO ON

:: NOTE: Create object files for linker
clang++ -c .\CPPFun.cpp -o CPPFun.obj

:: NOTE: Use object files to create executable
clang++ .\CPPFun.obj -o "%EXE_NAME%"

@ECHO OFF

:: NOTE: Cleanup useless files
DEL -Force .\CPPFun.obj
ECHO.
ECHO Created executable: "%EXE_NAME%"
ECHO.

@ECHO ON
