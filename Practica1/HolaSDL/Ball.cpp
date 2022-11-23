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
	Vector2D normal;
	bool coli;
	coli = game->collides(pos, heigth, normal);
	if (coli)
	{
		// aqui va la formula de reflexión
		// velocidad = velocidad - 2 * (velocidad * colisión * colisión)
		velocity = { velocity.getX() - ((normal.getX()) * normal.getX()) * 2, velocity.getY() - ((normal.getY()) * normal.getY()) * 2 };
		velocity.normalize();

	}
    pos = pos + velocity;
}
