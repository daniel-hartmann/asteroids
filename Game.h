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
    sf::RenderWindow Window;
    void Draw(sf::Clock& AsteroidClock);
    void HandleEvent(sf::Event SystemEvent);
    void Update();
};