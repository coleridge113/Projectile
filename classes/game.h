#pragma once

#include "block.h"
#include "ship.h"

class Game
{
    public:
        Game();
        void draw();
        void handleInput();
        void initializeBlocks();

    private:
        Ship ship;
        std::vector<Block> blocks;
        int direction;

        void drawBlocks();
        void handleCollision();
};
