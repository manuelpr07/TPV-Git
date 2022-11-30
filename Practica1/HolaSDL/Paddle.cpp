#include "Paddle.h"
#include "Game.h"
void Paddle::render()
{
    MovingObject::render();
}
void Paddle::update()
{
    Vector2D pos = *getPos() + *getDir();

    if (pos.getX() < WALL_WIDTH)
    {
        pos = { WALL_WIDTH, pos.getY() };
    }
    else if (pos.getX() > WIN_WIDTH - WALL_WIDTH - getRect()->w)
    {
        pos = { WIN_WIDTH - (double)WALL_WIDTH - getRect()->w, pos.getY() };
    }
    setPos(pos);

}
void Paddle::handdleEvents(int n)
{
    setDir(Vector2D(n, 0));
}

void Paddle::getReward(rewardType type)
{

}

bool Paddle::collides(SDL_Rect* rect, Vector2D& collision_vector, const Vector2D& velocity)
{
    if (SDL_HasIntersection(rect ,getRect()))
    {
        {
            double objectPos = rect->x + (rect->w / 2);
            double angle = (objectPos - (getRect()->x + getRect()->w / 2)) / (getRect()->w / 2); //Cálculo del ángulo de reflexión
            collision_vector = { angle, -2.5 };
            collision_vector.normalize();
            return true;

        }
    }
    return false;
}
