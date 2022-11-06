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
void Paddle::update()
{
    pos = pos + dir;

    if(pos.getX() < 15)
    {
        pos = {15, pos.getY()};
    }
    else if (pos.getX() > 685)
    {
        pos = { 685, pos.getY() };
    }

}
void Paddle::handdleEvents(int n)
{
    dir = Vector2D(n, 0);
}

bool Paddle::colides(Vector2D& _pos, int size, int& angle)
{
    if ((_pos.getX() + size >= pos.getX() && _pos.getX() <= pos.getX()) || (_pos.getX() >= pos.getX() && _pos.getX() + size <= pos.getX() + width) || (_pos.getX() <= pos.getX() + width && _pos.getX() + size >= pos.getX() + width))
    {
        if (_pos.getY() <= pos.getY() && _pos.getY() + size >= pos.getY())// golpea por arriba
        {

            _pos = { 0,1 };
            return true;
        }
    }
}