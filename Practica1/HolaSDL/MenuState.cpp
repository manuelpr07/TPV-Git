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
	GameObject* button1 = new MenuButton(100, 100, game->getTexture(startT));
	GameObject* button2 = new MenuButton(100, 100, game->getTexture(ExitT));
	includeGameObjets(button1);
	includeGameObjets(button2);
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
				s_menuToPlay();
			}
		}
	}
}

void MenuState::s_menuToPlay()
{
	game->getStateMachine()->changeState(new PlayState(game));
}
