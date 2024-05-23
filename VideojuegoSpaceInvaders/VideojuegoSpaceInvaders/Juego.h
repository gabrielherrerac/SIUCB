#pragma once
#include "JugadorTanque.h"
class Juego
{
public:
	Juego();
	~Juego();
	void Draw();
	void Update();
	void HandleInput();
private:
	void DeleteInactiveLasers();
	JugadorTanque Tanque;
};

