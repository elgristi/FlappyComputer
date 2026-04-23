#include <iostream>
#include <SFML/Graphics.hpp>

class Obstacle : public sf::Drawable{
    private:
        sf::Sprite upSprite;
        sf::Sprite downSprite;
        int index;
    public:
        Obstacle(sf::Texture&,int,int,int);
        void Update(float);
        bool Collision(sf::IntRect);
        sf::Vector2f GetPosition();
        virtual void draw(sf::RenderTarget& , sf::RenderStates) const;
        int getIndex();
};