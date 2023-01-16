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
	GameObject* button1 = new MenuButton(WIN_WIDTH / 2, WIN_HEIGTH / 3, getGame()->getTexture(startT), getGame(), play);
	GameObject* button2 = new MenuButton(WIN_WIDTH / 2, WIN_HEIGTH / 3 * 2, getGame()->getTexture(MenuT), getGame(), menu);
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