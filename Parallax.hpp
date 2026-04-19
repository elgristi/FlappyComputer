#include <iostream>
#include <SFML/Graphics.hpp>
#include "Obstacle.hpp"
#include <time.h>

class Parallax : public sf::Drawable{
    private:
        int last;
        int score;
        bool initiated;
        sf::Texture obstacleTexture;
        sf::Texture baseTexture;
        std::vector<sf::Sprite> bases;
        std::vector<Obstacle> obstacles;
    public:
        Parallax();
        void Update();
        bool Collision(sf::IntRect);
        void Initiated();
        int Score();
        virtual void draw(sf::RenderTarget& , sf::RenderStates) const;
};