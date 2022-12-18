#pragma once
#include"GameState.h"
#include"PlayState.h"
#include "MenuButton.h"
class MenuState : public GameState
{

private:
	static const std::string s_menuID;
	Game* game = nullptr;
	
	static void play(Game* game);
	static void load(Game* game);
	static void exit(Game* game);
public:

	MenuState(Game* game_) : GameState(game_) 
	{
		game = game_;
	};
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	void handleEvents();
	virtual std::string getStateID() const { return s_menuID; }

	

};