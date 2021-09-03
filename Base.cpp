#include "Base.h"
#include <random>

void Base::Log(string Message)
{
    std::cout << "[DEBUG] " << Message << std::endl;
}

float Base::RandomFloat(float Min, float Max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(Min, Max);
    return dist(mt);
}

int Base::RandomInt(int Min, int Max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(Min, Max);
    return dist(mt);
}
