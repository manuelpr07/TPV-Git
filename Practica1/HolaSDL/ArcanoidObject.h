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
	ArcanoidObject(Vector2D position, unsigned int h, unsigned int w, Texture* text);
	ArcanoidObject() {};
	~ArcanoidObject();

	//metodos de gameObject
	void render();
	virtual void update() = 0;
	virtual void handdleEvents(SDL_Event event) = 0;

	//metodos de la propia clase
	string loadFromFile(string str);
	void saveToFile(string level);
	SDL_Rect getRect();

};
