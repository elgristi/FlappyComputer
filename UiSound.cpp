#include "UiSound.hpp"

UISound::UISound()
{
    Initiated = false;
    GameOver = false;

    if(!Font.loadFromFile("resources/font/font.ttf"))
    {
        std::cout<<"Error al cargar la fuente font.tff \n";
    }

    if(!GameOverT.loadFromFile("resources/sprites/gameover.png"))
    {
        std::cout<<"Error al cargar la textura gameover.png \n";
    }

    if(!InitT.loadFromFile("resources/sprites/message.png"))
    {
        std::cout<<"Error al cargar la textura message.png \n";
    }

    if(!PointB.loadFromFile("resources/sounds/point.ogg"))
    {
        std::cout<<"Error al cargar el sonido point.ogg \n";
    }

    if(!WingB.loadFromFile("resources/sounds/wing.ogg"))
    {
        std::cout<<"Error al cargar el sonido wing.ogg \n";
    }

    if(!HitB.loadFromFile("resources/sounds/hit.ogg"))
    {
        std::cout<<"Error al cargar el sonido hit.ogg \n";
    }

    if(!Music.openFromFile("resources/sounds/music.ogg"))
    {
        std::cout<<"Error al cargar el sonido music.ogg \n";
    }

    Music.setVolume(30);
    Music.setLoop(true);
    Music.play();

    Point.setBuffer(PointB);
    Wing.setBuffer(WingB);
    Hit.setBuffer(HitB);

    Score = 0;
    ScoreT.setFont(Font);
    ScoreT.setCharacterSize(40);
    ScoreT.setPosition(210,50);
    ScoreT.setString(std::to_string(Score));
    ScoreT.setOrigin(ScoreT.getGlobalBounds().width/2,ScoreT.getGlobalBounds().height/2);

    std::ifstream in("score");
    in>>MaxScore;
    MaxScoreT.setFont(Font);
    MaxScoreT.setCharacterSize(20);
    MaxScoreT.setString(std::to_string(MaxScore));
    MaxScoreT.setOrigin(MaxScoreT.getGlobalBounds().width/2,MaxScoreT.getGlobalBounds().height/2);
    MaxScoreT.setPosition(210,100);

    GameOverS.setTexture(GameOverT);
    GameOverS.setOrigin(GameOverT.getSize().x/2,GameOverT.getSize().y);
    GameOverS.setScale(2,2);
    GameOverS.setPosition(210,350);

    InitS.setTexture(InitT);
    InitS.setOrigin(InitT.getSize().x/2,InitT.getSize().y);
    InitS.setScale(1.5f,1.5f);
    InitS.setPosition(210,280);
};

void UISound::SetScore(int val){
    if(Score!=val) Point.play();

    Score=val;
    ScoreT.setString(std::to_string(Score));
}

void UISound::initiate(bool state){
    Initiated = state;
    GameOver = false;

    std::ifstream in("score");
    in>>MaxScore;
    MaxScoreT.setString(std::to_string(MaxScore));
    MaxScoreT.setOrigin(MaxScoreT.getGlobalBounds().width/2,MaxScoreT.getGlobalBounds().height/2);
    

    Score = 0;
    ScoreT.setString(std::to_string(Score));
    GameOverS.setOrigin(GameOverT.getSize().x/2,GameOverT.getSize().y);
}

void UISound::wing(){
    Wing.play();
}

void UISound::gameOver(){
    if(!GameOver) Hit.play();
    
    if(Score > MaxScore)
    {
        MaxScore = Score;
        std::ofstream out("score");
        out<<Score;
    }

    GameOver = true;
}

void UISound::draw(sf::RenderTarget &rt, sf::RenderStates rs) const{
    if(!Initiated) rt.draw(InitS,rs);
    else{
        rt.draw(ScoreT,rs);
        rt.draw(MaxScoreT,rs);
        if(GameOver)rt.draw(GameOverS,rs);
    }
}


