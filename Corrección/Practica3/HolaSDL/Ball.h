#include"MovingObject.h"

class PlayState;

class Ball : public MovingObject
{

private:
	PlayState* game = nullptr;

public:
	Ball() {};
	Ball(Vector2D position, unsigned int h, unsigned w, Vector2D vel, Texture* text, PlayState* _game) : MovingObject(position, h, w, text, vel)
	{
		game = _game;
	}
	void render();
	void update();

	virtual void loadFromFile();
	virtual string saveToFile();
};