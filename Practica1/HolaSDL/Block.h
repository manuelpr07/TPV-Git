#include"ArcanoidObject.h"
class Block : ArcanoidObject
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
	Block(Vector2D position, unsigned int h, unsigned int w, unsigned int cl, unsigned int fil, unsigned int col, Texture* text) : ArcanoidObject(position, h, w, text)
	{
		color = cl;
		fila = fil;
		columna = col;
	}
	bool colides(Vector2D pos, int size, Vector2D& collision_vector);
	void render();
	//void update();

};