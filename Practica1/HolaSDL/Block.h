#include"ArcanoidObject.h"
class Block : public ArcanoidObject
{
private:

	unsigned int color;
	unsigned int fila;
	unsigned int columna;

public:
	Block() {};
	Block(Vector2D position, unsigned int h, unsigned int w, unsigned int cl, unsigned int fil, unsigned int col, Texture* text) : ArcanoidObject(position, h, w, text)
	{
		color = cl;
		fila = fil;
		columna = col;
	}
	~Block() {};
	bool colides(Vector2D pos, int size, Vector2D& collision_vector);
	void render();
	Vector2D* getPos();
	int getCol();
	//void update();
	virtual void loadFromFile() {};
	virtual string saveToFile() { return "*"; };

};