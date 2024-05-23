#pragma once
#include <raylib.h>
class Elemento
{
public:
	Elemento();
	~Elemento();
	virtual void Draw();
protected:
	Texture2D image;
	Vector2 position;
};

