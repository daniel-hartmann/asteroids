#pragma once
#include "Base.h"

class AProjectile: public Base
{
public:
    AProjectile(sf::Vector2f InitialPosition, float Rotation);
    sf::RectangleShape Shape;
    void Move();
    bool bDestroyed = false;

private:

    const float Width = 1.f;
    const float Height = 2.f;
    const float Speed = 10.f;
};
