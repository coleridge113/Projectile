#pragma once

#include "raylib.h"

class Bullet
{
    public:
        Bullet(float posX, float posY);
        float posX;
        float posY;

        void draw();
        void update();

    private:
        float width;
        float height;
        Color color;
        float velocity;
};
