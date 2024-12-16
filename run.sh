#!/bin/bash

# precisa desta dependencia para compilar o projeto
# sudo apt install nlohmann-json3-dev

#cd cpp
#cmake . -DCMAKE_BUILD_TYPE=Release -DCPP_FETCH_DEPS=ON
#cmake --build .

#cd ..

#!/bin/bash

# Function to check and install packages
install_package() {
    PACKAGE=$1
    dpkg -l | grep -qw $PACKAGE || sudo apt-get install -y $PACKAGE
}

echo "Checking dependencies..."

# Checking SDL2
echo "Checking SDL2..."
dpkg -l | grep -qw libsdl2-dev || install_package libsdl2-dev

# Checking Google Test
echo "Checking Google Test..."
dpkg -l | grep -qw libgtest-dev || install_package libgtest-dev

# Checking pigpio
echo "Checking pigpio..."
dpkg -l | grep -qw pigpio || install_package pigpio

echo "Check and installation complete!"


sudo ip link set can0 type can bitrate 500000
sudo ip link set can0 up

git submodule sync --recursive
git submodule update --init --recursive
git submodule update --recursive --remote

cmake -S . -B build
cd build
make
cd ..
./build/MainCarServer

