@echo off

if "%1" == "" (
    echo Usage: swe ^<folder^> ^<file^>
    goto :exit
)

if "%2" == "" (
    echo Usage: swe ^<folder^> ^<file^>
    goto :exit
)

if exist "%~dp0\src\main.cpp" (
    del "%~dp0\src\main.cpp"
) else (
    goto :skip
)

:skip
mklink /H "%~dp0\src\main.cpp" "%~dp0\src_swe\%1\%2.cpp"

:exit