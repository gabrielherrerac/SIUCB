#include "Juego.h"

Juego::Juego()
{

}

Juego::~Juego()
{

}

void Juego::Draw()
{
	Tanque.Draw();
}

void Juego::HandleInput()
{
	if (IsKeyDown(KEY_A))
	{
		Tanque.MoverIzq();
	}
	else if (IsKeyDown(KEY_D))
	{
		Tanque.MoverDerecha();
	}
}
