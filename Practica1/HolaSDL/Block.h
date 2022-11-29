#pragma once

#include "ArcanoidObject.h"
class Block: public ArcanoidObject {
private:

	unsigned int color;
	unsigned int fila;
	unsigned int columna;

public:
	Block() {};
	Block(Vector2D position, unsigned int h, unsigned int w, unsigned int cl, unsigned int fil, unsigned int col, Texture* text);
	bool colides(Vector2D pos, int size, Vector2D& collision_vector);
	void render();
	//void update();

};