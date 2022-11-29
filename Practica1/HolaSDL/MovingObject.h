
#include "ArcanoidObject.h"

class MovingObject : public ArcanoidObject
{
private:

	Vector2D dir = { 0,0 };

public:

	MovingObject() {};
	MovingObject(Vector2D position, unsigned int h, unsigned int w, Texture* text, Vector2D dir_);
	virtual ~MovingObject() {};
	virtual void render();
	virtual void update();
	virtual void handdleEvents(SDL_Event event) {};

	Vector2D getDir();
	void setDir(Vector2D dir_);

	virtual SDL_Rect getRect();
	virtual Vector2D getPos();
	virtual Texture* getText();


};