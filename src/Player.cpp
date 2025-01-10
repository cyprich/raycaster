#include "Player.h"
#include "globals.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

void Player::update()
{
    if (IsKeyDown(KEY_W))
    {
        move(true);
    }
    else if (IsKeyDown(KEY_S))
    {
        move(false);
    }

    if (IsKeyDown(KEY_D))
    {
        rotate(true);
    }
    else if (IsKeyDown(KEY_A))
    {
        rotate(false);
    }

    draw();
}

void Player::rotate(bool clockwise)
{
    angle += rotating_speed * (clockwise ? 1 : -1);

    // if it's more/less than 1 whole circle
    if (fabs(angle) > 2 * PI) // fabs() = float abs()
    {
        angle = angle - (2 * PI) * (angle > 1 ? 1 : -1);
    }
};

void Player::move(bool forward)
{
    float new_x = x + moving_speed * cos(angle) * (forward ? 1 : -1);
    float new_y = y + moving_speed * sin(angle) * (forward ? 1 : -1);

    bool can_move_x = !collisions(new_x, y) && !collisions(new_x + w, y) && !collisions(new_x, y + h) &&
                      !collisions(new_x + w, y + h);
    bool can_move_y = !collisions(x, new_y) && !collisions(x + w, new_y) && !collisions(x, new_y + h) &&
                      !collisions(x + w, new_y + h);

    can_move_x && (x = new_x);
    can_move_y && (y = new_y);
};

void Player::draw()
{
    int hl = w * 2.5; // handle lenght
    DrawRectangle(x, y, w, h, RED);
    DrawLine(x + w / 2.0, y + w / 2.0, x + w / 2.0 + (hl * cos(angle)), y + w / 2.0 + (hl * sin(angle)), RED);
}

bool Player::collisions(float new_x, float new_y)
{
    int cell_x = static_cast<int>(new_x) / cell_size; // static_cast<int>(new_x) is just like (int)new_x, but safer
    int cell_y = static_cast<int>(new_y) / cell_size;

    if (cell_x < 0 || cell_x >= cell_count || cell_y < 0 || cell_y >= cell_count)
    {
        return true;
    }

    return (*board)[cell_x][cell_y];
}
