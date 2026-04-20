#!/bin/bash

# Compilación con flags de seguridad y optimización
g++ -std=c++17 -Wall main.cpp Computer.cpp Obstacle.cpp Parallax.cpp UiSound.cpp \
    -o FlappyComputer \
    -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

# Verificar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "-----------------------------"
    echo "Linux copilation ended"
    echo "-----------------------------"
else
    echo "Linux copilation error."
    exit 1
fi