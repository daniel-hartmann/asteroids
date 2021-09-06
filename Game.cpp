
#include "Game.h"

AGame::AGame()
{
    Window.create(sf::VideoMode(WindowWidth, WindowHeight), "Asteroids");
    //Window.setFramerateLimit(60); // dont use with vsync
    Window.setVerticalSyncEnabled(true);
    Ship = new ACharacter();

    if (!MainFont.loadFromFile("res/Montserrat-Bold.ttf"))
    {
        perror("Couldn't load the font file.");
    }
    else
    {
        GameScoreText.setFont(MainFont);
        DamageScoreText.setFont(MainFont);
    }
    GameScoreText.setCharacterSize(20);
    GameScoreText.setFillColor(sf::Color::White);
    GameScoreText.setStyle(sf::Text::Bold);
 
    DamageScoreText.setCharacterSize(20);
    DamageScoreText.setFillColor(sf::Color::White);
    DamageScoreText.setStyle(sf::Text::Bold);
}

void AGame::Start()
{
    sf::Clock CharacterClock;
    sf::Clock AsteroidClock;
    while (Window.isOpen())
    {
        Ship->Update(CharacterClock.restart());
        Update();

        sf::Event SystemEvent;
        while (Window.pollEvent(SystemEvent))
        {
            HandleEvent(SystemEvent);
        }

        // Clear before drawing
        Window.clear();
        Draw(AsteroidClock);
        DrawText();
        Window.display();
    }
}

void AGame::Update()
{
    // Check collision
    for (long unsigned int i=0; i<Asteroids.size(); i++)
    {
        Asteroids[i]->Move();

        if (Ship->Shape.getGlobalBounds().intersects(
            Asteroids[i]->Shape.getGlobalBounds()))
        {
            Ship->Collision(Asteroids[i]->GetRadius(), Asteroids[i]->GetSpeed(), Asteroids[i]->GetRotation());
        }
        
        if (Asteroids[i]->bDestroyed ||
            Asteroids[i]->IsOutOfWindow(WindowWidth, WindowHeight))
        {
            delete Asteroids[i];
            Asteroids.erase(next(Asteroids.begin(), i));
        }
    }
    
    for (long unsigned int PIndex=0; PIndex < Ship->Projectiles.size(); PIndex++)
    {
        Ship->Projectiles[PIndex]->Move();

        for (long unsigned int AIndex=0; AIndex < Asteroids.size(); AIndex++)
        {

            if (Ship->Projectiles[PIndex]->Shape.getGlobalBounds().intersects(
                Asteroids[AIndex]->Shape.getGlobalBounds()))
            {
                float OldRadius = Asteroids[AIndex]->GetRadius();
                Asteroids[AIndex]->Damage();
                Ship->Projectiles[PIndex]->bDestroyed = true;
                
                GameScore += (OldRadius - Asteroids[AIndex]->GetRadius());
                
                if (!Asteroids[AIndex]->bDestroyed && (Asteroids[AIndex]->GetRadius()) >= Asteroids[AIndex]->MinRadius)
                {
                    Asteroids[AIndex]->Shape.rotate(30);
                    
                    Asteroids.push_back(new AAsteroid(
                        Asteroids[AIndex]->Shape.getPosition(),
                        Asteroids[AIndex]->Shape.getRotation()-30,
                        Asteroids[AIndex]->GetRadius(),
                        Asteroids[AIndex]->GetSpeed(),
                        Asteroids[AIndex]->GetColor()
                        ));
                }
                break;
            }
        }
        
        if (Ship->Projectiles[PIndex]->bDestroyed ||
            Ship->Projectiles[PIndex]->IsOutOfWindow(WindowWidth, WindowHeight))
        {
            delete Ship->Projectiles[PIndex];
            Ship->Projectiles.erase(next(Ship->Projectiles.begin(), PIndex));
        }
    }
    
    // Check window bounds
    sf::Vector2f ShipPosition = Ship->Shape.getPosition();
    sf::Vector2f NewShipPosition(ShipPosition.x, ShipPosition.y);
    float bPositionChanged = false;
    
    if (ShipPosition.x > (WindowWidth + Ship->Height))
    {
        ShipPosition.x = -Ship->Height;
        bPositionChanged = true;
    }
    else if (ShipPosition.x < -Ship->Height)
    {
        ShipPosition.x = static_cast<float>(WindowWidth) + Ship->Height;
        bPositionChanged = true;
    }
    if (ShipPosition.y > (WindowHeight + Ship->Height))
    {
        ShipPosition.y = -Ship->Height;
        bPositionChanged = true;
    }
    else if (ShipPosition.y < -Ship->Height)
    {
        ShipPosition.y = static_cast<float>(WindowHeight) + Ship->Height;
        bPositionChanged = true;
    }
    
    if (bPositionChanged)
    {
        Ship->Shape.setPosition(ShipPosition);
    }
}

void AGame::Draw(sf::Clock& AsteroidClock)
{
    Window.draw(Ship->Shape);

    if ((Asteroids.size() == 0) || AsteroidClock.getElapsedTime().asSeconds() > RandomInt(AsteroidFreqMin, AsteroidFreqMax))
    {
        Asteroids.push_back(new AAsteroid());
        AsteroidClock.restart();
    }

    for (long unsigned int i=0; i < Ship->Projectiles.size(); i++)
    {
        Window.draw(Ship->Projectiles[i]->Shape);
    }

    for (long unsigned int i=0; i < Asteroids.size(); i++)
    {
        Window.draw(Asteroids[i]->Shape);
    }
}

void AGame::DrawText()
{
    GameScoreText.setString("Score: " + to_string(GameScore));
    sf::FloatRect GameScoreBounds = GameScoreText.getLocalBounds();
    GameScoreText.setPosition(WindowWidth - GameScoreBounds.width - 20.f, 10.f);
    
    DamageScoreText.setString("Damage: " + to_string(Ship->GetDamage()));
    sf::FloatRect DamageScoreBounds = DamageScoreText.getLocalBounds();
    DamageScoreText.setPosition(WindowWidth - DamageScoreBounds.width - 20.f, GameScoreBounds.height + 15.f);
    
    Window.draw(GameScoreText);
    Window.draw(DamageScoreText);
}

void AGame::HandleEvent(sf::Event SystemEvent)
{
    if ((SystemEvent.type == sf::Event::Closed) ||
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
    {
        Window.close();
    }
}

