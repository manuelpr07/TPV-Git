#include "Wall.h"
#include "ArcanoidObject.h"
#include <list>
#include "Mouse.h"
class BlockMap;
class Paddle;
class Ball;
class Button;

using namespace std;
using uint = unsigned int;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGTH = 600;
const uint FRAME_RATE = 5;
const uint WALL_WIDTH = 15;
const uint NUM_TEXTURES = 11;
const uint BLOCK_HEIGHT = 20;
const uint BLOCK_WIDTH = 15;
const uint BALL_SIZE = 20;
const uint PADDLE_HEIGHT = 20;
const uint PADDLE_WIDTH = 100;
const int NUMMENU = 2;

enum TextureName{ballT, bricks, digit, gameOver, paddle, sideWall, topWall, winnerT, rewardT, startT, loadT};

typedef struct {
	string filename;
	uint hframes, vframes;
} TextureDescription;
const TextureDescription TEXT_DESCRIPT[NUM_TEXTURES]
{
	{"../images/ball2.png",1,1},{"../images/bricks2.png",3,2},{"../images/digits2.jpeg",3,4},{"../images/gameover1.png",1,1},
	{"../images/paddle2.png",2,3},{"../images/side2.png",1,10},{"../images/topside.png",10,1},{"../images/youwin.png",1,1},
	{"../images/rewards.png", 8, 10},{"../images/start.png", 1, 1},{"../images/load.png", 1, 1}
};
class Game {


private:

		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		bool gameOver, win, exit;
		Paddle* paddle = nullptr;
		Ball* ball = nullptr;
		BlockMap* blockMap = nullptr;
		Button* button = nullptr;
		Wall walls[3];
		Texture* textures[NUM_TEXTURES];
		int level = 1;
		int maxLevels = 4;
		bool cambioNivel = false;
		list<ArcanoidObject*> gObjects;
		list<ArcanoidObject*> gObjectsDestroy;

		
public:

	Game();
	~Game();
	void run();
	void render();
	void update();
	bool collides(SDL_Rect rect, Vector2D& collision_vector, const Vector2D& velocity);
	void handleEvents();
	void createReward(Vector2D position);
	void nextLevel();
	int menu();
	void loadFromFile();
	void saveToFile();
};
class Menu : public Game {
public:
	Button* StartButton;
	Menu();
	~Menu() {}
	void enter();
	void update();
	void exit();
};
class Options : public Game {
public:
	Options();
	~Options();
	void enter();
	void update();
	void exit();
};
