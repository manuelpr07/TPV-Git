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
    pos = pos + velocity;

    if (pos.getX() < 15)//golpea izq
    {
        velocity = { -velocity.getX(), velocity.getY()};
    }
    else if (pos.getX() > 765)//golpea drc
    {
        velocity = { -velocity.getX(), velocity.getY() };
    }
    if (pos.getY() > 560)//golpea arriba
    {
        velocity = { velocity.getX(), -velocity.getY() };
    }
    else if (pos.getY() < 0)
    {
        velocity = { velocity.getX(), -velocity.getY() };//perder
    }
}
