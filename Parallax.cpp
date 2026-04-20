#include "Parallax.hpp"

Parallax::Parallax(){

    last = -1;
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


void Parallax::Update()
{
    // ... (Tu lógica de bases sigue igual) ...

    if(!initiated) return;

    for(std::size_t i = 0; i < obstacles.size(); i++)
    {
        // Si el obstáculo está en el rango de puntuación
        // Verificamos si la X está exactamente en el umbral para sumar solo 1 vez
        if(obstacles[i].GetPosition().x >= 100 - 2 && obstacles[i].GetPosition().x < 100 + 2)
        {
            score++;
        }

        // Lógica de reemplazo
        if(obstacles[i].GetPosition().x <= -100)
        {
            int ultX = obstacles[obstacles.size() - 1].GetPosition().x;
            obstacles.push_back(Obstacle{obstacleTexture, ultX + 350, 100 + rand() % 250});
            obstacles.erase(obstacles.begin() + i);
            i--; // Ajustamos el índice tras borrar
        }
    }

    for(std::size_t i = 0; i < obstacles.size(); i++)
    {
        obstacles[i].Update();
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