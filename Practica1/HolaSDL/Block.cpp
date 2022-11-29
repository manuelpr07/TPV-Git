#include "Block.h"

Block::Block(Vector2D position, unsigned int h, unsigned int w, unsigned int cl, unsigned int fil, unsigned int col, Texture* text) : ArcanoidObject(position, h, w, text)
{
	color = cl;
	fila = fil;
	columna = col;

}

void Block::render()
{
	int fil = 0, col = 0;
	switch (color)
	{
		case 1: fil = 0, col = 0; break;
		case 2: fil = 0, col = 1; break;
		case 3: fil = 0, col = 2; break;
		case 4: fil = 1, col = 0; break;
		case 5: fil = 1, col = 1; break;
		case 6: fil = 1, col = 2; break;
	}
	SDL_Rect destRect = getRect();
	Texture* tex = getText();
	tex->renderFrame(destRect, fil, col);
}

bool Block::colides(Vector2D pos, int size, Vector2D& collision_vector)
{
	return false;
}
