#pragma once
#include "Base.h"
#include "Asteroid.h"
#include "Character.h"

class AGame: Base
{
public:
    AGame();
    void Start();
    ACharacter* Ship;
    vector<AAsteroid*> Asteroids;

private:
    const int WindowWidth = 800;
    const int WindowHeight = 600;
    const int AsteroidFreqMin = 1;
    const int AsteroidFreqMax = 4;
    sf::RenderWindow Window;
    void Draw(sf::Clock& AsteroidClock);
    void DrawText();
    void HandleEvent(sf::Event SystemEvent);
    void Update();
    sf::Font MainFont;
    sf::Text GameScoreText;
    sf::Text DamageScoreText;
    int GameScore = 0.f;
};