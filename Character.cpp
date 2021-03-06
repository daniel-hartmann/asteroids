#include "Character.h"

ACharacter::ACharacter()
{
    Shape.setPosition(500.0f, 500.0f);
    Shape.setFillColor(sf::Color(190, 190, 190));
    
    Shape.setPointCount(4);
    float ShapeDetailPoint = 5.f;
    Shape.setPoint(0, sf::Vector2f(-ShapeDetailPoint, -Width/2.f));
    Shape.setPoint(1, sf::Vector2f(Height-ShapeDetailPoint, 0.f));
    Shape.setPoint(2, sf::Vector2f(-ShapeDetailPoint, Width/2.f));
    Shape.setPoint(3, sf::Vector2f(0.f, 0.f));    
    Shape.rotate(-90);
}

bool ACharacter::IsDead()
{
    if (Damage >= MaxDamage)
    {
        return true;
    }
    return false;
}

void ACharacter::CheckCollision(AAsteroid *Asteroid)
{
    if (this->Shape.getGlobalBounds().intersects(
            Asteroid->Shape.getGlobalBounds()))
    {
        bColliding = true;

        this->Damage += Asteroid->GetRadius();

//        float RotationRad = Asteroid->GetRotation() * M_PI /180;
//
//        VelocityX += cos(RotationRad) * (Asteroid->GetSpeed()/30.f);
//        VelocityY += sin(RotationRad) * (Asteroid->GetSpeed()/30.f);
//        
//        if (VelocityX > MaxSpeed)
//        {
//            VelocityX = MaxSpeed;
//        }
//        if (VelocityY > MaxSpeed)
//        {
//            VelocityY = MaxSpeed;
//        }
        
//        Shape.rotate(2);
    }
    else
    {
        bColliding = false;
    }
}

int ACharacter::GetDamage()
{
    return Damage;
}

void ACharacter::Update(sf::Time ElapsedTime)
{
    this->ElapsedTime = ElapsedTime;
    FireTime += ElapsedTime.asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Accelerate();
    }
    if (VelocityX != 0.f || VelocityY != 0.f)
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
        if (FireTime >= FireRate)
        {
            Projectiles.push_back(new AProjectile(Shape.getPosition(), Shape.getRotation()));
            FireTime = 0.f;
        }
    }
    
}

void ACharacter::Accelerate()
{
    float RotationRad = Shape.getRotation() * M_PI /180;

    VelocityX += cos(RotationRad) * Acceleration * ElapsedTime.asSeconds();
    VelocityY += sin(RotationRad) * Acceleration * ElapsedTime.asSeconds();

    if (VelocityX > MaxSpeed)
    {
        VelocityX = MaxSpeed;
    }
    if (VelocityY > MaxSpeed)
    {
        VelocityY = MaxSpeed;
    }
}

void ACharacter::Move()
{
    if (!bColliding)
    {
        Shape.move(VelocityX, VelocityY);
    }
}


void ACharacter::Brake()
{
    float RotationRad = Shape.getRotation() * M_PI /180;

    VelocityX += cos(RotationRad) * -BrakeAcceleration * ElapsedTime.asSeconds();
    VelocityY += sin(RotationRad) * -BrakeAcceleration * ElapsedTime.asSeconds();
}

void ACharacter::Rotate(float Angle)
{
    Shape.rotate(Angle * ElapsedTime.asSeconds());
}
