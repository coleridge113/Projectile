#include "ship.h"
#include "bullet.h"
#include "raylib.h"
#include "constants.h"

Ship::Ship(float posX, float posY)
    : posX(posX), posY(posY), width(30), height(30), color(WHITE) 
      {}

void Ship::draw() const
{
    DrawRectangle(posX, posY, width, height, color);
}

void Ship::shoot()
{
    float spawnX = posX + width;
    float spawnY = posY + height / 2;
    Bullet bullet { spawnX, spawnY };
    bullets.push_back(bullet);
}


void Ship::update()
{
    for (auto it = bullets.begin(); it != bullets.end(); )
    {
        it->draw();
        it->update();

        if (it->posX > windowWidth)
        {
            it = bullets.erase(it);
        }
        else 
        {
            ++it;
        }
    }
}

void Ship::moveUp()
{
    posY -= 10;
    if (posY < 0) posY = 0;
}

void Ship::moveDown()
{
    posY += 10;
    float boundary = windowHeight - height;
    if (posY > boundary) posY = boundary;
}
