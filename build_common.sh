cd common
git submodule update --init --recursive
cd iocolors
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