@echo off
cd common
git submodule update --init --recursive
cd iocolors
if not exist build mkdir build
cd build
cmake ..
msbuild -verbosity:m INSTALL.vcxproj
cd ..\..
if not exist build mkdir build
cd build
cmake ..
msbuild -verbosity:m INSTALL.vcxproj
cd ..\..