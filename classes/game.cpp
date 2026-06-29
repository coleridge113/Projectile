#include "game.h"
#include "ship.h"
#include "constants.h"
#include "utils.h"

Game::Game()
    : ship(windowWidth / 6, windowHeight / 2) 
{
    blocks.push_back(Block { windowWidth / 1.5, windowHeight / 2 });
}

void Game::draw()
{
    handleInput();
    ship.update();
    ship.draw();
    drawBlocks();
    handleCollision();

    if (blocks.size() == 0)
    {
        blocks.push_back(Block { windowWidth / 1.5, windowHeight / 2 });
        blocks.push_back(Block { windowWidth / 1.5, windowHeight / 2 });
    }
}

void Game::handleInput()
{
    if (IsKeyPressed(KEY_SPACE))    ship.shoot();
    if (IsKeyDown(KEY_K))           ship.moveUp();
    if (IsKeyDown(KEY_J))           ship.moveDown();
}

void Game::drawBlocks()
{
    for (auto& block : blocks)
    {
        block.move(generateRandom(-10, 10));
        block.draw();
    }
}

void Game::handleCollision()
{
    for (auto bullet = ship.bullets.begin(); bullet != ship.bullets.end(); )
    {
        bool hit = false;

        for (auto block = blocks.begin(); block != blocks.end(); )
        {
            bool withinY = bullet->posY >= block->posY && bullet->posY <= (block->posY + block->height);
            
            if (bullet->posX >= block->posX && bullet->posX <= (block->posX + block->width) && withinY)
            {
                block = blocks.erase(block);
                
                hit = true;
                break;
            } 
            else
            {
                ++block;
            }
        }

        if (hit)
        {
            bullet = ship.bullets.erase(bullet);
        }
        else
        {
            ++bullet;
        }
    }
}
