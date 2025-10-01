@echo off
setlocal enabledelayedexpansion
set "SOURCES=OptionSimulator.cpp"

REM use files in Options directory
for /r Options %%f in (*.cpp) do (
    set "SOURCES=!SOURCES! %%f"
)

REM use files in UtilitiesDJD directory and sub-directories
for /r UtilitiesDJD %%f in (*.cpp) do (
    set "SOURCES=!SOURCES! %%f"
)

REM compile the code
cl /EHsc /I Options /I UtilitiesDJD !SOURCES!