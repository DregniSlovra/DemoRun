#pragma once

#include <list>
#include <vector>
#include "Tile.hpp"
#include "Pawn.hpp"

namespace DemoRun
{
    class Board
    {
    public:
        Board();
        ~Board();

        void init();
        void addPawn();
        void dump();

    private:
        std::vector<Tile *> _tiles;
        std::list<Pawn *> _pawns;
    };
}