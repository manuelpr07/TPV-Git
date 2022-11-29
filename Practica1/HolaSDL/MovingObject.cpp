#include "MovingObject.h"

MovingObject::MovingObject(Vector2D position, unsigned int h, unsigned int w, Texture* text, Vector2D dir_) : ArcanoidObject(position, h, w, text)
{
	dir = dir_;
}

void MovingObject::update()
{
	Vector2D pos = getPos() + getDir();
	setPos(pos);
}
void MovingObject::render()
{
	ArcanoidObject::render();
}

Vector2D MovingObject::getDir()
{
	return dir;
}

void MovingObject::setDir(Vector2D dir_)
{
	dir = dir_;
}

SDL_Rect MovingObject::getRect()
{
	return ArcanoidObject::getRect();
}

Vector2D MovingObject::getPos()
{
	return ArcanoidObject::getPos();
}

Texture* MovingObject::getText()
{
	return ArcanoidObject::getText();;
}

