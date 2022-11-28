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

	walls[0] = new Wall(Vector2D(WIN_WIDTH-20, 0), WIN_HEIGTH, WALL_WIDTH, textures[sideWall]);
	walls[1] = new Wall(Vector2D(5, 0), WIN_HEIGTH, WALL_WIDTH, textures[sideWall]);
	walls[2] = new Wall(Vector2D(0, 0), WALL_WIDTH, WIN_WIDTH,	textures[topWall]);
	ball = new Ball(Vector2D(WIN_WIDTH/2,WIN_HEIGTH-50),20,20,Vector2D(1,1), textures[ballT], this);
	paddle = new Paddle(Vector2D(WIN_WIDTH / 2, WIN_HEIGTH - 20), 20, 100, textures[4]);
	blockMap = new BlockMap(10, 10, textures[bricks]);
	blockMap->readMap(level);

	//gObjects.push_back(walls[0]);
	//gObjects.push_back(walls[1]);
	//gObjects.push_back(walls[2]);
	//gObjects.push_back(blockMap);
	//gObjects.push_back(ball);
	//gObjects.push_back(paddle);

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
		if (nextLevel)
		{
			ball->setIni();
			blockMap->readMap(level);
			nextLevel = false;
		}
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

	//Ball;
	ball->render();
	//Paddle
	paddle->render();


	for each (auto it in gObjects)
	{
		it->render();
	}

	SDL_RenderPresent(renderer);
}
void Game::update() {

	paddle->update();
	ball->update();
}
bool Game::collides(Vector2D pos, int size, Vector2D& collision_vector, const Vector2D& velocity) {

	bool colisiona = false;

	// Paredes
	if (pos.getX() <= WALL_WIDTH)//golpea pared izq
	{
		collision_vector = { 1, 0 };
		return true;
	}
	else if (pos.getX() >= WIN_WIDTH - WALL_WIDTH - BALL_SIZE)//golpea pared drc
	{
		collision_vector = { -1, 0 };
		return true;
	}
	else if (pos.getY() <= 0)//golpea pared arriba
	{
		collision_vector = { 0, 1 };
		return true;
	}
	else if (pos.getY() >= WIN_HEIGTH - BALL_SIZE)//perder
	{
		collision_vector = { 0, -1 };
		//gameOver = true;
		return true;
	}

	//colision con bloques
	colisiona = blockMap->collides(pos, size, collision_vector, velocity);

	if (!colisiona)
	{
		//colision con la pala
		colisiona = paddle->collides(pos, size, collision_vector, velocity);
	}
	if (blockMap->getBlocks() == 0)
	{
		//win = true;
		level++;
		nextLevel = true;
		
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
				paddle->handdleEvents(event);
			}
			if (event.key.keysym.sym == SDLK_d) {
				paddle->handdleEvents(event);
			}
			if (event.key.keysym.sym == SDLK_p) {
				exit = true;
			}
		}
		else if (event.type == SDL_KEYUP)
		{
			paddle->handdleEvents(event);
		}
	}


}