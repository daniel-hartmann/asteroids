#pragma once
#include "Base.h"

class AAsteroid: public Base
{
public:
    AAsteroid();
    ~AAsteroid();
    AAsteroid(sf::Vector2f Position, float Rotation, float Radius, float Speed, sf::Color Color);
    sf::CircleShape Shape;
    void Move();
    void Damage();
    float GetRadius();
    float GetSpeed();
    float GetRotation();

    void SetRadius(float Radius);
    void SetSpeed(float Speed);
    bool bDestroyed = false;
    const float MinRadius = 10.f;
    sf::Color GetColor();
    bool IsOutOfWindow(int WindowWidth, int WindowHeight);

private:
    const float MaxRadius = 80.f;
    const float DamageRadius = 2.5f;
    const float MaxSpeed = 3.f;
    const float DamageSpeedRatio = 1.5f;
    float Radius;
    float Speed;
};
