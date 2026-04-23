#include "Parallax.hpp"

Parallax::Parallax(){

    lastI = 0;
    last = -1;
    initiated = false;
    score = 0;
    vel = 1;

    if(!obstacleTexture.loadFromFile("resources/sprites/pipe.png"))
    {
        std::cout<<"Error al cargar la textura pipe.png \n";
    }

    if(!baseTexture.loadFromFile("resources/sprites/base.png"))
    {
         std::cout<<"Error al cargar la textura base.png \n";
    }

    srand(time(NULL));

    obstacles.push_back(Obstacle(obstacleTexture,500,100+rand()%250,1));
    obstacles.push_back(Obstacle(obstacleTexture,850,100+rand()%250,2));

    sf::Sprite NewSprite;
    NewSprite.setTexture(baseTexture);
    NewSprite.setPosition(0,700-112);
    NewSprite.setScale(1.5f,1.5f);
    bases.push_back(NewSprite);
    NewSprite.setPosition(336*1.5f,700-112);
    bases.push_back(NewSprite);

}


void Parallax::Update()
{
    // --- LÓGICA DE BASES ---
    for(std::size_t i = 0; i < bases.size(); i++)
    {
        // Movimiento de la base
        bases[i].move(-2.5 * vel, 0);

        if(bases[i].getPosition().x <= -(336*1.5f)) 
        {
            float tailX = bases[(i == 0) ? 1 : 0].getPosition().x + 333*1.5f;
            
            bases[i].setPosition(tailX, bases[i].getPosition().y);
        }
    }


    if(!initiated) return;

    // --- LÓGICA DE OBSTÁCULOS ---
    for(std::size_t i = 0; i < obstacles.size(); i++)
    {
        if(obstacles[i].GetPosition().x >= 100 - 2 && obstacles[i].GetPosition().x < 100 + 2 && obstacles[i].getIndex()>lastI)
        {
            score++;
            lastI++;
        }

        if(obstacles[i].GetPosition().x <= -100)
        {
            float lastX = obstacles.back().GetPosition().x;
            obstacles.push_back(Obstacle(obstacleTexture, lastX + 350, 100 + rand() % 250,(lastI+2)));
            obstacles.erase(obstacles.begin() + i);
            i--; 
        }
    }

    for(auto& obs : obstacles) {
        obs.Update(vel);
    }
}

bool Parallax::Collision(sf::IntRect rect)
{
    for(std::size_t i=0; i < obstacles.size(); i++)
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
    for(std::size_t i = 0; i < obstacles.size(); i++)rt.draw(obstacles[i],rs);
    for(std::size_t i = 0; i < bases.size(); i++)rt.draw(bases[i],rs);
}

void Parallax::SetVel(float NewVel){
    if(vel != NewVel)vel = NewVel;
}