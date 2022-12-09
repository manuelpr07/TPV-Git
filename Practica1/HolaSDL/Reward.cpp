#include "Reward.h"
#include "Paddle.h"



Reward::~Reward()
{
}

void Reward::render()
{
	//life, nextLevel, longP, shortP

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
//	if (tipo == "life")
//		type = life;
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
	if (type == life)
		datos += "life";
	else if (type == nextLevel)
		datos += "nextLevel";
	else if (type == longP)
		datos += "longP";
	else if (type == shortP)
		datos += "shortP";

	return datos;
}
