#pragma once
#include "Elemento.h"

class Laser :
    public Elemento
{
public:
    Laser(Vector2 position, int speed);
    void Update();
    void Draw();
    bool active;
private:
    Vector2 position;
    int speed;
};

