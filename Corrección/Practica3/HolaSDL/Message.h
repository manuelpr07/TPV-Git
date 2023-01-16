#pragma once
#include "ArcanoidObject.h"
class Message : public ArcanoidObject
{
private:

public:
	Message() {};
	Message(Vector2D position, unsigned int h, unsigned int w, Texture* text) : ArcanoidObject(position, h, w, text) {};
	void render();
	void update() {};
	void handdleEvents(SDL_Event event) {};
	virtual void loadFromFile() {};
	virtual string saveToFile() { return ""; };
};