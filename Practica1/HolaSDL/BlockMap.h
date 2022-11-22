#include "Vector2D.h"
#include "Texture.h"
#include "Block.h"
#include <iostream>
#include <fstream>
#include <string>
class BlockMap
{
private:
	Vector2D pos = { 0, 0 };
	unsigned int cellHeigth;
	unsigned int cellWidth;
	unsigned int winHeigth;
	unsigned int winWidth;
	unsigned int nColumnas;
	unsigned int nFilas;
	unsigned int color;
	Block*** matriz = new Block** [nColumnas];
	Texture* tex = nullptr;


public:

	BlockMap(unsigned int nfil, unsigned int ncol, Texture* text) :nFilas(nfil), nColumnas(ncol), tex(text)
	{

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
	bool colides(Vector2D& pos, int size, double& angle);
	//void update();

};