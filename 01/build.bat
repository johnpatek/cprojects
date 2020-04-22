@echo off
if not exist build mkdir build
cd build
cmake ..
msbuild ALL_BUILD.vcxproj
cd ..