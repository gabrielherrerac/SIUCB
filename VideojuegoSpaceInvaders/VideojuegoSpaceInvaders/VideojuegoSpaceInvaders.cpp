

#include <iostream>
#include <raylib.h>
#include "Juego.h"


int main()
{
    Color grey = {0,58,11,0.8}; //Color fondo
    int windowWidth = 750;
    int windowHeight = 700; // Tamanio pantalla
    InitWindow(windowWidth, windowHeight, "Space Invaders");//inicializacion pantalla
    SetTargetFPS(60);
    
    Juego SIJuego; //Directorio de comandos
    

    while(WindowShouldClose() == false)//bucle de proceso
    {
        SIJuego.HandleInput();
        SIJuego.Update();
        BeginDrawing();
        ClearBackground(grey);
        SIJuego.Draw();
        EndDrawing();
    }
    CloseWindow();
}

