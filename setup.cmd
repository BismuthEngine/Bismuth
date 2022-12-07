@echo off

echo Installing Bismuth Build Tool

CALL npm i -g git+https://github.com/BismuthEngine/BismuthBuildTool.git

echo Compiling

bismuth-build-tool --compile ./ --editor

pause