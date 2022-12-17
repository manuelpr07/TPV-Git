#include "MenuState.h"
const std::string MenuState::s_menuID = "MENU";
void MenuState::update()
{
	//llamar al update de los botones, checkear eventos
}
void MenuState::render()
{
	//llamar al render de los botones
}
bool MenuState::onEnter()
{
	//generar los botones
	std::cout << "entering MenuState\n";
	return true;
}
bool MenuState::onExit()
{
	//destruir los botones
	std::cout << "exiting MenuState\n";
	return true;
}
void MenuState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		/*if (event.type == SDL_QUIT)
			exit = true;*/
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_p) {
				//cambio para salir
			}
		}
	}
}