#include "Computer.hpp"

Computer::Computer(int x, int y)
{
    
    initiated = false;
    life = true;
    state = 0;
    timerState = 10;
    frameAnim.resize(3);

    //Cargando texturas y avisando si hay errores
    if(!frameAnim[0].loadFromFile("resources/sprites/birdupflap.png"))
    {
      std::cout<<"Error al cargar la textura birdupflap.png \n";
    }

    if(!frameAnim[1].loadFromFile("resources/sprites/birdmidflap.png"))
    {
      std::cout<<"Error al cargar la textura birdmidflap.png \n";
    }

    if(!frameAnim[2].loadFromFile("resources/sprites/birddownflap.png"))
    {
      std::cout<<"Error al cargar la textura birddownlap.png \n";  
    }
    
    sprite.setTexture(frameAnim[state]);
    sprite.setOrigin(17,12);
    sprite.setPosition(x,y);
    sprite.setScale(2,2);
    move = 0;

}

void Computer::Update(){

    if(!life)
    {
        if(sprite.getPosition().y<(700-136))
        {
            sprite.move(0,12);
            sprite.setRotation(sprite.getRotation()+10);
        }
    }

    timerState--;

    if(timerState==0)
    {
        state++;
        state%=3;
        sprite.setTexture(frameAnim[state]);
        sprite.setOrigin(17,12);
        timerState = 10;
    }

    if(!initiated) return;

    sprite.move(0,move);
    move+=0.5f;
    
    if(move>8&&move<15) sprite.setRotation(sprite.getRotation()+4);
    
}

void Computer::Jump(){
    move=-7.5f;
    sprite.setRotation(-15);
}

sf::Vector2f Computer::GetPosition(){
    return sprite.getPosition();
}

bool Computer::GetLive(){
    return life;
}

void Computer::Death(){
    life = false;
}

void Computer::Initiated(){
    initiated=true;
}

void Computer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states); 
}

