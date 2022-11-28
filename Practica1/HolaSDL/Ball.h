#pragma once

#include "Vector2D.h"
#include "Texture.h"

class Game;

class Ball
{
private:
	Vector2D pos;
	Vector2D iniPos;
	unsigned int heigth = 0;
	unsigned int width = 0;
	Vector2D velocity;
	Vector2D iniVel;
	Texture* tex = nullptr;
	Game* game = nullptr;


public:
	Ball() {};
	Ball(Vector2D position, unsigned int h, unsigned w, Vector2D vel, Texture* text, Game* _game) : pos(position), heigth(h), width(w), velocity(vel), tex(text)
	{
		game = _game;
		iniPos = pos;
		iniVel = vel;
	};
	~Ball()
	{
		delete tex;
		tex = nullptr;
		delete game;
		game = nullptr;
	};
	void render();
	void update();
	void setIni();

};