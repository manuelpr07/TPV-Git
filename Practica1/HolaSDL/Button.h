#pragma once
#include "ArcanoidObject.h"
#include "Texture.h"
class Button : public ArcanoidObject
{

private:
	static SDL_Texture* texture;
	SDL_Rect srect, drect;
	bool selected = false;


public:


	Button() {};
	void update() {};
	void draw(SDL_Renderer* ren);
	Button(SDL_Renderer* ren) {};


	~Button() {};



/*private:
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
	virtual void loadFromFile(string str) {};
	virtual void saveToFile(string level) {};*/
};

