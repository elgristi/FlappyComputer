#include <iostream>
#include <SFML/Graphics.hpp>

class Computer : public sf::Drawable {
    private:
        bool initiated;
        bool life;
        int state;
        int timerState;
        std::vector<sf::Texture> frameAnim;
        sf::Sprite sprite;
        float move;

    public:
        Computer(int,int);
        void Update();
        void Jump();
        void Death();
        bool GetLive();
        sf::Vector2f GetPosition();
        void Initiated();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};