#include "ArcanoidObject.h"

ArcanoidObject::ArcanoidObject(Vector2D position, unsigned int h, unsigned int w, Texture* text)
{
	rect.x = position.getX();
	rect.y = position.getY();
	rect.w = w;
	rect.h = h;

	texture = text;
}

ArcanoidObject::~ArcanoidObject()
{
	delete texture;
	texture = nullptr;
}

void ArcanoidObject::render()
{
	texture->render(rect);
}

string ArcanoidObject::loadFromFile(string str)
{
	//ifstream myfile(str);
	//string level;
	//if (myfile.is_open()) {
	//	char mychar;
	//	while (myfile) {
	//		mychar = myfile.get();
	//		level += mychar;
	//	}
	//	return level;
	//}
	//else throw std::string(" fichero de mapa de bloques no encontrado o no valido ");
	return" ";
}

void ArcanoidObject::saveToFile(string level)
{
	//ofstream MyFile("../Mapas/saveFile.txt");
	//MyFile << level;
	//MyFile.close();
}

SDL_Rect ArcanoidObject::getRect()
{

	return rect;
}
