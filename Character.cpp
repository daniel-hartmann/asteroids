#include "Character.h"

ACharacter::ACharacter()
{
    Shape.setPosition(500.0f, 500.0f);
    Shape.setFillColor(sf::Color(190, 190, 190));
    
    Shape.setPointCount(4);
    Shape.setPoint(0, sf::Vector2f(-5.f, -15.f));
    Shape.setPoint(1, sf::Vector2f(40.f, 0.f));
    Shape.setPoint(2, sf::Vector2f(-5.f, 15.f));
    Shape.setPoint(3, sf::Vector2f(0.f, 0.f));    
    Shape.rotate(-90);
}

void ACharacter::Update(sf::Time ElapsedTime)
{
    this->ElapsedTime = ElapsedTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Accelerate();
    }
    if (CurrentSpeed > 0.f)
    {
        Move();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Rotate(RotationSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Brake();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Rotate(-RotationSpeed);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
        sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        Projectiles.push_back(new AProjectile(Shape.getPosition(), Shape.getRotation()));
    }
    
}

void ACharacter::Accelerate()
{
    CurrentSpeed = CurrentSpeed + (Acceleration*ElapsedTime.asSeconds());
    
    if (CurrentSpeed > MaxSpeed)
    {
        CurrentSpeed = MaxSpeed;
    }
}

void ACharacter::Move()
{
    float RotationRad = Shape.getRotation() * M_PI /180;

    float VelocityX = cos(RotationRad) * CurrentSpeed;
    float VelocityY = sin(RotationRad) * CurrentSpeed;

    Shape.move(VelocityX, VelocityY);
}


void ACharacter::Brake()
{
    CurrentSpeed = CurrentSpeed - (Acceleration*ElapsedTime.asSeconds());
    
    if (CurrentSpeed < MinSpeed)
    {
        CurrentSpeed = MinSpeed;
    }
}

void ACharacter::Rotate(float Angle)
{
    Shape.rotate(Angle);
}