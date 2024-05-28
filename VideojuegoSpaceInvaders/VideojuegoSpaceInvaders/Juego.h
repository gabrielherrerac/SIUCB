#pragma once
#include "JugadorTanque.h"
#include "Obstaculo.h"
#include "Alien.h"

using namespace std;
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
	vector<Obstaculo> CrearObstaculo();
	vector<Alien> CrearAliens();
	void moverAliens();
	void moverAbajoAliens(int distancia);
	JugadorTanque Tanque;
	vector<Obstaculo> obstaculos;
	vector<Alien> aliens;
	int direccionAlien;
};

