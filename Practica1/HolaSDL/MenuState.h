#include"GameState.h"
class MenuState : public GameState
{
private:
	static const std::string s_menuID;
	Game* game = nullptr;
public:

	MenuState(Game* game) : GameState(game) {};
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	void handleEvents();
	virtual std::string getStateID() const { return s_menuID; }
};