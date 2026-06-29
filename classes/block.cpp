#include "block.h"
#include "raylib.h"

Block::Block(float posX, float posY)
     :posX(posX), posY(posY), width(10), height(20), color(WHITE) 
      {}

void Block::draw() const
{
    DrawRectangle(posX, posY, width, height, color);
}

void Block::move(float velocity)
{
    posY += velocity;
}
