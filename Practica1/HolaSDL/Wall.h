#include "ArcanoidObject.h"

class Wall: public ArcanoidObject
{
private:

public:
	Wall(){};
	Wall(Vector2D position, unsigned int h, unsigned int w, Texture* text);
	void render();
	void update() {};
	void handdleEvents(SDL_Event event) {};
};