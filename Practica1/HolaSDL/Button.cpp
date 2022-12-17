#include "Button.h"

SDL_Texture * Button::texture = 0;


Button::Button(SDL_Renderer * ren, float x, float y)
{
	texture = IMG_LoadTexture(ren, "./images/botones.PNG");
	srect.x = x;
	srect.y = y;
	drect.h = srect.h = 327 / 6;
	drect.w = srect.w = 331 / 2;
	
}

/*void Button::render()
{
	ArcanoidObject::render();
}*/

void Button::draw(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, texture, &srect, &drect);
}

void Button::setPos(float x, float y)
{
	drect.x = x;
	drect.y = y;
}

