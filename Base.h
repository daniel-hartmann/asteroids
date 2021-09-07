// Copyleft Daniel Hartmann 2021
#pragma once
#include <cmath>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Base
{
public:
    Base();

protected:
    void Log(string Message);
    float RandomFloat(float Min, float Max);
    int RandomInt(int Min, int Max);
    sf::Font MainFont;
};