#pragma once
#include "Base.h"

class AProjectile: public Base
{
public:
    AProjectile(sf::Vector2f InitialPosition, float Rotation);
    ~AProjectile();
    sf::RectangleShape Shape;
    void Move();
    bool bDestroyed = false;
    bool IsOutOfWindow(int WindowWidth, int WindowHeight);

private:

    const float Width = 1.f;
    const float Height = 2.f;
    const float Speed = 10.f;
};
