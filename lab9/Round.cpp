#include "Round.hpp"
#include <iostream>

namespace ib
{
    void Round::Radius(int r)
    {
        if (r < 0)
        {
            std::cout << "Error: negative radius" << std::endl;
            return;
        }
        m_radius = r;
    }

    int Round::Radius()
    {
        return m_radius;
    }

    double Round::Length()
    {
        return 2 * PI * m_radius;
    }
}