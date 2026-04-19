#include "UiSound.hpp"

UISound::UISound()
{
    Initiated = false;
    GameOver = false;

    if(!Font.loadFromFile("resouces/font/font.ttf"))
    {
        std::cout<<"Error al cargar la fuente font.tff \n";
    }

    if(!GameOverT.loadFromFile("resouces/sprites/gameover.png"))
    {
        std::cout<<"Error al cargar la textura gameover.png \n";
    }

    if(!InitT.loadFromFile("resouces/sprites/message.png"))
    {
        std::cout<<"Error al cargar la textura message.png \n";
    }

    if(!PointB.loadFromFile("resouces/sounds/point.ogg"))
    {
        std::cout<<"Error al cargar el sonido point.ogg \n";
    }

    if(!WingB.loadFromFile("resouces/sounds/wing.ogg"))
    {
        std::cout<<"Error al cargar el sonido wing.ogg \n";
    }

    if(!HitB.loadFromFile("resouces/sounds/hit.ogg"))
    {
        std::cout<<"Error al cargar el sonido hit.ogg \n";
    }

    if(!Music.openFromFile("resouces/sounds/music.ogg"))
    {
        std::cout<<"Error al cargar el sonido music.ogg \n";
    }



};