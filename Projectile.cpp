#include "Projectile.h"

AProjectile::AProjectile(sf::Vector2f InitialPosition, float Rotation)
{
    Shape.setSize(sf::Vector2f(1.f, 2.f));
    Shape.setPosition(InitialPosition);
    Shape.setRotation(Rotation);
    Shape.setFillColor(sf::Color(255, 255, 255));
}

AProjectile::~AProjectile()
{
//    cout << "Projectile is dead" << endl;
}

void AProjectile::Move()
{
    float RotationRad = Shape.getRotation() * M_PI /180;

    float VelocityX = cos(RotationRad) * Speed;
    float VelocityY = sin(RotationRad) * Speed;

    Shape.move(VelocityX, VelocityY);
}

bool AProjectile::IsOutOfWindow(int WindowWidth, int WindowHeight)
{
    return Shape.getPosition().x > WindowWidth ||
        Shape.getPosition().x < 0.f ||
        Shape.getPosition().y > WindowHeight ||
        Shape.getPosition().y < 0.f;
}
