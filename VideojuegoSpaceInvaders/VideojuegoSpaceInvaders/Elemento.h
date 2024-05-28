#pragma once
#include <raylib.h>
class Elemento
{
public:
	Elemento();
	~Elemento();
	virtual void Draw();
	Vector2 position;
protected:
	Texture2D image;
	
};

