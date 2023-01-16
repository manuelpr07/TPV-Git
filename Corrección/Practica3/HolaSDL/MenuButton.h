#pragma once
#include "GameObject.h"

class MenuState;
class Game;

class MenuButton : public GameObject
{
public:
	MenuButton(int x, int y, Texture* texture_, Game* game, void (*callback)(Game* game));
	virtual void render();
	virtual void update();
	bool mousePress(SDL_MouseButtonEvent& b);
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	button_state  m_currentFrame;
	Texture* texture = nullptr;
	SDL_Rect rect;	
	Game* game;
	void (*m_callback) (Game* game);

};