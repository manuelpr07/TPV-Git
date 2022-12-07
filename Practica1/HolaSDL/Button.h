#pragma once
#include "ArcanoidObject.h"
class Button : public ArcanoidObject
{
private:
	Vector2D pos;
	unsigned int heigth;
	unsigned int width;
	Texture* texture = nullptr;
	bool selected;
public:

	Button(Vector2D position, unsigned int h, unsigned int w, Texture* text) : ArcanoidObject(position, h, w, text) {};
	~Button() {};
	void render();
	void update() {};
	void handdleEvents(SDL_Event event) {};
};

