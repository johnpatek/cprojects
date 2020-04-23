cd common/iocolors
if [ ! -d "build" ]; then
    mkdir build
fi
cd build
cmake ..
make install
cd ../..
if [ ! -d "build" ]; then
    mkdir build
fi
cd build
cmake ..
make install
cd ../..