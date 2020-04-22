@echo off
cd common\iocolors
if not exist build mkdir build
cd build
cmake ..
msbuild INSTALL.vcxproj
cd ..\..\..