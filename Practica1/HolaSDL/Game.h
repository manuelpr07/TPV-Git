#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "BlockMap.h"

using namespace std;
using uint = unsigned int;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGTH = 600;
const uint FRAME_RATE = 5;
const uint WALL_WIDTH = 15;
const uint NUM_TEXTURES = 8;

enum TextureName{ball, bricks, digit, gameOver, paddle, sideWall, topWall, winner};

typedef struct {
	string filename;
	uint hframes, vframes;
} TextureDescription;
const TextureDescription TEXT_DESCRIPT[NUM_TEXTURES]
{
	{"../images/ball2.png",1,1},{"../images/bricks2.png",2,3},{"../images/digits2.jpeg",3,4},{"../images/gameover1.png",1,1},
	{"../images/paddle2.png",2,3},{"../images/side2.png",1,10},{"../images/topside.png",10,1},{"../images/youwin.png",1,1}
};
class Game {


private:

		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		bool gameOver, win, exit;
		Paddle* paddle = nullptr;
		Ball* ball = nullptr;
		//BlockMap* blockMap = nullptr;
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