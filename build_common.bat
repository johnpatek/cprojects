@echo off
cd common\iocolors
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