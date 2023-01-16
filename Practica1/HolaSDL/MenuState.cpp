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
	GameObject* button1 = new MenuButton(WIN_WIDTH/2, WIN_HEIGTH/4, getGame()->getTexture(startT), getGame(), play);
	GameObject* button2 = new MenuButton(WIN_WIDTH/2, WIN_HEIGTH/4*2, getGame()->getTexture(loadT), getGame(), load);
	GameObject* button3 = new MenuButton(WIN_WIDTH/2, WIN_HEIGTH/4*3, getGame()->getTexture(ExitT), getGame(), exit);
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

		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				//salir del juego
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

