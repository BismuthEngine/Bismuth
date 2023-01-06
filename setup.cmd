@echo off
cls
color ce

echo Installing Bismuth Build Tool

CALL npm i -g --unsafe-perm=true --allow-root git+https://github.com/BismuthEngine/BismuthBuildTool.git || CALL :bbt_install_failed

echo Compiling

CALL bismuth-build-tool --compile ./ --editor --no-bmt

echo Installing Bismuth Project Tool

CALL npm i -g --unsafe-perm=true --allow-root git+https://github.com/BismuthEngine/BismuthProjectTool.git || CALL :bpt_install_failed

pause
EXIT /B 0

:bbt_install_failed
cls
color f4
echo . && echo . && echo . && echo .
echo Failed installing Bismuth Build Tool
echo See https://github.com/BismuthEngine/BismuthBuildTool for installation guide
set /p redirect=Press Y to open link in browser, or any key to close...
if "%redirect%" == "Y" (start https://github.com/BismuthEngine/BismuthBuildTool)
if "%redirect%" == "y" (start https://github.com/BismuthEngine/BismuthBuildTool)
EXIT 0

:bpt_install_failed
cls
color f4
echo . && echo . && echo . && echo .
echo Failed installing Bismuth Project Tool
echo See https://github.com/BismuthEngine/BismuthProjectTool for installation guide
set /p redirect=Press Y to open link in browser, or any key to close...
if "%redirect%" == "Y" (start https://github.com/BismuthEngine/BismuthProjectTool)
if "%redirect%" == "y" (start https://github.com/BismuthEngine/BismuthProjectTool)
EXIT 0