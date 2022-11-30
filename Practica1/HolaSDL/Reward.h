#pragma once
#include "Vector2D.h"
#include "Texture.h"
class Paddle;
enum rewardType { life, nextLevel, longP, shortP };
class Reward
{
private:
	Vector2D pos;
	unsigned int heigth = 0;
	unsigned int width = 0;
	Vector2D velocity;
	Texture* tex;
	rewardType type;
	int fil, col;
	Paddle* paddle;

public:
	Reward(Vector2D position, unsigned int h, unsigned w, Texture* text, rewardType type_, Paddle* paddle_) : pos(position), heigth(h), width(w),tex(text), type(type_), paddle(paddle_) 
	{
		switch (type)
		{
		case life: fil = 0; break;//L fila 1 
		case nextLevel: fil = 2; break;//E fila  2
		case longP: fil = 3;//C fila 3
		case shortP: fil = 4; break;//S fila 4
		}
		col = 0;

	};
	~Reward();
	virtual void render();
	virtual void update();

};