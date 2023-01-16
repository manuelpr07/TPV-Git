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
	static const std::string s_pauseID;
	ArcanoidObject* message = nullptr;
	bool won;


public:
	EndState(Game* game_, bool b) : GameState(game_), won(b) {};
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	void handleEvents();
	virtual std::string getStateID() const { return s_pauseID; }

};