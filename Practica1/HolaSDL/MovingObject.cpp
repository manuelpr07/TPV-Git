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
	setPos(*getPos() + *getDir());
}

Vector2D* MovingObject::getDir()
{
	return &dir;
}

void MovingObject::setDir(Vector2D dir_)
{
	dir = dir_;
}
void MovingObject::Size(int change)
{
	ArcanoidObject::Size(change);
}


