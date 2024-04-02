#!/bin/bash
#compile lxqt tools
echo -e "\e[32m---------------compile lxqt-build-tools-0.13.0---------------\e[0m"
cd lxqt-build-tools-0.13.0
rm -r ./build
mkdir build && cd build
cmake .. && make
cd .. && cd ..

#compile qterminal
echo -e "\e[32m---------------compile qtermwidget-----------------\e[0m"
cp ./lxqt-build-tools-0.13.0/build/lxqt-build-tools-config.cmake ./lxqt-build-tools-0.13.0/build/lxqt-build-tools-config-version.cmake ./qtermwidget/cmake
cd ./qtermwidget
rm -r ./build
mkdir build && cd build
cmake .. && make
cd .. && cd ..

#compile pid_assiant
echo -e "\e[32m---------------compile pid_assiant-----------------\e[0m"
rm ./PID_Assiant/cmake/*
cp ./qtermwidget/build/qtermwidget5-config.cmake ./qtermwidget/build/qtermwidget5-config-version.cmake ./qtermwidget/build/qtermwidget5-targets.cmake ./PID_Assiant/cmake
cd PID_Assiant
rm -r ./build
mkdir build && cd build
cmake .. && make
cp -r ../template ./

echo -e "\e[32m---------------compile finish-----------------\e[0m"
