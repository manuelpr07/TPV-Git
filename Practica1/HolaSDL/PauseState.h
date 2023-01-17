#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "MenuState.h"
class GameObject;
class PauseState : public GameState
{
private:
	static void menu(Game* game);
	static void play(Game* game);
	static void save(Game* game);
	static const std::string s_pauseID;

	MenuButton* button1;
	MenuButton* button2;

	SDL_Rect button1Rec;
	SDL_Rect button2Rec;

public:
	PauseState(Game* game_) : GameState(game_) {};
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	void handleEvents();
	virtual std::string getStateID() const { return s_pauseID; }

};