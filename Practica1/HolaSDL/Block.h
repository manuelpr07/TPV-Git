#include "Vector2D.h"
#include "Texture.h"
class Block
{
private:
	Vector2D pos;
	unsigned int heigth;
	unsigned int width;
	unsigned int color;
	unsigned int fila;
	unsigned int columna;
	Texture* tex = nullptr;

public:
	Block() {};
	Block(Vector2D position, unsigned int h, unsigned int w, unsigned int cl, unsigned int fil, unsigned int col, Texture* text) : pos(position), heigth(h), width(w), color(cl), fila(fil), columna(col),  tex(text){}
	void render();
	//void update();

};