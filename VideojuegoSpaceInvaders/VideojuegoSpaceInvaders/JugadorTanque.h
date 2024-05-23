#pragma once
#include "Elemento.h"
#include "Laser.h"
#include <vector>

class JugadorTanque :
    public Elemento
{
public:
    JugadorTanque();
    ~JugadorTanque();
    void MoverIzq();
    void MoverDerecha();
    void DispararLaser();
    void Draw();
    std::vector<Laser> lasers;
private:
    double lastFireTime;
};

