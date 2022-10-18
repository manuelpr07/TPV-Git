#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "BlockMap.h"

using namespace std;
using uint = unsigned int;

const uint winWidth = 800;
const uint winHeight = 600;
const uint FRAME_RATE = 5;
const uint WALL_WIDTH = 15;
const uint NUM_TEXTURES = 8;

enum TextureName{paddle, ball, bricks, digit, gameOver, sideWall, topWall, winner};

typedef struct {
	string filename;
	uint hframes, vframes;
} TextureDescription;
const TextureDescription TEXT_DESCRIPT[NUM_TEXTURES]
{
	{"ball.png",1,1},{"bricks2.png",2,3},{"digits2.jpg",3,4},{"gameover1.png",1,1},{"paddle2.png",2,3},{"sideWall1",1,10},{"topWall1",10,1},{"winner",1,1}
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

	Game();
	~Game();
	void run();
	void render();
	void update();
	void collides();
	void handleEvents();
};