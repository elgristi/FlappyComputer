#include <iostream>
#include <SFML/Graphics.hpp>
#include "Computer.hpp"
#include "Parallax.hpp"

/*

COPIA PARA COPILAR:
g++ main.cpp Computer.cpp Obstacle.cpp Parallax.cpp -o FlappyComputer -lsfml-graphics -lsfml-window -lsfml-system

COPIA PARA EJECUTAR (En consola para ver errores)
./FlappyComputer

*/

int main()
{

    sf::Texture backT;
    sf::Sprite back;

    if(!backT.loadFromFile("resources/sprites/background.png"))
    {
        std::cout<<"Error al cargar textura de background.png \n";
    }

    back.setTexture(backT);
    back.setPosition(0,-15);
    back.setScale(1.5f,1.5f);


    bool initiated;
    bool pressed;

    //Crear ventana
    sf::RenderWindow window(sf::VideoMode(400,700),"Flappy Computer");
    window.setFramerateLimit(60);
    
    pressed = false;

    while(window.isOpen())
    {
        //
        // Inicializacion
        //

        Computer *computer = new Computer(210,350);
        Parallax *parallax = new Parallax();
        initiated = false;
        

        while (true)
        {
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type==sf::Event::Closed)
                {
                    window.close();
                    return 0;
                }
            }
            
            computer->Update();

            if(computer->GetLive())
            {
                parallax->Update();
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!pressed)
                {
                    computer->Jump();
                    pressed = true;
                    if(!initiated)
                    {
                        initiated = true;
                        computer->Initiated();
                        parallax ->Initiated();
                    }
                }
                else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && pressed)
                {
                    pressed = false;
                    
                }
            }else{
                break;
            }
            sf::IntRect Rect(computer->GetPosition().x-23,computer->GetPosition().y-21,44,40);
            if(parallax->Collision(Rect))
            {
                computer->Death();
            }

            if(computer->GetPosition().y<0||computer->GetPosition().y>(700-136))
            {
                computer->Death();
            }

            window.clear();
            window.draw(back);
            window.draw(*parallax);
            window.draw(*computer);
            window.display();
        }

        delete parallax;
        delete computer;
    }
    return 0;
}