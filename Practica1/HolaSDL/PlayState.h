#pragma once
#include "GameState.h"
#include "GameStateMachine.h"
#include"Reward.h"
#include"Wall.h"

class BlockMap;
class Paddle;
class Ball;

class PlayState : public GameState
{
private:

	Paddle* paddle = nullptr;
	Ball* ball = nullptr;
	BlockMap* blockMap = nullptr;
	Wall walls[3];
	static const std::string s_playID;

	int level = 1;
	int maxLevels = 4;
	bool cambioNivel = false;
	list<ArcanoidObject*> gObjects;
	list<ArcanoidObject*> gObjectsDestroy;

public:

	PlayState(Game* game) : GameState(game) {};

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }

	bool collides(SDL_Rect rect, Vector2D& collision_vector, const Vector2D& velocity);
	void createReward(Vector2D position);
	void nextLevel();
	void handleEvents();
	void loadFromFile();
	void saveToFile();
};