#include "Vector2D.h"
#include "Texture.h"
class Game;
class Ball
{
private:
	Vector2D pos;
	unsigned int heigth;
	unsigned int width;
	Vector2D velocity;
	Texture* tex = nullptr;
	Game* game;
public:
	Ball() {};
	Ball(Vector2D position, unsigned int h, unsigned w, Vector2D vel, Texture* text, Game* game) : pos(position), heigth(h), width(w), velocity(vel), tex(), game() {}
	void render();
	//void update();

};