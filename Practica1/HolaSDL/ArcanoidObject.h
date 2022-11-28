#include "GameObject.h"
#include <iostream>
#include <fstream>
#include <string>

class ArcanoidObject: public GameObject
{
private:

	SDL_Rect rect;
	Texture* texture = nullptr;

public:
	//constructora
	//ArcanoidObject(Vector2D position, unsigned int h, unsigned int w, Texture* text);
	ArcanoidObject() {};
	virtual ~ArcanoidObject();

	//metodos de gameObject
	virtual void render();// si se pone const es en todos los render
	virtual void update(){};
	virtual void handdleEvents(SDL_Event event){};

	//metodos de la propia clase
	virtual string loadFromFile(string str);
	virtual void saveToFile(string level);
	virtual SDL_Rect getRect();

};
