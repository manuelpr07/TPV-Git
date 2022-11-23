#include "Ball.h"
#include "Game.h"

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
	double angle = 0;
	coli = game->collides(normal, heigth, angle);
	if (coli)
	{
		// aqui va la formula de reflexión
		velocity = { velocity.getX() - ((normal.getX() * angle) * normal.getX()) * 2, velocity.getY() - ((normal.getY() * angle) * normal.getY()) * 2 };
		velocity.normalize();

	}
    pos = pos + velocity;
}
