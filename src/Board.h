#pragma once
#include "globals.h"

class Board
{
  private:
    int cells[cell_count][cell_count] = {};

  public:
    Board();
    ~Board() {};

    int *operator[](int a)
    {
        return cells[a];
    };

    void draw();
    void update();

    int *get_cells()
    {
        return &cells[0][0];
    };
};
