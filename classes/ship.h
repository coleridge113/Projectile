#pragma once

#include "bullet.h"
#include "raylib.h"
#include <vector>

class Ship
{
    public:
        Ship(float posX, float posY);
        void draw() const;
        void update();
        void shoot();
        void moveUp();
        void moveDown();

        std::vector<Bullet> bullets;

    private:
        float posX;
        float posY;
        int width;
        int height;
        Color color;
};
