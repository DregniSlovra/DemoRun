#include "Tile.hpp"

#include <algorithm>

namespace DemoRun
{
    Tile::Tile(int id)
    {
        _id = id;
        _type = TileType::Classic;
    }

    Tile::~Tile()
    {
    }

    int Tile::getID() const
    {
        return _id;
    }

    TileType Tile::getType() const
    {
        return _type;
    }

    void Tile::setType(TileType type)
    {
        _type = type;
    }

    const std::list<int> & Tile::getPawns() const
    {
        return _pawns;
    }

    void Tile::addPawn(int pawnID)
    {
        _pawns.push_back(pawnID);
    }

    void Tile::removePawn(int pawnID)
    {
        _pawns.remove(pawnID);
    }

    bool Tile::isCrack() const
    {
        return _cracked;
    }

    void Tile::setCrack()
    {
        _cracked = !_cracked;
    }

    std::vector<int> & Tile::getNeighbors()
    {
        return _neighbors;
    }

    void Tile::addNeighbor(Tile & neighbor)
    {
        if (std::find(_neighbors.begin(), _neighbors.end(), neighbor.getID()) == _neighbors.end())
        {
            _neighbors.push_back(neighbor.getID());
            neighbor.addNeighbor(*this);
        }
    }
}