#include "Vector2D.h"
#include "Texture.h"
class GameObject
{
public:

	//GameObject() {};
	virtual ~GameObject() {};
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handdleEvents(SDL_Event event) = 0;
};

