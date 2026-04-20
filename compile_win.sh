#!/bin/bash
export SFML_PATH="/home/victor/SFML-2.6.1"

x86_64-w64-mingw32-g++ main.cpp Computer.cpp Obstacle.cpp Parallax.cpp UiSound.cpp -o FlappyComputer.exe \
-I$SFML_PATH/include \
-L$SFML_PATH/lib \
-DSFML_STATIC \
-lsfml-audio-s -lsfml-graphics-s -lsfml-window-s -lsfml-system-s \
-lopenal32 -lFLAC -lvorbisenc -lvorbisfile -lvorbis -logg \
-lopengl32 -lwinmm -lgdi32 -lfreetype \
-static-libgcc -static-libstdc++ -lpthread \
-mwindows

echo "Windows compilation ended"
