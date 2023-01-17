#pragma once
#include"GameState.h"
#include"PlayState.h"
#include "MenuButton.h"
class MenuState : public GameState
{

private:
	static const std::string s_menuID;
	
	static void play(Game* game);
	static void load(Game* game);
	static void exit(Game* game);

	MenuButton* button1;
	MenuButton* button2;
	MenuButton* button3;

	SDL_Rect button1Rec;
	SDL_Rect button2Rec;
	SDL_Rect button3Rec;

public:

	MenuState(Game* game_) : GameState(game_) {};
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	void handleEvents();
	virtual std::string getStateID() const { return s_menuID; }

	

};