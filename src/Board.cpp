#include "Board.h"
#include "globals.h"
#include "raylib.h"
#include <fstream>
#include <iostream>

Board::Board()
{
    const char *filename = "map.txt";
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Failed to open file " << filename << " to load map..." << std::endl;
        exit(1);
    }

    int i = 0;
    std::string line;
    while (std::getline(file, line))
    {
        for (int j = 0; j < cell_count; j++)
        {
            cells[j][i] = stoi(line.substr(j, 1));
        }

        i++;
    }
}

void Board::update()
{
    draw();
}

void Board::draw()
{
    for (int i = 0; i < cell_count; i++)
    {
        for (int j = 0; j < cell_count; j++)
        {
            if (cells[i][j] == 1)
            {
                DrawRectangle(i * cell_size, j * cell_size, cell_size, cell_size, BLACK);
            }
        }
    }

    for (int i = 0; i < cell_count; i++)
    {
        DrawLine(0, i * cell_size, cell_size * cell_count, i * cell_size, {0, 0, 0, 32});
        DrawLine(i * cell_size, 0, i * cell_size, cell_size * cell_count, {0, 0, 0, 32});
    }
}
