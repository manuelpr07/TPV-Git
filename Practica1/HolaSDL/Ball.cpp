#include "Ball.h"
#include "Game.h"


Ball::Ball(Vector2D position, unsigned int h, unsigned w, Vector2D vel, Texture* text, Game* _game) : MovingObject(position, h, h, text, vel)
{
	game = _game;
	iniPos = getPos();
	iniVel = getDir();
}

void Ball::render()
{
	MovingObject::render();
}

void Ball::update()
{
	//colision con bloques
	Vector2D collision_vector;
	Vector2D pos = getPos();
	Vector2D velocity = getDir();

	//bool coli;
	//coli = game->collides(pos, heigth, collision_vector);
	if (game->collides(pos, getRect().w, collision_vector, velocity))
	{
		// aqui va la formula de reflexión
		// velocidad = velocidad - 2 * (velocidad * colisión * colisión)
		
		
		velocity = velocity - (velocity * collision_vector * collision_vector)*2;
		
		//Vector2D primeraOp = collision_vector * collision_vector;
		//Vector2D segundaOp = velocity * primeraOp;
		//velocity = velocity - segundaOp*2;

		setDir(velocity);
	}
	MovingObject::update();
}

void Ball::setIni()
{
	setPos(iniPos);
	setDir(iniVel);
}
