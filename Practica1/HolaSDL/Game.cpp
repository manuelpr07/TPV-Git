#include"Game.h"
#include"Ball.h"
#include"Paddle.h"
#include"BlockMap.h"
#include<iostream>


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

	ball = new Ball(Vector2D(WIN_WIDTH/2,WIN_HEIGTH-50),20,20,Vector2D(1,1), textures[ballT], this);
	paddle = new Paddle(Vector2D(WIN_WIDTH / 2, WIN_HEIGTH - 20), 20, 100, textures[4]);
	blockMap = new BlockMap(WIN_HEIGTH, WIN_WIDTH, 10, 10, textures[bricks]);
	blockMap->readMap(level);
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
		frameTime = SDL_GetTicks();
		handleEvents();
		if (frameTime- startTime >= FRAME_RATE) {
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
	//Ball;
	ball->render();
	//Paddle
	paddle->render();
	//BlockMap
	blockMap->render();



	SDL_RenderPresent(renderer);
}
void Game::update() {

	paddle->update();
	ball->update();
}
bool Game::collides(Vector2D& pos, int size, double& angle) {

	bool colisiona = false;

	//colision con bloques
	colisiona = blockMap->colides(pos, size, angle);

	if (!colisiona)
	{
		//colision con la pala
		colisiona = paddle->colides(pos, size, angle);

		//colision con las paredes
		if (!colisiona) {
			if (pos.getX() <= WALL_WIDTH)//golpea pared izq
			{
				pos = { 1, 0 };
				angle = -1;
				colisiona = true;
			}
			else if (pos.getX() >= WIN_WIDTH-WALL_WIDTH)//golpea pared drc
			{
				pos = { -1, 0 };
				angle = 1;
				colisiona = true;
			}
			else if (pos.getY() <= 0)//golpea pared arriba
			{
				pos = { 0, -1 };
				angle = -1;
				colisiona = true;
			}
			else if (pos.getY() >= WIN_HEIGTH)//perder
			{
				//pos = { 0, 1 };
				//angle = 1;
				//colisiona = true;
				gameOver = true;
			}
		}
	}
	if (blockMap->getBlocks() == 0)
	{
		level++;
	}
	return colisiona;
}
void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		/*if (event.type == SDL_QUIT)
			exit = true;*/
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_a) {
				paddle->handdleEvents(-1);
			}
			if (event.key.keysym.sym == SDLK_d) {
				paddle->handdleEvents(1);
			}
			if (event.key.keysym.sym == SDLK_p) {
				exit = true;
			}
		}
		else if (event.type == SDL_KEYUP)
		{
			paddle->handdleEvents(0);
		}
	}


}