#pragma once
#include"MovingObject.h"
#include"Game.h"

class Paddle;

enum rewardType { lifeP, nextLevelP, longP, shortP, none};

class Reward : public MovingObject
{
private:

	rewardType type;
	int fil, col;
	Paddle* paddle;
	bool elim = false;

public:
	Reward(Vector2D position, unsigned int h, unsigned int w, Texture* text, rewardType type_, Paddle* paddle_) : MovingObject(position, h, w, text, Vector2D(0,1))
	{
		type = type_;
		paddle = paddle_;

		switch (type)
		{
		case lifeP: fil = 0; break;//L fila 1 
		case nextLevelP: fil = 2; break;//E fila  2
		case longP: fil = 3; break;//C fila 3
		case shortP: fil = 4; break;//S fila 4
		}
		col = 0;

	};
	~Reward();
	virtual void render();
	virtual void update();

	bool eliminar() { return elim; };

	virtual void loadFromFile() {};
	virtual string saveToFile();

};