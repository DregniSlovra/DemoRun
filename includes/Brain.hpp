#pragma once

namespace DemoRun
{
    enum class BrainType
    {
        Random,
        Straight,
        Invalid,
    };

    class Brain
    {
    public:
        Brain(BrainType brainType);
        ~Brain();

    private:

    }
}