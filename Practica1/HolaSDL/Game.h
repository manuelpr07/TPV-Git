
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Paddle.h"
#include "Ball.h"
#include "BlockMap.h"
#include "checkML.h"
#include <iostream>

using namespace std;
using uint = unsigned int;

const uint winWidth = 800;
const uint winHeight = 600;
const uint FRAME_RATE = 5;
const uint WALL_WIDTH = 15;
const uint NUM_TEXTURES = 8;

enum TextureName{paddle, ball, bricks, digit, ameOver, sideWall, topWall, winner};

typedef struct {
	string filename;
	uint hframes, vframes;
} TextureDescription;
const TextureDescription TEXT_DESCRIPT[NUM_TEXTURES]
{
	{"ball.png",1,1},{"bricks2.png",2,3},{"digits2.jpg",3,4},{"gameover1.png",1,1},{"paddle2.png"/*...*/}
};
class Game {


private:

		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		bool gameOver, win, exit;
		Paddle* paddle = nullptr;
		Ball* ball = nullptr;
		BlockMap* blockMap = nullptr;
		Wall walls[3];
		Texture* textures[NUM_TEXTURES];
		
public:
	bool win = false;

	Game() {

		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (window == nullptr || renderer == nullptr)
			cout << "Error cargando SDL" << endl;

		gameOver = win = exit = false;
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

		for (int i = 0; i < NUM_TEXTURES; i++){

			const TextureDescription& desc = TEXT_DESCRIPT[i];
			textures[i] = new Texture(render, desc.filename, desc.vframes, desc.hframes);
		}

		walls[0] = Wall(Vector2D(0, 0), WIN_HEIGTH, WALL_WIDTH, textures[sideWall]);
	}
	~Game() {
		delete(paddle);
		delete(ball);
		delete(ball);
		SDL_DestroyRenderer(renderer);
	  	SDL_DestroyWindow(window);
	  	SDL_Quit();
	}
	
	void run()
	{
		uint32_t  startTime, frameTime;
		startTime = SDL_GetTicks();
		while (!exit && !gameOver && !win) {
			handleEvents();
			frameTime = SDL_GetTicks();
			if (frameTime >= FRAME_RATE) {
				update();
				startTime = SDL_GetTicks();
			}
			render();
		}
	}
	void render(){
		SDL_RenderClear(renderer);
		for (int i = 0; i < 3;i++)
		{
			walls[i].render();
		}
		//Ball
		ball->render();
		//Paddle
		paddle->render();
		//BlockMap
		blockMap->render();



		SDL_RenderPresent(renderer);
	}
	void update() {

	}
	void collides() {

	}
	void handleEvents() {

	}
};