#pragma once
#include "GameObject.h"

class MenuButton : public GameObject
{
public:
	MenuButton(float x, float y, Texture texture);
	virtual void render();
	virtual void update();
	virtual void clean();
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
};