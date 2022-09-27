#pragma once

#include "Brain.hpp"

namespace DemoRun
{
    enum class Leader
    {
        Claire,
        Damien
        Robert,
        Sandra,
    };

    class APlayer
    {
    public:
        void setBrain(BrainType brainType);
        virtual void move() = 0;
        virtual void setBlocker() = 0;

    protected:
        std::list<int> _pawns;
        Brain _brain;
    }
}