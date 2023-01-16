#pragma once
#include "GameState.h"
#include"Reward.h"
#include"Wall.h"
#include"PauseState.h"
#include"EndState.h"

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

	bool load = false;
	int level = 1;
	int maxLevels = 2;
	bool cambioNivel = false;
	list<GameObject*> gObjectsDestroy;

public:

	PlayState(Game* game, bool load_) : GameState(game), load(load_) {};

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