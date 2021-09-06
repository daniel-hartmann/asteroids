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
    void Collision(int Damage, float Speed, float Rotation);
    void Update(sf::Time ElapsedTime);
    vector<AProjectile*> Projectiles;
    int GetDamage();
    
    const float Width = 30.f;
    const float Height = 45.f;

private:
    const float Acceleration = 1.1f;
    const float BrakeAcceleration = 0.9f;
    const float MinSpeed = 0.2f;
    const float MaxSpeed = 4.5f;
    const float RotationSpeed = 2.f;
    const float MaxDamage = 1000.f;
    int Damage = 0.f;
    float FireTime = 0.f;
    bool bFireAllowed = true;
    float FireRate = 0.2f; // In seconds
    float VelocityX = 0.f;
    float VelocityY = 0.f;
    sf::Time ElapsedTime;
};