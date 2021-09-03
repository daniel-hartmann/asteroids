#include "Projectile.h"

AProjectile::AProjectile(sf::Vector2f InitialPosition, float Rotation)
{
    Shape.setSize(sf::Vector2f(1.f, 2.f));
    
    // Set random position and rotation
//    float PositionX = RandomFloat(0.f, 800.f);
//    float PositionY = -MaxRadius;
    Shape.setPosition(InitialPosition);
    Shape.setRotation(Rotation);

    Shape.setFillColor(sf::Color(255, 255, 255));
    
    // TODO: set time of life
}

void AProjectile::Move()
{
    float RotationRad = Shape.getRotation() * M_PI /180;

    float VelocityX = cos(RotationRad) * Speed;
    float VelocityY = sin(RotationRad) * Speed;

    Shape.move(VelocityX, VelocityY);
}
