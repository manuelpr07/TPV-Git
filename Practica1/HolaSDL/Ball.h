#include"MovingObject.h"

class Game;

class Ball : public MovingObject
{
private:
	Game* game = nullptr;

public:
	Ball() {};
	Ball(Vector2D position, unsigned int h, unsigned w, Vector2D vel, Texture* text, Game* _game) : MovingObject(position, h, w, text, vel)
	{
		game = _game;
	}
	void render();
	void update();

	virtual void loadFromFile();
	virtual string saveToFile();
};