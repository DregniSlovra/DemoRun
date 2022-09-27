#include "Pawn.hpp"

namespace DemoRun
{
    Pawn::Pawn(int tileID)
    {
        this->_id = 0;
        this->_tileID = tileID;
    }

    Pawn::~Pawn()
    {
    }

    int Pawn::getID() const
    {
        return this->_id;
    }

    void Pawn::setId(int id)
    {
        this->_id = id;
    }

    void Pawn::move(int tileID)
    {
        this->_tileID = tileID;
    }

    int Pawn::getTileID() const
    {
        return this->_tileID;
    }

    bool Pawn::isBlocking() const
    {
        return this->_blocking;
    }

    void Pawn::setBlocking()
    {
        this->_blocking = !this->_blocking;
    }
}