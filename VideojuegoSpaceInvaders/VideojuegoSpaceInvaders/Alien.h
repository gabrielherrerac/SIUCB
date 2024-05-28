#pragma once
#include "Elemento.h"
class Alien :
    public Elemento
{
public:
    Alien(int tipo, Vector2 posicion);
    void Update(int direccion);
    void Draw();
    int getTipo();
    static void UnloadImagnes();
    static Texture2D ImagensAlien[3];
    int tipo;
    Vector2 getPosition();
private:

};

