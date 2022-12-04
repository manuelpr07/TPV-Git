#include"Game.h"
#include"Ball.h"
#include"Paddle.h"
#include"BlockMap.h"
#include"Reward.h"
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
	Button =  Button(Vector2D(WIN_WIDTH / 2, WIN_HEIGTH / 3), 20, 40, textures[start]);

	walls[0] = Wall(Vector2D(WIN_WIDTH-20, 0), WIN_HEIGTH, WALL_WIDTH, textures[sideWall]);
	walls[1] = Wall(Vector2D(5, 0), WIN_HEIGTH, WALL_WIDTH, textures[sideWall]);
	walls[2] = Wall(Vector2D(0, 0), WALL_WIDTH, WIN_WIDTH, textures[topWall]);

	ball = new Ball(Vector2D(WIN_WIDTH/2,WIN_HEIGTH-50),20,20,Vector2D(1,1), textures[ballT], this);
	paddle = new Paddle(Vector2D(WIN_WIDTH / 2, WIN_HEIGTH - 20), 20, 100, textures[4], this);
	blockMap = new BlockMap(10, 10, textures[bricks], this);
	blockMap->readMap(level);

	gObjects.push_back(&walls[0]);
	gObjects.push_back(&walls[1]);
	gObjects.push_back(&walls[2]);
	gObjects.push_back(blockMap);
	gObjects.push_back(paddle);
	//gObjects.push_back(ball);

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
	//paddle->render();
	////BlockMap
	//blockMap->render();

	for each (ArcanoidObject * var in gObjects)
	{
		var->render();
	}

	SDL_RenderPresent(renderer);
}
void Game::update() {

	//paddle->update();
	ball->update();
	for each (ArcanoidObject* var in gObjects)
	{
		var->update();
		if (var->eliminar())
		{
			gObjectsDestroy.push_back(var);
		}
	}

	for each (ArcanoidObject * var in gObjectsDestroy)
	{
		gObjects.remove(var);
	}
}
bool Game::collides(SDL_Rect rect, Vector2D& collision_vector, const Vector2D& velocity) {

	bool colisiona = false;

	// Paredes
	if (rect.x <= WALL_WIDTH)//golpea pared izq
	{
		collision_vector = { 1, 0 };
		return true;
	}
	else if (rect.x >= WIN_WIDTH - WALL_WIDTH - BALL_SIZE)//golpea pared drc
	{
		collision_vector = { -1, 0 };
		return true;
	}
	else if (rect.y <= 0)//golpea pared arriba
	{
		collision_vector = { 0, 1 };
		return true;
	}
	else if (rect.y >= WIN_HEIGTH - BALL_SIZE)//perder
	{
		collision_vector = { 0, -1 };

		if (paddle->getLive() >= 1)
		{
			paddle->setLives(-1);
		}
		if(paddle->getLive() == 0)
		{
			//gameOver = true;
		}

		return true;
	}

	//colision con bloques
	colisiona = blockMap->colides(rect, collision_vector, velocity);

	if (!colisiona)
	{
		//colision con la pala
		colisiona = paddle->collides(&rect, collision_vector, velocity);
	}
	if (blockMap->getBlocks() == 0)
	{
		win = true;
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

void Game::createReward(Vector2D position)
{
	Reward* r = nullptr;
	int aux1 = rand() %4;
	if (aux1 == 0)
	{
		r = new Reward(position, PADDLE_HEIGHT, PADDLE_WIDTH / 2, textures[rewardT], life, paddle);
	}
	else if (aux1 == 1)
	{
		r = new Reward(position, PADDLE_HEIGHT, PADDLE_WIDTH / 2, textures[rewardT], longP, paddle);
	}
	else if (aux1 == 2)
	{
		r = new Reward(position, PADDLE_HEIGHT, PADDLE_WIDTH / 2, textures[rewardT], shortP, paddle);
	}
	else if (aux1 == 3)
	{
		r = new Reward(position, PADDLE_HEIGHT, PADDLE_WIDTH / 2, textures[rewardT], nextLevel, paddle);
	}
	gObjects.push_back(r);
}
void Game::NextLevel()
{
	level++;
}

void Game::Menu()
{
	//SDL_Surface* menus[NUMMENU];
	//SDL_Color color[2] = { {255,255,255},{255,0,0} };
	//menus[0] =
	//menus[1] =

	if (start)
	{
		run();
	}
	else
	{
		//cargar partida
	}


}


