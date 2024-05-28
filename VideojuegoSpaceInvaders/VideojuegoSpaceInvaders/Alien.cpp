#include "Alien.h"

Texture2D Alien::ImagensAlien[3] = {};

Alien::Alien(int tipo, Vector2 posicion)
{
	this->tipo = tipo;
	this->position = posicion;
	if (ImagensAlien[tipo - 1].id == 0) {
		switch (tipo)
		{
		case 1:
			ImagensAlien[0] = LoadTexture("Graficos/InvasorA.png");
			break;
		case 2:
			ImagensAlien[1] = LoadTexture("Graficos/InvasorB.png");
			break;
		case 3:
			ImagensAlien[2] = LoadTexture("Graficos/InvasorC.png");
			break;
		default:
			ImagensAlien[0] = LoadTexture("Graficos/InvasorA.png");
			break;
		}
	}	
}

void Alien::Update(int direccion)
{
	position.x += direccion;
}

void Alien::Draw()
{
	DrawTextureV(ImagensAlien[tipo-1], position, WHITE);
}

int Alien::getTipo()
{
	return tipo;
}

void Alien::UnloadImagnes()
{
	for (int i = 0; i < 4; i++)
	{
		UnloadTexture(ImagensAlien[i]);
	}
}

Vector2 Alien::getPosition()
{
	return position;
}
