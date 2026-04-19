#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>

class UISound : public sf::Drawable{
    private:
        sf::SoundBuffer PointB;
        sf::SoundBuffer WingB;
        sf::SoundBuffer HitB;
        sf::Sound Point;
        sf::Sound Wing;
        sf::Sound Hit;
        sf::Music Music;
        sf::Font Font;
        sf::Text MaxScoreT;
        sf::Text ScoreT;
        int MaxScore;
        int Score;
        bool Initiated;
        bool GameOver;
        sf::Texture GameOverT;
        sf::Sprite GameOverS;
        sf::Texture InitT;
        sf::Sprite InitS;
    public:
        UISound();
        void SetScore(int);
        void initiate(bool);
        void gameOver();
        void Wing();
        virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};