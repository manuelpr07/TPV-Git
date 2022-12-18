#include"GameState.h"
#include"Game.h"

list<GameObject*> GameState::getGameObjets()
{
	return gObjects;
}

void GameState::includeGameObjets(GameObject* Objet)
{
	gObjects.push_back(Objet);
}
