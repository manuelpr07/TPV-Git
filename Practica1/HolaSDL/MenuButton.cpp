#include "MenuButton.h"



MenuButton::MenuButton(int x, int y, Texture* texture)
{
	m_currentFrame = MOUSE_OUT; // start at frame 0
}
void MenuButton::render()
{
	texture->render(rect);
}
void MenuButton::update()
{
	int auxX, auxY;
	SDL_Event e;
	SDL_GetMouseState(&auxX,&auxY);
	Vector2D* pMousePos = new Vector2D(auxX, auxY);

	if (pMousePos->getX() < (rect.x + rect.w) && pMousePos->getX() > rect.x
		&& pMousePos->getY() < (rect.y + rect.h) && pMousePos->getY() > rect.y)
	{
		m_currentFrame = MOUSE_OVER;
		if (mousePress(e.button))
		{
			m_currentFrame = CLICKED;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

bool MenuButton::mousePress(SDL_MouseButtonEvent& b) {
	if (b.button == SDL_BUTTON_LEFT) {
		return true;
	}
	return false;
}
