#pragma once
#include "Elemento.h"
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
private:
};

