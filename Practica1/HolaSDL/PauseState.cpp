#include"PauseState.h"
#include"Game.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::update()
{
	for each (GameObject * var in getGameObjets())
	{
		var->update();
	}
}
void PauseState::render()
{
	for each (GameObject * var in getGameObjets())
	{
		var->render();
	}
}
bool PauseState::onEnter()
{

	button1Rec.w = 180;
	button2Rec.w = 180;

	button1Rec.h = 60;
	button2Rec.h = 60;

	button1Rec.x = WIN_WIDTH / 2 - button1Rec.w/2;
	button2Rec.x = WIN_WIDTH / 2 - button2Rec.w/2;

	button1Rec.y = WIN_HEIGTH / 3;
	button2Rec.y = WIN_HEIGTH / 3 * 2;

	button1 = new MenuButton(button1Rec, getGame()->getTexture(startT), getGame(), play);
	button2 = new MenuButton(button2Rec, getGame()->getTexture(MenuT), getGame(), menu);
	includeGameObjets(button1);
	includeGameObjets(button2);
	std::cout << "entering PauseState\n";
	return true;
}
bool PauseState::onExit()
{
	for each (GameObject * var in getGameObjets())
	{
		getGameObjets().remove(var);
	}
	getGameObjets().clear();
	std::cout << "exiting PauseState\n";
	return true;
}
void PauseState::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				//salir del juego
			}
		}
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
		}
	}
}
void PauseState::menu(Game* game) 
{
	game->getStateMachine()->changeState(new MenuState(game));
}
void PauseState::play(Game* game)
{
	game->getStateMachine()->popState();
}
