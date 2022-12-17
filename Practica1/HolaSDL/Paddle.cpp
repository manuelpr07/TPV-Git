#include "Paddle.h"
#include "Game.h"
void Paddle::setLives(int lifeP)
{
    live += lifeP;
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
    currentType = type;
    switch (currentType)
    {
        case lifeP:setLives(1); currentType = none; break;//L fila 1 

        case nextLevelP:game->nextLevel(); currentType = none; break;//E fila  2

        case longP: Size(1); break;//C fila 3

        case shortP: Size(-1); break;//S fila 4
    }
    if (!(currentType == longP || currentType == shortP))
        Size(0);
}

void Paddle::Size(int change)
{
    if (change == 1)
    {
        if(getRect()->w < PADDLE_WIDTH)
            change = PADDLE_WIDTH;
        else change = PADDLE_WIDTH * 1.5;
    }
    else if (change == -1)
    {
        if (getRect()->w > PADDLE_WIDTH)
            change = PADDLE_WIDTH;
        else change = PADDLE_WIDTH * 0.75;
    }
    else
    {
        change = PADDLE_WIDTH;
    }
    ArcanoidObject::Size(change);
}

void Paddle::loadFromFile()
{
    int posX, posY;
    string sType;
    std::cin >> posX >> posY >> sType;
    setPos(Vector2D(posX, posY));
    if (sType == "lifeP")
        currentType = lifeP;
    else if (sType == "nextLevelP")
        currentType = nextLevelP;
    else if (sType == "longP")
        currentType = longP;
    else if (sType == "shortP")
        currentType = shortP;
    else currentType = none;

}

string Paddle::saveToFile()
{
    string datos = std::to_string(getRect()->x) + ' ' + std::to_string(getRect()->y) + ' ' + std::to_string(currentType);
    return datos;
}

bool Paddle::collides(SDL_Rect rect, Vector2D& collision_vector, const Vector2D& velocity) // comprueba colisiones con la bola o los powerUps
{
    if (SDL_HasIntersection(&rect ,getRect()))
    {
        {
            //double center = rect.x + (rect.w / 2);
            //double angle = (center - (getRect()->x + getRect()->w / 2)) / (getRect()->w / 2); //Cálculo del ángulo
            //collision_vector = { angle, -1 };
            //collision_vector.normalize();
            //return true;
            double angle;
            float dif = (rect.x + (rect.w / 2)) - (getRect()->x + (getRect()->w / 2));
            if (dif < 0)
            {
                angle = 1 + ((getRect()->w / 2) * dif) / 10000;

            }
            else if (dif > 0)
            {
                angle = 1 + ((getRect()->w / 2) * dif) / 10000;
            }
            else if (dif == 0)
            {
                angle = 1;
            }
            collision_vector = { angle, -2.5 };
            collision_vector.normalize();
            return true;
        }
    }
    return false;
}
