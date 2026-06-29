#include "game.h"
#include "ship.h"
#include "constants.h"

Game::Game()
    : ship(windowWidth / 6, windowHeight / 2), direction(1) 
{
    initializeBlocks();
}

void Game::draw()
{
    handleInput();
    ship.update();
    ship.draw();
    drawBlocks();
    handleCollision();
}

void Game::handleInput()
{
    if (IsKeyPressed(KEY_SPACE))    ship.shoot();
    if (IsKeyDown(KEY_K))           ship.moveUp();
    if (IsKeyDown(KEY_J))           ship.moveDown();
}

void Game::drawBlocks()
{
    bool changeDirection = false;
    for (const auto& block : blocks)
    {
        if (direction == 1 && (block.posY + block.height) >= windowHeight)
        {
            changeDirection = true;
            break;
        }
        else if (direction == -1 && block.posY <= 0)
        {
            changeDirection = true;
            break;
        }
    }

    if (changeDirection)
    {
        direction *= -1;
    }

    for (auto& block : blocks)
    {
        block.move(1 * direction);
        block.draw();
    }
}

void Game::initializeBlocks()
{
    constexpr int gapX = 40;
    constexpr int gapY = 20;
    constexpr int height = 20;
    constexpr int width = 10;
    constexpr int numRows = (windowHeight / 1.01) / (gapY + height);
    constexpr int numCols = windowWidth * (1 - 1/1.5) / (width + gapX);    

    for (int i = 0; i < numRows - 1; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            float spawnY = 10 + (gapY + height) * i;
            float spawnX = (windowWidth / 1.5) + (width + gapX) * j;
            Block block { spawnX, spawnY };
            blocks.push_back(block);

        }
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
