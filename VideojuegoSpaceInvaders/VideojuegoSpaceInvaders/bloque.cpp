#include "bloque.h"

bloque::bloque(Vector2 position)
{
	this->position = position;
}

void bloque::Draw()
{
	DrawRectangle(position.x, position.y, 3, 3, { 243,216,63,255 });
}
