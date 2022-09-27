#pragma once

#include "Player.hpp"

namespace DemoRun::Players
{
    class Sandra
    {
        public:
        Sandra();
        ~Sandra();

        void move() override;
        void setBlocker() override;
    }
}