#include"Game.h"


//#include "Button.h"


Game::Game() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGTH, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;

	exit = false;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	for (int i = 0; i < NUM_TEXTURES; i++) {

		const TextureDescription& desc = TEXT_DESCRIPT[i];
		textures[i] = new Texture(renderer, desc.filename, desc.vframes, desc.hframes);
	}

	gameStateMachine_ = new GameStateMachine();
	gameStateMachine_->changeState(new MenuState(this));

}
Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run()
{
	uint32_t  startTime, frameTime;
	startTime = SDL_GetTicks();
	while (!exit) {
		frameTime = SDL_GetTicks();
		gameStateMachine_->handleEvents();
		if (frameTime- startTime >= FRAME_RATE) {
			update();
			startTime = SDL_GetTicks();
		}
		render();
	}
}
void Game::render() {
	SDL_RenderClear(renderer);
	gameStateMachine_->render();
	SDL_RenderPresent(renderer);
}

void Game::update() {
	gameStateMachine_->update();
}

void Game::setExit()
{
	exit = true;
}


Texture* Game::getTexture(TextureName tex)
{
	return textures[tex];
}
