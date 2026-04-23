#include "Obstacle.hpp"

Obstacle::Obstacle(sf::Texture & texture, int x, int y,int NewIndex)
{
    index = NewIndex;

    upSprite.setTexture(texture);
    downSprite.setTexture(texture);

    upSprite.setOrigin(texture.getSize().x,0);
    upSprite.setRotation(180);

    upSprite.setPosition(x,y);
    downSprite.setPosition(x,y+150);

    upSprite.scale(1.5f,1.5f);
    downSprite.scale(1.5f,1.5f);
    
}

void Obstacle::Update(float vel){
    upSprite.move(-2.5 * vel,0);
    downSprite.move(-2.5 * vel,0);

}

bool Obstacle::Collision(sf::IntRect rect)
{
    sf::IntRect rectUp((upSprite.getPosition().x)+4,upSprite.getPosition().y-480,70,480);
    sf::IntRect rectDown((downSprite.getPosition().x)+4,downSprite.getPosition().y,70,480);

    if(rectUp.intersects(rect)||rectDown.intersects(rect))
    {
        return true;
    }
    return false;
}

sf::Vector2f Obstacle::GetPosition(){
    return downSprite.getPosition();
}

void Obstacle::draw(sf::RenderTarget &rt, sf::RenderStates rs) const
{
    rt.draw(upSprite,rs);
    rt.draw(downSprite,rs);
}

int Obstacle::getIndex()
{
    return index;
}
