#pragma once

#include "ArcanoidObject.h"
#include "Block.h"
class BlockMap: public ArcanoidObject
{
private:
	unsigned int cellHeigth;
	unsigned int cellWidth;
	unsigned int nColumnas;
	unsigned int nFilas;
	unsigned int color;
	Block*** matriz = new Block** [nColumnas];
	Texture* texture;

public:

	BlockMap(unsigned int nfil, unsigned int ncol, Texture* text);
	~BlockMap();
	
	void render();
	void readMap(int level);
	int getBlocks();
	bool colides(Vector2D pos, int size, Vector2D& collision_vector, const Vector2D& velocity);
	
	
	void update() {};
	virtual void handdleEvents(SDL_Event event) {};

};