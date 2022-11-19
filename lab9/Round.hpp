#pragma once

namespace ib
{
    const double PI = acos(-1.0);

    class Round
    {
    private:
        int m_radius;
    public:
        void Radius(int r);
        int Radius();
        double Length();
    };
}
