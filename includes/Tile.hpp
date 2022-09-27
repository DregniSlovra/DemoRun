#pragma once

#include <list>
#include <vector>

namespace DemoRun
{
    enum class TileType
    {
        Center,
        Target,
        Safe,
        Fast,
        Surprise,
        Classic
    };

    inline const char* ToString(TileType value)
    {
        switch (value)
        {
            case TileType::Center: return "Center";
            case TileType::Target: return "Target";
            case TileType::Safe: return "Safe";
            case TileType::Fast: return "Fast";
            case TileType::Surprise: return "Surprise";
            case TileType::Classic: return "Classic";
            default: return "Invalid type";
        }
    }

    class Tile
    {
    public:
        Tile(int id);
        ~Tile();

        int getID() const;
        TileType getType() const;
        void setType(TileType type);
        const std::list<int> & getPawns() const;
        void addPawn(int pawnID);
        void removePawn(int pawnID);
        bool isCrack() const;
        void setCrack();
        std::vector<int> & getNeighbors();
        void addNeighbor(Tile & neighbor);

    private:
        int _id;
        TileType _type;
        bool _cracked;
        std::list<int> _pawns;
        std::vector<int> _neighbors;
    };
}