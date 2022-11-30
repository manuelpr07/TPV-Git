#include "MovingObject.h"
#include "Reward.h"
class Game;

class Paddle : public MovingObject
{

private:

	Game* game = nullptr;
	int live = 1;
public:

	Paddle(Vector2D position, unsigned int h, unsigned w, Texture* text, Game* _game) : MovingObject(position, h, w, text, Vector2D( 0,0 ))
	{
		game = _game;
	}
	void setLives(int life);
	int getLive();
	void render();
	void update();
	bool collides(SDL_Rect* rect, Vector2D& collision_vector, const Vector2D& velocity);
	void handdleEvents(int n);
	void getReward(rewardType type);

	virtual void Size(int change);
};