#include "Vector2D.h"
#include "Texture.h"

class Game;

class Ball
{
private:
	Vector2D pos;
	unsigned int heigth = 0;
	unsigned int width = 0;
	Vector2D velocity;
	Texture* tex = nullptr;
	Game* game = nullptr;

public:
	Ball() {};
	Ball(Vector2D position, unsigned int h, unsigned w, Vector2D vel, Texture* text, Game* _game) : pos(position), heigth(h), width(w), velocity(vel), tex(text) 
	{
		game = _game;
	}
	void render();
	void update();

};