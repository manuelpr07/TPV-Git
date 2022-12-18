#include"EndState.h"
#include"Game.h"

const std::string EndState::s_pauseID = "END";

void EndState::update()
{
	for each (GameObject * var in getGameObjets())
	{
		var->update();
	}
}
void EndState::render()
{
	for each (GameObject * var in getGameObjets())
	{
		var->render();
	}
}
bool EndState::onEnter()
{
	if(won)
		message = new Message(Vector2D(WIN_WIDTH / 2 - 200, WIN_HEIGTH / 6), 300, 400, getGame()->getTexture(winnerT));
	else message = new Message(Vector2D(WIN_WIDTH / 2 - 200, WIN_HEIGTH / 6), 300, 400, getGame()->getTexture(gameOver));
	GameObject* button1 = new MenuButton(WIN_WIDTH / 2, WIN_HEIGTH / 6 * 4, getGame()->getTexture(startT), getGame(), play);
	GameObject* button2 = new MenuButton(WIN_WIDTH / 2, WIN_HEIGTH / 6 * 5, getGame()->getTexture(MenuT), getGame(), menu);
	includeGameObjets(button1);
	includeGameObjets(button2);
	includeGameObjets(message);
	std::cout << "entering EndState\n";
	return true;
}
bool EndState::onExit()
{
	for each (GameObject * var in getGameObjets())
	{
		getGameObjets().remove(var);
	}
	getGameObjets().clear();
	std::cout << "exiting EndState\n";
	return true;
}
void EndState::handleEvents()
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
void EndState::menu(Game* game)
{
	game->getStateMachine()->changeState(new MenuState(game));
}
void EndState::play(Game* game)
{
	game->getStateMachine()->changeState(new PlayState(game, false));
}