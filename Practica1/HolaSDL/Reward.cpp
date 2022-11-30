#include "Reward.h"
#include "Paddle.h"



Reward::~Reward()
{
}

void Reward::render()
{
	//life, nextLevel, longP, shortP

	SDL_Rect destRect = *getRect();
	Texture* tex = getText();
	tex->renderFrame(destRect, fil, col);

	col++;
	if (col > 7)
		col = 0;
}
void Reward::update()
{

	if (paddle->collides(getRect(), Vector2D{0,0}, *getDir()))
	{
		paddle->getReward(type);
		elim = true;
		return;
	}
	MovingObject::update();
}