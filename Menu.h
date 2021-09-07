#pragma once
#include "Base.h"
#include "Game.h"

enum Option
{
    OPT_START,
    OPT_STATS,
    OPT_EXIT
};

class AMenu: Base
{
public:
    AMenu(State& CurrentState);
    void Update(sf::RenderWindow& Window);
    void Draw(sf::RenderWindow& Window);

private:
    State& CurrentState;
    sf::Font MainFont;
    sf::Text StartText;
    sf::Text StatsText;
    sf::Text ExitText;
    Option CurrentOption = OPT_START;
    void SetTextAttributes(sf::Text& TextField);
    void HighlightOption(sf::Text& TextField);
    void HandleInput();

};