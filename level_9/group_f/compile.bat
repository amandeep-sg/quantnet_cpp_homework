@echo off
setlocal enabledelayedexpansion
set "SOURCES=TestBSPDE1.cpp"

REM Use files in UtilitiesDJD directory and sub-directories
for /r UtilitiesDJD %%f in (*.cpp) do (
    set "SOURCES=!SOURCES! %%f"
)

cl /EHsc /I UtilitiesDJD !SOURCES!