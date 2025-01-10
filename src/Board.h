#pragma once

class Board
{
  private:
    static const int cell_count = 32;
    static const int cell_size = 16;

    int cells[cell_count][cell_count] = {};

  public:
    Board();
    ~Board() {};

    void draw();
    void update();
};
