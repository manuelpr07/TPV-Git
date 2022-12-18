#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<list>
#include"GameObject.h"

class Game;

class GameState
{

public:
	GameState(Game* game_) 
	{
		game = game_;
	};
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
	virtual Game* getGame() { return game; };
	virtual void handleEvents() = 0;
	list<GameObject*> getGameObjets();
	void includeGameObjets(GameObject* Objet);

private:
	list<GameObject*> gObjects;
	Game* game = nullptr;

};