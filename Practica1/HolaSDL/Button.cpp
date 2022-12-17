#include "Button.h"

SDL_Texture * Button::texture = 0;


Button::Button(SDL_Renderer * ren)
{
	texture = IMG_LoadTexture(ren, "./images/botones.PNG");
}






/*void Button::render()
{
	ArcanoidObject::render();
}*/


