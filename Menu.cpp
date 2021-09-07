#include "Menu.h"

AMenu::AMenu(State& CurrentState):
    CurrentState(CurrentState)
{
    if (!MainFont.loadFromFile("res/Montserrat-Bold.ttf"))
    {
        perror("Couldn't load the font file.");
        exit(0);
    }
    SetTextAttributes(StartText);
    SetTextAttributes(StatsText);
    SetTextAttributes(ExitText);
    StartText.setString("NEW GAME");
    StatsText.setString("STATS");
    ExitText.setString("EXIT");
}

void AMenu::Update(sf::RenderWindow& Window)
{
    StartText.setFillColor(sf::Color(155, 155, 155));
    StatsText.setFillColor(sf::Color(155, 155, 155));
    ExitText.setFillColor(sf::Color(155, 155, 155));

    sf::Event SystemEvent;

    while (Window.pollEvent(SystemEvent))
    {
        if (SystemEvent.type == sf::Event::KeyPressed)
        {
            switch (SystemEvent.key.code)
            {
                case sf::Keyboard::Up:
                case sf::Keyboard::W:
                    switch(CurrentOption)
                    {
                        case OPT_START:
                            CurrentOption = OPT_EXIT;
                            break;
                        case OPT_STATS:
                            CurrentOption = OPT_START;
                            break;
                        case OPT_EXIT:
                            CurrentOption = OPT_STATS;
                            break;
                    }
                    break;

                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    switch(CurrentOption)
                    {
                        case OPT_START:
                            CurrentOption = OPT_STATS;
                            break;
                        case OPT_STATS:
                            CurrentOption = OPT_EXIT;
                            break;
                        case OPT_EXIT:
                            CurrentOption = OPT_START;
                            break;
                    }
                    break;

                case sf::Keyboard::Enter:
                    switch(CurrentOption)
                    {
                        case OPT_START:
                            CurrentState = STATE_PLAYING;
                            break;
                        case OPT_STATS:
                            CurrentState = STATE_STATS;
                            break;
                        case OPT_EXIT:
                            CurrentState = STATE_EXIT;
                            break;
                    }
                    break;

                default:
                    break;
            }
            
        }
        else if ((SystemEvent.type == sf::Event::Closed) || CurrentState == STATE_EXIT)
        {
            Window.close();
        }
    }
    
    switch(CurrentOption)
    {
        case OPT_START:
            HighlightOption(StartText);
            break;
        case OPT_STATS:
            HighlightOption(StatsText);
            break;
        case OPT_EXIT:
            HighlightOption(ExitText);
            break;
    }
}

void AMenu::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
        sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        cout << "HUMM" << endl;
    }
    
}

void AMenu::HighlightOption(sf::Text& TextField)
{
    TextField.setFillColor(sf::Color(255, 255, 255));
}

void AMenu::SetTextAttributes(sf::Text& TextField)
{
    TextField.setFont(MainFont);
    TextField.setCharacterSize(36);
    TextField.setStyle(sf::Text::Bold);
}

void AMenu::Draw(sf::RenderWindow& Window)
{
    
//    sf::FloatRect DamageScoreBounds = DamageScoreText.getLocalBounds();
//    StartText.setPosition(WindowWidth - DamageScoreBounds.width - 20.f, GameScoreBounds.height + 15.f);

    float CenterX = Window.getSize().x/2.f;
    float CenterY = Window.getSize().y/2.f;
    float PaddingY = 10.f;

    sf::FloatRect StartBounds = StartText.getLocalBounds();
    sf::FloatRect StatsBounds = StatsText.getLocalBounds();
    sf::FloatRect ExitBounds = ExitText.getLocalBounds();    

    StartText.setPosition(CenterX - StartBounds.width/2.f, CenterY - StartBounds.height - PaddingY);
    StatsText.setPosition(CenterX - StatsBounds.width/2.f, CenterY);
    ExitText.setPosition(CenterX - ExitBounds.width/2.f, CenterY + ExitBounds.height + PaddingY);
    
    Window.draw(StartText);
    Window.draw(StatsText);
    Window.draw(ExitText);
}
