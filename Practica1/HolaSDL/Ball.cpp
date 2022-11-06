#include "Ball.h"

void Ball::render()
{
	SDL_Rect destRect;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	destRect.h = heigth;
	destRect.w = width;
	tex->render(destRect);
}

void Ball::update()
{
	//colision con bloques
	Vector2D normal = pos;
	bool coli;
	coli = game->collides(normal, heigth);
	if (coli)
	{
		// aqui va la formula de reflexión
		//velocity = velocity − 2 ∗ (¿¿A?? ∗ normal) ∗ normal
	}

    pos = pos + velocity;
}
