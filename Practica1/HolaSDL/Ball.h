#include "Vector2D.h"
#include "Texture.h"
class Ball
{
private:
	Vector2D pos;
	Vector2D dir = { 0,0 };
	unsigned int heigth;
	unsigned int width;
	Texture* texture = nullptr;
	Game* game = nullptr;
public:

	Ball(Vector2D position, unsigned int h, unsigned w, Texture* text, Game* game) : pos(position), heigth(h), texture(), game() {}

	void render();

};