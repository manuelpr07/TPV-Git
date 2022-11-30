#include "Ball.h"
#include "Game.h"

void Ball::render()
{
	SDL_Rect destRect;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	destRect.h = heigth;
	destRect.w = width;
	tex->render(destRect);
}

void Ball::update()
{
	//colision con bloques
	Vector2D collision_vector;
	SDL_Rect rect = { pos.getX(), pos.getY(), heigth, width };
	//bool coli;
	//coli = game->collides(pos, heigth, collision_vector);
	if (game->collides(rect, collision_vector, velocity))
	{
		// aqui va la formula de reflexión
		// velocidad = velocidad - 2 * (velocidad * colisión * colisión)
				
		velocity = velocity - (velocity * collision_vector * collision_vector)*2;
		
		//Vector2D primeraOp = collision_vector * collision_vector;
		//Vector2D segundaOp = velocity * primeraOp;
		//velocity = velocity - segundaOp*2;

		velocity.normalize();

	}
    pos = pos + velocity;
}
