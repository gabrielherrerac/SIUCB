#include "Juego.h"
#include <iostream>

Juego::Juego()
{
	obstaculos = CrearObstaculo();
	aliens = CrearAliens();
	direccionAlien = 1;
}

Juego::~Juego()
{
	Alien::UnloadImagnes();
}

void Juego::Draw()
{
	Tanque.Draw();

	for(auto& laser:Tanque.lasers)
	{
		laser.Draw();
	}
	for (auto& Obstaculo : obstaculos) {
		Obstaculo.Draw();
	}
	for (auto& Alien : aliens) {
		Alien.Draw();
	}
}

void Juego::Update()
{
	for (auto& laser : Tanque.lasers)
	{
		laser.Update();
	}
	moverAliens();
	DeleteInactiveLasers();
	//std::cout << "Vector Size: " << Tanque.lasers.size(); 
	//codigo para mostrar datos
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
	else if (IsKeyDown(KEY_SPACE)) {
		Tanque.DispararLaser();
	}
	
}

void Juego::DeleteInactiveLasers()
{
	for (auto it = Tanque.lasers.begin(); it != Tanque.lasers.end();) {
		if (!it->active) {
			it = Tanque.lasers.erase(it);
		}
		else
		{
			++ it;
		}
	}
}

vector<Obstaculo> Juego::CrearObstaculo()
{
	int obstacleWidth = Obstaculo::grid[0].size()*3;
	float gap = (GetScreenWidth() - (4 * obstacleWidth)) / 5;

	for (int i = 0; i < 4; i++) {
		float offsetX = (i + 1) * gap + i * obstacleWidth;
		obstaculos.push_back(Obstaculo({ offsetX,float(GetScreenHeight() - 100)}));
		cout << float(GetScreenHeight() - 100);
	}
	return obstaculos;
}

vector<Alien> Juego::CrearAliens()
{
	vector<Alien> aliens;
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 11; column++)
		{
			int tipoalien;
			if (row == 0) {
				tipoalien = 3;
			}else if (row == 1 || row == 2) {
				tipoalien = 2;
			}else {
				tipoalien = 1;
			}
			float x = 75+column * 55;
			float y = 110+row * 55;
			aliens.push_back(Alien(tipoalien, { x,y }));
		}
	}
	return aliens;
}

void Juego::moverAliens()
{
	for (auto& alien : aliens) {
		if (alien.getPosition().x + alien.ImagensAlien[alien.tipo - 1].width > GetScreenWidth())
		{
			direccionAlien = -1;
			moverAbajoAliens(4);
		}
		if (alien.getPosition().x < 0) {
			direccionAlien = 1;
			moverAbajoAliens(4);
		}
		alien.Update(direccionAlien);
	}
}

void Juego::moverAbajoAliens(int distancia)
{
	for (auto& alien : aliens) {
		alien.position.y += distancia;
	}
}
