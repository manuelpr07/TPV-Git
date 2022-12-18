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
	GameObject* button1 = new MenuButton(WIN_WIDTH/2, WIN_HEIGTH/4, game->getTexture(startT), game, play);
	GameObject* button2 = new MenuButton(WIN_WIDTH/2, WIN_HEIGTH/4*2, game->getTexture(loadT), game, load);
	GameObject* button3 = new MenuButton(WIN_WIDTH/2, WIN_HEIGTH/4*3, game->getTexture(ExitT),game, exit);
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
	//TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	//TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}
void MenuState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_s) {
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
	std::cout << "Exit button clicked\n";
}

