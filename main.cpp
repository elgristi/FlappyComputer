#include <iostream>
#include <SFML/Graphics.hpp>
#include "Computer.hpp"
#include "Parallax.hpp"
#include "UiSound.hpp"

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

    UISound uis;

    while(window.isOpen())
    {
        Computer *computer = new Computer(210,350);
        Parallax *parallax = new Parallax();
        initiated = false;
        uis.initiate(false);

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
                
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !pressed)
                {
                    computer->Jump();
                    pressed = true;
                    uis.wing();
                    if(!initiated)
                    {
                        initiated = true;
                        computer->Initiated();
                        parallax->Initiated();
                        uis.initiate(true);
                    }
                }

                sf::IntRect Rect(computer->GetPosition().x-23, computer->GetPosition().y-21, 44, 40);
                if(parallax->Collision(Rect) || computer->GetPosition().y < 0 || computer->GetPosition().y > (700-136))
                {
                    computer->Death();
                    uis.gameOver();
                }
            }
            else 
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !pressed)
                {
                    pressed = true;
                    break; 
                }
            }

            if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)) pressed = false;

            uis.SetScore(parallax->Score());
            parallax->SetVel(1+(parallax->Score()*0.05f));

            window.clear();
            window.draw(back);
            window.draw(*parallax);
            window.draw(*computer);
            window.draw(uis);
            window.display();
        }

        delete parallax;
        delete computer;
    }
    return 0;
}