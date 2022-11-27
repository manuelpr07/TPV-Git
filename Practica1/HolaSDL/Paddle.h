#include "Vector2D.h"
#include "Texture.h"
class Paddle
{
private:
	Vector2D pos;
	Vector2D dir = {0,0};
	unsigned int heigth;
	unsigned int width;
	Texture* texture = nullptr;
public:

	Paddle(Vector2D position, unsigned int h, unsigned w, Texture* text) : pos(position), heigth(h), width(w), texture(text) {}

	void render();
	void update();
	bool colides(Vector2D _pos, int size, Vector2D& collision_vector, const Vector2D& velocity);
	void handdleEvents(SDL_Event event);

};