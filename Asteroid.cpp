#include "Base.h"
#include "Asteroid.h"

AAsteroid::AAsteroid()
{
    // Set random radius
    Radius = RandomFloat(MaxRadius, MinRadius);
    Shape.setRadius(Radius);
    
    // Set random position and rotation
    float PositionX = RandomFloat(0.f, 800.f);
    float PositionY = -MaxRadius;
    Shape.setPosition(PositionX, PositionY);
    Shape.setRotation(RandomFloat(10.f, 260.f));

    Speed = RandomFloat(0.1f, MaxSpeed);
    cout << "Asteroid speed " << Speed << endl;

    //Set random brown colors
    int Gray = RandomInt(50, 120);
    Shape.setFillColor(sf::Color(Gray, Gray-20, Gray-20));
}

void AAsteroid::Damage()
{
    float NewRadius = Shape.getRadius() - DamageRadius;
    if (NewRadius < 4.f)
    {
        NewRadius = 0;
        bDestroyed = true;
    }
    Shape.setRadius(NewRadius);
}

void AAsteroid::Move()
{
    float RotationRad = Shape.getRotation() * M_PI /180;

    float VelocityX = cos(RotationRad) * Speed;
    float VelocityY = sin(RotationRad) * Speed;

    Shape.move(VelocityX, VelocityY);
}
