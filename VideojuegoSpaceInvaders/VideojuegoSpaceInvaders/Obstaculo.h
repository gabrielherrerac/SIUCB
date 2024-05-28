#pragma once
#include <vector>
#include "bloque.h"

using namespace std;
class Obstaculo
{
public:
	Obstaculo(Vector2 Posicion);
	void Draw();
	Vector2 posicion;
	vector<bloque> bloques;
	static vector<vector<int>> grid;
private:

};

