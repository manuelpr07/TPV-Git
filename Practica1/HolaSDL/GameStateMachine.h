#pragma once
#include "PlayState.h"
#include "MenuState.h"
class GameStateMachine
{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	
	void update();
	void render();
	void handleEvents();

private:
	std::vector<GameState*> m_gameStates;

};