#include "APlayer.hpp"

namespace DemoRun::Players
{
    APlayer::setBrain(BrainType brainType)
    {
        this->brain.init(brainType);
    }
}