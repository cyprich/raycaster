#pragma once

class Player
{
  private:
    static const int w = 12;
    static const int h = 12;

    float x = 300;
    float y = 300;
    float angle = 0;

    float moving_speed = 1.25;   // pixels per frame
    float rotating_speed = 0.05; // degrees pre frame

  public:
    Player() {};
    ~Player() {};

    void rotate(bool clockwise);
    void move(bool forward);
    void draw();

    void update();
};
