#pragma once
class Button
{
private:
	Texture* texture = nullptr;
	SDL_Texture* texture;
	SDL_Rect sRect, dRect;
	bool selected;
public:

	Button(Vector2D position, unsigned int h, unsigned int w, Texture* text) {};
	Button(int x, int y);
	~Button() {};
	void SetY(int x, int y);
	void render();
	void update() {};
	void handdleEvents(SDL_Event event) {};
};

