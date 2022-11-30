#include "MovingObject.h"

MovingObject::MovingObject(Vector2D position, unsigned int h, unsigned int w, Texture* text, Vector2D dir_) : ArcanoidObject(position, h, w, text)
{
	dir = dir_;
}

void MovingObject::render()
{
	ArcanoidObject::render();
}

void MovingObject::update()
{
	setPos(Vector2D(getRect().x + dir.getX(), getRect().y + dir.getY()));
}

Vector2D MovingObject::getDir()
{
	return dir;
}

void MovingObject::setDir(Vector2D dir_)
{
	dir = dir_;
}


