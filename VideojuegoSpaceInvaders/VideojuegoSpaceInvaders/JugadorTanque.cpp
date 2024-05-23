#include "JugadorTanque.h"

JugadorTanque::JugadorTanque()
{
	image = LoadTexture("Graficos/TanqueJugador.png");
	position.x = (GetScreenWidth() - image.width)/2;
	position.y = GetScreenHeight() - image.height;
	lastFireTime = 0.0;
}

JugadorTanque::~JugadorTanque()
{
	UnloadTexture(image);	
}

void JugadorTanque::MoverIzq()
{
	position.x -= 7;
	if (position.x < 0)
	{
		position.x = 0;
	}
}

void JugadorTanque::MoverDerecha()
{
	position.x += 7;
	if (position.x > GetScreenWidth() - image.width)
	{
		position.x = GetScreenWidth() - image.width;
	}
}

void JugadorTanque::DispararLaser()
{
	if (GetTime() - lastFireTime >= 0.35) {
		lasers.push_back(Laser({ position.x + image.width / 2 - 2,position.y }, -6));
		lastFireTime = GetTime();
	}
	
}

void JugadorTanque::Draw()
{
	DrawTextureV(image, position, WHITE);
}
