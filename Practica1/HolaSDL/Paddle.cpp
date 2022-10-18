#include "Paddle.h"

void Paddle::render()
{
	SDL_Rect destRect;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	destRect.h = heigth;
	destRect.w = width;
	texture->render(destRect);
}
