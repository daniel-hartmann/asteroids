#pragma once
#include "Base.h"
#include "Projectile.h"

using namespace std;

class ACharacter: public Base
{
public:
    ACharacter();

    sf::ConvexShape Shape;
    void Rotate(float Angle);
    void Accelerate();
    void Move();
    void Brake();
    void Update(sf::Time ElapsedTime);
    vector<AProjectile*> Projectiles;

private:
    const float Acceleration = 1.1f;
    const float BrakeAcceleration = 0.9f;
    const float MinSpeed = 0.2f;
    const float MaxSpeed = 5.f;
    const float RotationSpeed = 2.f;
    float CurrentSpeed = 0.f;
    sf::Time ElapsedTime;
};