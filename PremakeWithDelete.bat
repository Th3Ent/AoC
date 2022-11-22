@echo off
cls

del /S /Q build\*
rmdir /S /Q build\*
del /S /Q bin\*
rmdir /S /Q bin\*

rmdir /S /Q build
rmdir /S /Q bin

cls

.\premake5 vs2019

pause
