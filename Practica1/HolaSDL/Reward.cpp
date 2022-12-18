#include "Reward.h"
#include "Paddle.h"
#include"Game.h"

Reward::~Reward()
{
}

void Reward::render()
{
	//lifeP, nextLevel, longP, shortP

	SDL_Rect destRect = *getRect();
	Texture* tex = getText();
	tex->renderFrame(destRect, fil, col);

	col++;
	if (col > 7)
		col = 0;
}
void Reward::update()
{

	if (paddle->collides(*getRect(), Vector2D{0,0}, *getDir()))
	{
		paddle->getReward(type);
		elim = true;
		return;
	}

	if (getPos()->getY() > WIN_HEIGTH)
	{
		elim = true;
		return;
	}

	MovingObject::update();
}

//void Reward::loadFromFile()
//{
//	int posX, posY;
//	string tipo;
//	std::cin >> posX >> posY >> tipo;
//	setPos(Vector2D(posX, posY));
//
//
//	if (tipo == "lifeP")
//		type = lifeP;
//	else if( tipo == "nextLevel") 
//		type = nextLevel;
//	else if( tipo == "longP") 
//		type = longP;
//	else if( tipo == "shortP") 
//		type = shortP;
//}

string Reward::saveToFile()
{
	string datos;
	datos += std::to_string(getRect()->x) + " " + std::to_string(getRect()->y) + " ";
	if (type == lifeP)
		datos += "lifeP";
	else if (type == nextLevelP)
		datos += "nextLevelP";
	else if (type == longP)
		datos += "longP";
	else if (type == shortP)
		datos += "shortP";

	return datos;
}
