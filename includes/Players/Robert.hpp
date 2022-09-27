#pragma once

#include "Player.hpp"

namespace DemoRun::Players
{
    class Robert
    {
        public:
        Robert();
        ~Robert();

        void move() override;
        void setBlocker() override;
    }
}