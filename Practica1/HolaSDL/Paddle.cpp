#include "Paddle.h"

void Paddle::render()
{
	SDL_Rect destRect;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	destRect.h = heigth;
	destRect.w = width;
	texture->render(destRect);
}
void Paddle::update()
{
    pos = pos + dir*10;
}
void Paddle::handdleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        /*if (event.type == SDL_QUIT)
            game->setUserExit();*/
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_a) {
                dir = { -1,0 };
            }
            if (event.key.keysym.sym == SDLK_d) {
                dir = { 1,0 };
            }
        }
    }
}
