#include"ArcanoidObject.h"
#include"Block.h"
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
	Block*** matriz = new Block** [nColumnas];


public:

	BlockMap(unsigned int nfil, unsigned int ncol, Texture* text) : ArcanoidObject(Vector2D{0,0}, 0, 0, text)
	{
		nFilas = nfil;
		nColumnas = ncol;
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
	bool colides(Vector2D pos, int size, Vector2D& collision_vector, const Vector2D& velocity);
	//void update();

};