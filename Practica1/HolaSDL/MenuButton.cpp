#include "MenuButton.h"
#include "MenuState.h"
#include "Game.h"

MenuButton::MenuButton(SDL_Rect rec, Texture* texture_, Game* game_, void (*callback)(Game* game))
{
	game = game_;
	m_callback = callback;
	m_currentFrame = MOUSE_OUT; // start at frame 0
	rect = rec;
	texture = texture_;
}

void MenuButton::render()
{
	if (m_currentFrame == 0)
		texture->renderFrame(rect, 0, 0);
	else texture->renderFrame(rect, 0, 1);
}
void MenuButton::update()
{
		
	int auxX, auxY;
	SDL_Event e;
	SDL_GetMouseState(&auxX, &auxY);
	Vector2D* pMousePos = new Vector2D(auxX, auxY);
	

	if (pMousePos->getX() < (rect.x + rect.w) && pMousePos->getX() > rect.x
		&& pMousePos->getY() < (rect.y + rect.h) && pMousePos->getY() > rect.y)
	{
		m_currentFrame = MOUSE_OVER;
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}

}

void MenuButton::handleEvents() {

	m_callback(game);
}

SDL_Rect* MenuButton::getRect()
{
	return &rect;
}

int MenuButton::GetBState()
{
	return m_currentFrame;
}

bool MenuButton::mousePress(SDL_MouseButtonEvent& b) {
	if (b.button == SDL_BUTTON_LEFT) {
		return true;
	}
	return false;
}
