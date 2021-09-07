#pragma once
#include "Base.h"
#include "Asteroid.h"
#include "Character.h"

enum State
{
    STATE_MAIN_MENU,
    STATE_PLAYING,
    STATE_STATS,
    STATE_PAUSE,
    STATE_EXIT
};

class AGame: Base
{
public:
    AGame();
    void Start();
    ACharacter* Ship;
    vector<AAsteroid*> Asteroids;
    State CurrentState = STATE_MAIN_MENU;

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
    sf::Text GameScoreText;
    sf::Text DamageScoreText;
    int GameScore = 0.f;
};