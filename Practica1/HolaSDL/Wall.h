#pragma once
#include "ArcanoidObject.h"
class Wall : public ArcanoidObject
{
private:
	Vector2D pos;
	unsigned int heigth;
	unsigned int width;
	Texture* texture = nullptr;
public:
	Wall(){};
	Wall(Vector2D position, unsigned int h, unsigned int w, Texture* text) : ArcanoidObject(position, h, w, text) {};
	void render();
	void update() {};
	void handdleEvents(SDL_Event event) {};
	virtual void loadFromFile() {};
	virtual string saveToFile() { return "*"; };
};