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

	button1Rec.w = 180;
	button2Rec.w = 180;

	button1Rec.h = 60;
	button2Rec.h = 60;

	button1Rec.x = WIN_WIDTH / 2 - button1Rec.w/2;
	button2Rec.x = WIN_WIDTH / 2 - button2Rec.w/2;

	button1Rec.y = WIN_HEIGTH / 6 * 4;
	button2Rec.y = WIN_HEIGTH / 6 * 5;

	button1 = new MenuButton(button1Rec, getGame()->getTexture(MenuT), getGame(), menu);
	button2 = new MenuButton(button2Rec, getGame()->getTexture(ExitT), getGame(), exit);
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
void EndState::menu(Game* game)
{
	game->getStateMachine()->changeState(new MenuState(game));
}
void EndState::play(Game* game)
{
	game->getStateMachine()->changeState(new PlayState(game, false));
}

void EndState::exit(Game* game) {
	game->setExit();
	std::cout << "Exit button clicked\n";
}