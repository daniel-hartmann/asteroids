#pragma once
#include "Base.h"

class AAsteroid: public Base
{
public:
    AAsteroid();
    float Radius;
    sf::CircleShape Shape;
    void Move();
    void Damage();
    bool bDestroyed = false;

private:
    const float MaxRadius = 80.f;
    const float MinRadius = 6.f;
    const float DamageRadius = 2.5f;
    const float MaxSpeed = 4.f;
    float Speed;
};
