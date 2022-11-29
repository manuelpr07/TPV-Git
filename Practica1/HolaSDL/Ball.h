
#include"MovingObject.h"
class Game;

class Ball: public MovingObject
{
private:

	Vector2D iniPos;
	Vector2D iniVel;
	Game* game = nullptr;


public:
	Ball() {};
	Ball(Vector2D position, unsigned int h, unsigned w, Vector2D vel, Texture* text, Game* _game);

	~Ball()
	{
		delete game;
		game = nullptr;
	};
	void render();
	void update();
	void setIni();

};