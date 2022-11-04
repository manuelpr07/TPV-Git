#include"Game.h"
#include <iostream>

Game::Game() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGTH, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;

	gameOver = win = exit = false;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	for (int i = 0; i < NUM_TEXTURES; i++) {

		const TextureDescription& desc = TEXT_DESCRIPT[i];
		textures[i] = new Texture(renderer, desc.filename, desc.vframes, desc.hframes);
	}

	walls[0] = Wall(Vector2D(WIN_WIDTH-20, 0), WIN_HEIGTH, WALL_WIDTH, textures[sideWall]);
	walls[1] = Wall(Vector2D(5, 0), WIN_HEIGTH, WALL_WIDTH, textures[sideWall]);
	walls[2] = Wall(Vector2D(0, 0), WALL_WIDTH, WIN_WIDTH, textures[topWall]);

	//ball = new Ball(Vector2D(WIN_WIDTH/2,WIN_HEIGTH-50), );
	paddle = new Paddle(Vector2D(WIN_WIDTH / 2, WIN_HEIGTH - 20), 5, 20, textures[4]);
}
Game::~Game() {
	delete(paddle);
	delete(ball);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run()
{
	uint32_t  startTime, frameTime;
	startTime = SDL_GetTicks();
	while (!exit && !gameOver && !win) {
		paddle->handdleEvents();
		frameTime = SDL_GetTicks();
		if (frameTime >= FRAME_RATE) {
			update();
			startTime = SDL_GetTicks();
		}
		render();
	}
}
void Game::render() {
	SDL_RenderClear(renderer);
	for (int i = 0; i < 3;i++)
	{
		walls[i].render();
	}
	//Ball
	//ball->render();
	//Paddle
	paddle->render();
	//BlockMap
	//blockMap->render();



	SDL_RenderPresent(renderer);
}
void Game::update() {

}
void Game::collides() {

}
void Game::handleEvents() {

}