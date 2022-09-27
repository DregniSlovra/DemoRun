#include <iostream>
#include <random>
#include <ctime>

#include "Board.hpp"

#include "tools.hpp"

namespace DemoRun
{
    Board::Board()
    {
    }

    Board::~Board()
    {
    }

    static void createTriangle(std::vector<Tile *> & tiles, int idOffset)
    {
        for (int i = 0; i < 9; i++)
        {
            Tile * tile = new Tile(i+idOffset);
            tiles.push_back(tile);
        }
        for (int i = 0; i < 9; i++)
        {
            if (i != 2 && i != 5 && i != 8)
                tiles[i+idOffset]->addNeighbor(*tiles[i+idOffset+1]);
            if (i == 1 || i == 4)
                tiles[i+idOffset]->addNeighbor(*tiles[i+idOffset+2]);
            if (i == 0)
                tiles[i+idOffset]->addNeighbor(*tiles[idOffset+7]);
        }
    }

    static void createCenter(std::vector<Tile *> & tiles)
    {
        Tile * center = new Tile(0);
        center->setType(TileType::Center);
        tiles.push_back(center);
        for (int i = 1; i <= 6; i++)
        {
            Tile * tile = new Tile(i);
            tile->setType(TileType::Classic);
            tile->addNeighbor(*center);
            tile->addNeighbor(*tiles[i-1]);
            tiles.push_back(tile);
        }
        tiles[6]->addNeighbor(*tiles[1]);
        DEBUG("Crown node created.");
        Tile * fast = new Tile(7);
        fast->setType(TileType::Fast);
        fast->addNeighbor(*tiles[6]);
        tiles.push_back(fast);
        DEBUG("Fast node 1 created.");
        fast = new Tile(8);
        fast->setType(TileType::Fast);
        fast->addNeighbor(*tiles[2]);
        tiles.push_back(fast);
        DEBUG("Fast node 2 created.");
        fast = new Tile(9);
        fast->setType(TileType::Fast);
        fast->addNeighbor(*tiles[4]);
        tiles.push_back(fast);
        DEBUG("Fast node 3 created.");
    }

    static void linkTriangles(std::vector<Tile *> & _tiles)
    {
        _tiles[1]->addNeighbor(*_tiles[19]);
        _tiles[3]->addNeighbor(*_tiles[10]);
        _tiles[5]->addNeighbor(*_tiles[28]);
        _tiles[7]->addNeighbor(*_tiles[27]);
        _tiles[7]->addNeighbor(*_tiles[30]);
        _tiles[8]->addNeighbor(*_tiles[18]);
        _tiles[8]->addNeighbor(*_tiles[21]);
        _tiles[9]->addNeighbor(*_tiles[12]);
        _tiles[9]->addNeighbor(*_tiles[36]);
    }

    static void TypeTriangle(std::vector<Tile *> & tiles)
    {
        for (Tile * tile : tiles)
        {
            if (tile->getNeighbors().size() == 1)
            {
                tile->setType(TileType::Target);
            }
        }
        for (Tile * tile : tiles)
        {
            auto neighbors = tile->getNeighbors();
            for (int tileID : neighbors)
            {
                if (tiles[tileID]->getType() == TileType::Target)
                {
                    tile->setType(TileType::Safe);
                }
            }
        }
    }

    static void SupriseTiles(std::vector<Tile *> & tiles)
    {
        int r = 0;
        for (int i = 0; i < 2; ++i)
        {
            r = 1 + std::rand() % 6;
            if (tiles[r]->getType() == TileType::Surprise)
            {
                --i;
                continue;
            }
            tiles[r]->setType(TileType::Surprise);
        }
        for (int i = 0; i < 10; ++i)
        {
            r = 10 + std::rand() % 26;
            if (tiles[r]->getType() == TileType::Surprise ||
                tiles[r]->getType() == TileType::Target ||
                tiles[r]->getType() == TileType::Safe)
            {
                --i;
                continue;
            }
            tiles[r]->setType(TileType::Surprise);
        }
    }

    void Board::init()
    {
        DEBUG("Initialization...");
        createCenter(_tiles);
        DEBUG("Center done.");
        for (int i = 1; i < 4; i++)
        {
            DEBUG("Creating triangle " << i << "...");
            createTriangle(_tiles, 1+ (i*9));
            DEBUG("Triangle" << i << " done.");
        }
        linkTriangles(_tiles);
        DEBUG("Triangles linked.");
        TypeTriangle(_tiles);
        std::srand(std::time(nullptr));
        SupriseTiles(_tiles);
        DEBUG("Triangles typed.");
    }

    void Board::addPawn()
    {
        Pawn * pawn = new Pawn(_pawns.size());
       _pawns.push_back(pawn);
    }

    void Board::dump()
    {
        int classic=0;
        int surprises=0;
        for (std::vector<Tile *>::iterator it = _tiles.begin();
                it != _tiles.end(); ++it)
        {
            std::cout << "Tile " << (*it)->getID() << " : ";
            if ((*it)->getType() == TileType::Classic)
                classic ++;
            if ((*it)->getType() == TileType::Surprise)
                surprises ++;
            for (std::vector<int>::iterator it2 = (*it)->getNeighbors().begin();
                    it2 != (*it)->getNeighbors().end(); ++it2)
            {
                std::cout << (*it2) << " ";
            }
            std::cout << ToString((*it)->getType()) << std::endl;
        }
        COUT("classic tiles : " << classic);
        COUT("surprise tiles : " << surprises);
    }
}