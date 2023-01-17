#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "PlayState.h"
#include "Message.h"
class GameObject;
class EndState : public GameState
{
private:
	static void menu(Game* game);
	static void play(Game* game);
	static void exit(Game* game);
	static const std::string s_pauseID;
	ArcanoidObject* message = nullptr;
	bool won;

	MenuButton* button1;
	MenuButton* button2;

	SDL_Rect button1Rec;
	SDL_Rect button2Rec;

public:
	EndState(Game* game_, bool b) : GameState(game_), won(b) {};
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	void handleEvents();
	virtual std::string getStateID() const { return s_pauseID; }

};