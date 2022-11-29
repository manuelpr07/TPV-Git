#include "Paddle.h"
#include "Game.h"
#include "Reward.h"
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
void Paddle::handdleEvents(SDL_Event event)
{
    if (event.key.keysym.sym == SDLK_a) {
        dir = Vector2D(-1, 0);
    }
    else if (event.key.keysym.sym == SDLK_d) {
        dir = Vector2D(1, 0);
    }
    else if (event.type == SDL_KEYUP) {
        dir = Vector2D(0, 0);
    }
}

bool Paddle::collides(Vector2D _pos, int size, Vector2D& collision_vector, const Vector2D& velocity)
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
        }
    }
    return false;
}

/*void Paddle::GetReward(rewardType type)
{
}*/
