#include "bullet.h"
#include "raylib.h"

Bullet::Bullet(float posX, float posY)
      : posX(posX), posY(posY), width(10), height(2), 
        color(WHITE), velocity(10)
        {};

void Bullet::draw()
{
    DrawRectangle(posX, posY, width, height, color);
}

void Bullet::update()
{
    posX += velocity;
}
