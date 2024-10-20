@echo off

if exist "%~dp0\src\main.cpp" del "%~dp0\src\main.cpp"

if "%1" == "" (
    echo swe - Switch experiment
    echo Usage: swe ^<folder^> ^<file^>
    goto exit
)

if "%2" == "" (
    echo swe - Switch experiment
    echo Usage: swe ^<folder^> ^<file^>
    goto exit
)

mklink /H "%~dp0\src\main.cpp" "%~dp0\src_swe\%1\%2.cpp"

:exit