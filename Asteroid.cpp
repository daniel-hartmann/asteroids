#include "Base.h"
#include "Asteroid.h"

AAsteroid::AAsteroid()
{
    // Set random radius
    Radius = RandomFloat(MaxRadius, MinRadius);
    Shape.setRadius(Radius);
    
    // Set random position and rotation
    float PositionX = RandomFloat(0.f, 800.f);
    float PositionY = -Radius;
    Shape.setPosition(PositionX, PositionY);
    Shape.setRotation(RandomFloat(10.f, 260.f));

    Speed = RandomFloat(0.1f, MaxSpeed);

    //Set random brown colors
    int Gray = RandomInt(50, 120);
    Shape.setFillColor(sf::Color(Gray, Gray-20, Gray-20));
}

AAsteroid::AAsteroid(sf::Vector2f Position, float Rotation, float Radius, float Speed, sf::Color Color)
{
    SetRadius(Radius);
    SetSpeed(Speed);
    Shape.setPosition(Position);
    Shape.setRotation(Rotation);
    Shape.setFillColor(Color);
}

AAsteroid::~AAsteroid()
{
    //cout << "Asteroid is dead" << endl;
}

void AAsteroid::Damage()
{
    float NewRadius = Shape.getRadius() / 2.f;

    if (NewRadius < MinRadius)
    {
        NewRadius = 0;
        bDestroyed = true;
    }
    SetRadius(NewRadius);
    
    Speed = Speed / DamageSpeedRatio;
}

void AAsteroid::Move()
{
    float RotationRad = Shape.getRotation() * M_PI /180;

    float VelocityX = cos(RotationRad) * Speed;
    float VelocityY = sin(RotationRad) * Speed;

    Shape.move(VelocityX, VelocityY);
}

sf::Color AAsteroid::GetColor()
{
    return Shape.getFillColor();
}

float AAsteroid::GetRadius()
{
    return Radius;
}

void AAsteroid::SetRadius(float Radius)
{
    Shape.setRadius(Radius);
    this->Radius = Radius;
}

float AAsteroid::GetSpeed()
{
    return Speed;
}

void AAsteroid::SetSpeed(float Speed)
{
    if (Speed > MaxSpeed)
    {
        Speed = MaxSpeed;
    }
    this->Speed = Speed;
}

float AAsteroid::GetRotation()
{
    return Shape.getRotation();
}

bool AAsteroid::IsOutOfWindow(int WindowWidth, int WindowHeight)
{
    return (Shape.getPosition().x - Radius) > WindowWidth ||
        (Shape.getPosition().x + Radius) < 0.f ||
        (Shape.getPosition().y - Radius) > WindowHeight ||
        (Shape.getPosition().y + Radius) < 0.f;
}
