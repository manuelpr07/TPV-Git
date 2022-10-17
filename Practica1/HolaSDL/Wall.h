#include "Vector2D.h"
#include "Texture.h"
class Wall
{
private:
	Vector2D pos;
	unsigned int heigth;
	unsigned int width;
	Texture* texture = nullptr;
public:
	
	Wall(Vector2D position, unsigned int h, unsigned w, Texture* text) : pos(position), heigth(h), texture() {}
	
	void render()
	{
		SDL_Rect destRect;
		destRect.x = pos.getX();
		destRect.y = pos.getY();
		destRect.h = heigth;
		destRect.w = width;
		texture->render(destRect);
	}


};