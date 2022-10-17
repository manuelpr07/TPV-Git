#include "Game.h"
class Texture {
private:
	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;
	uint w = 0; uint h = 0; // Texture width and height
	uint fw = 0; uint fh = 0; // Frame width and height
	uint numCols = 1; uint numRows = 1;
public:
	Texture(SDL_Renderer* r) : renderer(r) {};
	Texture(SDL_Renderer* r, string filename, uint numRows = 1, uint numCols = 1)
		: renderer(r) {
		load(filename, numRows, numCols);
	};
	~Texture() { free(); };
	
	void free();
	int getW() const { return w; };
	int getH() const { return h; };
	void load(string filename, uint numRows = 1, uint numCols = 1);
	void render(const SDL_Rect& rect, SDL_RendererFlip flip = SDL_FLIP_NONE) const;
	void renderFrame(const SDL_Rect& destRect, int row, int col, int angle = 0,
		SDL_RendererFlip flip = SDL_FLIP_NONE) const;
};