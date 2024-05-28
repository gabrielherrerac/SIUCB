#include "Obstaculo.h"

vector<vector<int>> Obstaculo::grid = {
		{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
		{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
		{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
};

Obstaculo::Obstaculo(Vector2 Posicion)
{
	this->posicion = Posicion;
	
	for (unsigned int row = 0; row < grid.size(); ++row)
	{
		for (unsigned int column = 0; column < grid[0].size(); ++column)
		{
			if (grid[row][column] == 1)
			{
				float pos_x = posicion.x + column * 3;
				float pos_y = posicion.y + row * 3;
				bloque Bloque = bloque({ pos_x,pos_y });
				bloques.push_back(Bloque);
			}
		}
	}
}

void Obstaculo::Draw()
{
	for (auto& bloque:bloques) {
		bloque.Draw();
	}
}
