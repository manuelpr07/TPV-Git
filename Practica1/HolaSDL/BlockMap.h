#pragma once
#include"ArcanoidObject.h"
#include"Block.h"
#include"Reward.h"

class Game;

class BlockMap: public ArcanoidObject
{
private:
	unsigned int cellHeigth;
	unsigned int cellWidth;
	unsigned int winHeigth;
	unsigned int winWidth;
	unsigned int nColumnas;
	unsigned int nFilas;
	unsigned int color;
	Block*** matriz;
	Game* game = nullptr;

public:

	BlockMap(unsigned int nfil, unsigned int ncol, Texture* text, Game* game_) : ArcanoidObject(Vector2D{0,0}, 0, 0, text)
	{
		nFilas = nfil;
		nColumnas = ncol;
		game = game_;
		matriz = new Block **[nColumnas];
		for (int i = 0; i < nColumnas; i++) {
			matriz[i] = new Block*[nFilas];
		}
	}
	~BlockMap()
	{
		for (int i = 0; i < nColumnas; i++) {
			delete[] matriz[i];
		}
		delete[] matriz;
	}
	void render();
	void readMap(int level);
	int getBlocks();
	bool colides(SDL_Rect rect, Vector2D& collision_vector, const Vector2D& velocity);
	void breakBlock(int i, int j);
	//void update();

	virtual void loadFromFile();
	virtual string saveToFile();
	string saveLineByLine(int line);

};