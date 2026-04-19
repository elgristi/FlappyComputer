#include "Parallax.hpp"

Parallax::Parallax(){
    initiated = false;
    score = 0;

    if(!obstacleTexture.loadFromFile("resources/sprites/pipe.png"))
    {
        std::cout<<"Error al cargar la textura pipe.png \n";
    }

    if(!baseTexture.loadFromFile("resources/sprites/base.png"))
    {
         std::cout<<"Error al cargar la textura base.png \n";
    }

    srand(time(NULL));

    obstacles.push_back(Obstacle(obstacleTexture,500,100+rand()%250));
    obstacles.push_back(Obstacle(obstacleTexture,800,100+rand()%250));

    sf::Sprite NewSprite;
    NewSprite.setTexture(baseTexture);
    NewSprite.setPosition(0,700-112);
    NewSprite.setScale(1.5f,1.5f);
    bases.push_back(NewSprite);
    NewSprite.setPosition(336*1.5f,700-112);
    bases.push_back(NewSprite);

}

void Parallax::Update(){

    for(int i = 0; i < bases.size(); i++)
    {
        if(bases[i].getPosition().x < -(336*1.5f))
        {
            sf::Sprite NewSprite = bases[bases.size()-1];
            NewSprite.setPosition(NewSprite.getPosition().x+336*1.5f,700-112);
            bases.push_back(NewSprite);
            bases.erase(bases.begin()+i);
            continue;
        }
    }

    for(int i = 0; i < bases.size(); i++)
    {
        bases[i].move(-2.5,0);
    }
    
    if(!initiated) return;

    int ult = obstacles.size()-1;

    for(int i = 0; i < obstacles.size();i++)
    {
        
        if(obstacles[i].GetPosition().x<100&&i>last)
        {
            last=i;
            score++;
        }

        if(obstacles[i].GetPosition().x<=-100)
        {
            obstacles.push_back(Obstacle{obstacleTexture,static_cast<int>(obstacles[ult].GetPosition().x + 350),100+rand()%250});
            obstacles.erase(obstacles.begin()+i); 
        }
    }

    for(int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i].Update();
    }

    std::cout<<bases.size()<<" ";
}

bool Parallax::Collision(sf::IntRect rect)
{
    for(int i=0; i < obstacles.size(); i++)
    {
        if (obstacles[i].Collision(rect)) 
        {
            return true;
        }
    }

    return false;
}

int Parallax::Score()
{
    return score;
}

void Parallax::Initiated(){
    initiated = true;
}

void Parallax::draw(sf::RenderTarget &rt, sf::RenderStates rs) const{
    for(int i = 0; i < obstacles.size(); i++)rt.draw(obstacles[i],rs);
    for(int i = 0; i < bases.size(); i++)rt.draw(bases[i],rs);
}