#pragma once

#include <list>

namespace DemoRun
{

    class Pawn
    {
    public:
        Pawn(int tileID);
        ~Pawn();

        int getID() const;
        void setId(int id);
        void move(int tileID);
        int getTileID() const;
        bool isBlocking() const;
        void setBlocking();

    private:
        int _id;
        int _tileID;
        bool _blocking;
    };
}