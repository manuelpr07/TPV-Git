#include "Paddle.h"
#include "Game.h"
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

    if (pos.getX() < WALL_WIDTH)
    {
        pos = { WALL_WIDTH, pos.getY() };
    }
    else if (pos.getX() > WIN_WIDTH - WALL_WIDTH - width)
    {
        pos = { WIN_WIDTH - (double)WALL_WIDTH - width, pos.getY() };
    }

}
void Paddle::handdleEvents(int n)
{
    dir = Vector2D(n, 0);
}

bool Paddle::colides(Vector2D _pos, int size, Vector2D& collision_vector, const Vector2D& velocity)
{
    if ((_pos.getX() + size >= pos.getX() && _pos.getX() <= pos.getX()) ||
        (_pos.getX() >= pos.getX() && _pos.getX() + size <= pos.getX() + width) ||
        (_pos.getX() <= pos.getX() + width && _pos.getX() + size >= pos.getX() + width)) {
        if (_pos.getY() + size >= pos.getY() && _pos.getY() <= pos.getY())// golpea por arriba
        {
            double ballpos = _pos.getX() + (size / 2);
            double angle = (ballpos - (pos.getX() + width / 2)) / (width / 2); //Cálculo del ángulo de reflexión
            collision_vector = { angle, -2.5 };
            collision_vector.normalize();
            return true;


            collision_vector.normalize();//noralizar
            return true;
        }
    }
    return false;
}
