@echo off
cmake -B build -G Ninja >nul 2>&1
cmake --build build >nul 2>&1
.\build\Debug\MyCppApp.exe
