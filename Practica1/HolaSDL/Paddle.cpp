#include "Paddle.h"
#include "Game.h"
void Paddle::setLives(int life)
{
    live += life;
}
int Paddle::getLive()
{
    return live;
}
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
    switch (type)
    {
        case life:setLives(1); Size(0); break;//L fila 1 

        case nextLevel:game->NextLevel(); Size(0); break;//E fila  2

        case longP: Size(1);//C fila 3

        case shortP: Size(-1); break;//S fila 4
    }

}

void Paddle::Size(int change)
{
    if (change == 1)
    {
        change = PADDLE_WIDTH * 1.5;
    }
    if (change == -1)
    {
        change = PADDLE_WIDTH * 0.75;
    }
    else
    {
        change = PADDLE_WIDTH;
    }
}

bool Paddle::collides(SDL_Rect* rect, Vector2D& collision_vector, const Vector2D& velocity)
{
    if (SDL_HasIntersection(rect ,getRect()))
    {
        {
            double objectPos = rect->x + (rect->w / 2);
            double angle = (objectPos - (getRect()->x + getRect()->w / 2)) / (getRect()->w / 2); //C�lculo del �ngulo de reflexi�n
            collision_vector = { angle, -2.5 };
            collision_vector.normalize();
            return true;

        }
    }
    return false;
}
