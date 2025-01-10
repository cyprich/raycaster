#include "Player.h"
#include <cmath>
#include <raylib.h>

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
};

void Player::move(bool forward)
{
    x += moving_speed * cos(angle) * (forward ? 1 : -1);
    y += moving_speed * sin(angle) * (forward ? 1 : -1);
};

void Player::draw()
{
    int hl = w * 2; // handle lenght
    DrawRectangle(x, y, w, h, RED);
    DrawLine(x + w / 2.0, y + w / 2.0, x + w / 2.0 + (hl * cos(angle)), y + w / 2.0 + (hl * sin(angle)), RED);
}
