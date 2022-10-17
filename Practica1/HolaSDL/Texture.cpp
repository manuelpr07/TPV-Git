#include "Texture.h"

void Texture::free() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
	w = h = 0;
}
void Texture::load(string filename, uint nRows, uint nCols) {
	SDL_Surface* tempSurface = IMG_Load(filename.c_str());
	if (tempSurface == nullptr) throw “Error loading surface from " + filename;
		free();
	texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (texture == nullptr) throw "Error loading texture from " + filename;
	numRows = nRows;
	numCols = nCols;
	w = tempSurface->w; h = tempSurface->h;
	fw = w / numCols; fh = h / numRows;
	SDL_FreeSurface(tempSurface);
}