#pragma once

#include "Player.hpp"

namespace DemoRun::Players
{
    class Damien
    {
        public:
        Damien();
        ~Damien();

        void move() override;
        void setBlocker() override;
    }
}