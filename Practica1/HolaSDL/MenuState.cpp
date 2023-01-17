#include "MenuState.h"
#include "Game.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for each (GameObject * var in getGameObjets())
	{
		var->update();
	}
}
void MenuState::render()
{
	for each (GameObject * var in getGameObjets())
	{
		var->render();
	}
}
bool MenuState::onEnter()
{

	button1Rec.w = 180;
	button2Rec.w = 180;
	button3Rec.w = 180;

	button1Rec.h = 60;
	button2Rec.h = 60;
	button3Rec.h = 60;

	button1Rec.x = WIN_WIDTH / 2 - button1Rec.w/2;
	button2Rec.x = WIN_WIDTH / 2 - button2Rec.w/2;
	button3Rec.x = WIN_WIDTH / 2 - button3Rec.w/2;

	button1Rec.y = WIN_HEIGTH / 4;
	button2Rec.y = WIN_HEIGTH / 4*2;
	button3Rec.y = WIN_HEIGTH / 4*3;

	button1 = new MenuButton(button1Rec, getGame()->getTexture(startT), getGame(), play);
	button2 = new MenuButton(button2Rec, getGame()->getTexture(loadT), getGame(), load);
	button3 = new MenuButton(button3Rec, getGame()->getTexture(ExitT), getGame(), exit);
	includeGameObjets(button1);
	includeGameObjets(button2);
	includeGameObjets(button3);
	std::cout << "entering MenuState\n";
	return true;
}
bool MenuState::onExit()
{
	for each (GameObject * var in getGameObjets())
	{
		getGameObjets().remove(var);
	}
	getGameObjets().clear();
	std::cout << "exiting MenuState\n";
	return true;
}
void MenuState::handleEvents() {
	
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		if ((event.type == SDL_MOUSEBUTTONUP) && event.button.button == SDL_BUTTON_LEFT)
		{
			int auxX, auxY;
			SDL_Event e;
			SDL_GetMouseState(&auxX, &auxY);
			Vector2D* pMousePos = new Vector2D(auxX, auxY);
			

			if (pMousePos->getX() < (button1Rec.x + button1Rec.w) && pMousePos->getX() > button1Rec.x && pMousePos->getY() < (button1Rec.y + button1Rec.h) && pMousePos->getY() > button1Rec.y)
			{
				button1->handleEvents();
			}
			else if (pMousePos->getX() < (button2Rec.x + button2Rec.w) && pMousePos->getX() > button2Rec.x && pMousePos->getY() < (button2Rec.y + button2Rec.h) && pMousePos->getY() > button2Rec.y)
			{
				button2->handleEvents();
			}
			else if (pMousePos->getX() < (button3Rec.x + button3Rec.w) && pMousePos->getX() > button3Rec.x && pMousePos->getY() < (button3Rec.y + button3Rec.h) && pMousePos->getY() > button3Rec.y)
			{
				button3->handleEvents();
			}
		}

	}

}
void MenuState::play(Game* game) {

	game->getStateMachine()->changeState(new PlayState(game, false));
}
void MenuState::load(Game* game)
{
	game->getStateMachine()->changeState(new PlayState(game, true));
}
void MenuState::exit(Game* game)
{
	game->setExit();
	std::cout << "Exit button clicked\n";
}

