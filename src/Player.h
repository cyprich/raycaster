#pragma once
#include "Board.h"
#include "globals.h"
#include <raylib.h>
#include <utility>

class Player
{
  private:
    Board *board = nullptr;

    static const int w = cell_size / 4 * 3;
    static const int h = cell_size / 4 * 3;

    float x = 300;
    float y = 300;
    float angle = PI / 2 * 3;

    float moving_speed = 1.25;   // pixels per frame
    float rotating_speed = 0.05; // degrees pre frame

    bool collisions(float new_x, float new_y);

  public:
    Player() {};
    ~Player() {};

    void rotate(bool clockwise);
    void move(bool forward);
    void draw();

    void update();

    void update_board(Board *pBoard)
    {
        board = pBoard;
    };
};
