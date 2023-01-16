#include "Ball.h"
#include "PlayState.h"

void Ball::render()
{
	SDL_Rect* destRect = getRect();
	Texture* tex = getText();
	tex->render(*destRect);
}

void Ball::update()
{
	//colision con bloques
	Vector2D collision_vector;
	if (game->collides(*getRect(), collision_vector, *getDir()))
	{
				
		Vector2D velocity;
		velocity = *getDir() - (*getDir() * collision_vector * collision_vector)*2;
		setDir(velocity);

	}
    setPos(*getPos() + *getDir());
}

void Ball::loadFromFile()
{
	double posX, posY, dirX, dirY;
	std::cin >> posX >> posY >> dirX >> dirY;
	setPos(Vector2D(posX, posY));
	setDir(Vector2D(dirX, dirY));
}

string Ball::saveToFile()
{
	string datos = std::to_string(getRect()->x) + ' ' + std::to_string(getRect()->y) + ' ' + std::to_string(getDir()->getX()) + ' ' + std::to_string(getDir()->getY());
	return datos;
}
