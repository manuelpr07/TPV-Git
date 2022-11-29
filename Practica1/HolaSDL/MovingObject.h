#pragma once
#include "ArcanoidObject.h"

class MovingObject : public ArcanoidObject
{
private:


public:

	virtual void render();
	virtual void update() {};
	virtual void handdleEvents(SDL_Event event) {};



};