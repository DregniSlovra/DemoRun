#pragma once

#include "Player.hpp"

namespace DemoRun::Players
{
    class Claire
    {
        public:
        Claire();
        ~Claire();

        void move() override;
        void setBlocker() override;
    }
}