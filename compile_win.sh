#!/bin/bash
export SFML_PATH="/home/victor/Documentos/FlappyComputer/SFML-2.6.1"

# 1. Agregamos -DSFML_STATIC si usas las librerías .a (estáticas)
# 2. Corregimos el orden: las librerías que dependen de otras van PRIMERO
# 3. Agregamos las dependencias de Windows (opengl32, winmm, gdi32)

x86_64-w64-mingw32-g++ main.cpp Computer.cpp Obstacle.cpp Parallax.cpp -o FlappyComputer.exe \
-I$SFML_PATH/include \
-L$SFML_PATH/lib \
-DSFML_STATIC \
-lsfml-graphics-s -lsfml-window-s -lsfml-system-s \
-lopengl32 -lwinmm -lgdi32 -lfreetype \
-static-libgcc -static-libstdc++ -lpthread

echo "Compilación para Windows finalizada."
