#include "Block.h"

void Block::render()
{
	int fil, col;
	switch (color)
	{
		case 1: fil = 0, col = 0; break;
		case 2: fil = 0, col = 1; break;
		case 3: fil = 0, col = 2; break;
		case 4: fil = 1, col = 0; break;
		case 5: fil = 1, col = 1; break;
		case 6: fil = 1, col = 2; break;
	}
	SDL_Rect destRect;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	destRect.h = heigth;
	destRect.w = width;
	tex->renderFrame(destRect, fil, col);
}
