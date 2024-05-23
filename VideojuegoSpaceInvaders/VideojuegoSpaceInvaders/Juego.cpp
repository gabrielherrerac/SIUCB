#include "Juego.h"
#include <iostream>

Juego::Juego()
{

}

Juego::~Juego()
{

}

void Juego::Draw()
{
	Tanque.Draw();

	for(auto& laser:Tanque.lasers)
	{
		laser.Draw();
	}
}

void Juego::Update()
{
	for (auto& laser : Tanque.lasers)
	{
		laser.Update();
	}
	DeleteInactiveLasers();
	std::cout << "Vector Size: " << Tanque.lasers.size();
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
