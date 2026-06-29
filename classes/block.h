#pragma once

#include "raylib.h"

class Block
{
    public:
        Block(float posx, float posY);
        void draw() const;
        void move(float velocity);

        float posX;
        float posY;
        int width;
        int height;
        Color color;
};
