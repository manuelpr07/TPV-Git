#include "MovingObject.h"
#include "Reward.h"
class Paddle : public MovingObject
{
	class Game;
private:

	Game* game;
public:

	Paddle(Vector2D position, unsigned int h, unsigned w, Texture* text) : MovingObject(position, h, w, text, Vector2D( 0,0 )){};
	void render();
	void update();
	bool collides(SDL_Rect* rect, Vector2D& collision_vector, const Vector2D& velocity);
	void handdleEvents(int n);

	void getReward(rewardType type);


};