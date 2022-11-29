#include "Reward.h"
#include "Paddle.h"


Reward::~Reward()
{
}

void Reward::render()
{
	//life, nextLevel, longP, shortP

	SDL_Rect destRect;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	destRect.h = heigth;
	destRect.w = width;
	tex->renderFrame(destRect, fil, col);

	col++;
	if (col > 7)
		col = 0;
}
void Reward::update()
{

	if (paddle->collides(pos, heigth, Vector2D{0,0}, velocity))
	{
		paddle->GetReward(type);
		delete this;
	}
	pos = pos + velocity;
}
