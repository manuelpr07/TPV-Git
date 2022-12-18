#include "PlayState.h"
#include"Ball.h"
#include"Paddle.h"
#include"BlockMap.h"
#include "Game.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	handleEvents();
	for each (ArcanoidObject* var in getGameObjets())
	{
		var->update();
		if (var->eliminar())
		{
			gObjectsDestroy.push_back(var);
		}
	}

	for each (ArcanoidObject * var in gObjectsDestroy)
	{
		getGameObjets().remove(var);
	}

	if(cambioNivel)
	{
		if (level > maxLevels)
			getGame()->getStateMachine()->pushState(new EndState(getGame(), true));
		else
			blockMap->readMap(level);
		cambioNivel = false;
	}
}
void PlayState::render()
{

	for each (ArcanoidObject * var in getGameObjets())
	{
		var->render();
	}
	// nothing for now
}
bool PlayState::onEnter()
{
	walls[0] = Wall(Vector2D(WIN_WIDTH - 20, 0), WIN_HEIGTH, WALL_WIDTH, getGame()->getTexture(sideWall));
	walls[1] = Wall(Vector2D(5, 0), WIN_HEIGTH, WALL_WIDTH, getGame()->getTexture(sideWall));
	walls[2] = Wall(Vector2D(0, 0), WALL_WIDTH, WIN_WIDTH, getGame()->getTexture(topWall));

	ball = new Ball(Vector2D(WIN_WIDTH / 2, WIN_HEIGTH - 50), 20, 20, Vector2D(1, 1), getGame()->getTexture(ballT), this);
	paddle = new Paddle(Vector2D(WIN_WIDTH / 4, WIN_HEIGTH - 20), 20, 100, getGame()->getTexture(paddleT), this);
	blockMap = new BlockMap(40, 40, getGame()->getTexture(bricks), this);


	includeGameObjets(&walls[0]);
	includeGameObjets(&walls[1]);
	includeGameObjets(&walls[2]);
	includeGameObjets(blockMap);
	includeGameObjets(paddle);
	includeGameObjets(ball);

	if (!load)
		blockMap->readMap(1);
	else loadFromFile();

	std::cout << "entering PlayState\n";
	return true;
}
bool PlayState::onExit()
{
	for each (ArcanoidObject * var in getGameObjets())
	{
		getGameObjets().remove(var);
	}

	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::collides(SDL_Rect rect, Vector2D& collision_vector, const Vector2D& velocity) {

	bool colisiona = false;

	// Paredes
	if (rect.x <= WALL_WIDTH)//golpea pared izq
	{
		collision_vector = { 1, 0 };
		return true;
	}
	else if (rect.x >= WIN_WIDTH - WALL_WIDTH - BALL_SIZE)//golpea pared drc
	{
		collision_vector = { -1, 0 };
		return true;
	}
	else if (rect.y <= 0)//golpea pared arriba
	{
		collision_vector = { 0, 1 };
		return true;
	}
	else if (rect.y >= WIN_HEIGTH - BALL_SIZE)//perder
	{
		collision_vector = { 0, -1 };

		if (paddle->getLive() >= 1)
		{
			paddle->setLives(-1);
		}
		if (paddle->getLive() == 0)
		{
			//getGame()->getStateMachine()->pushState(new EndState(getGame(), false));
		}

		return true;
	}

	//colision con bloques
	colisiona = blockMap->colides(rect, collision_vector, velocity);

	if (!colisiona)
	{
		//colision con la pala
		colisiona = paddle->collides(rect, collision_vector, velocity);
	}
	if (blockMap->getBlocks() == 0)
	{
		level++;
		cambioNivel = true;
	}
	return colisiona;
}
void PlayState::createReward(Vector2D position)
{
	Reward* r = nullptr;
	int aux1 = rand() % 4;
	if (aux1 == 0)
	{
		r = new Reward(position, PADDLE_HEIGHT, PADDLE_WIDTH / 2, getGame()->getTexture(rewardT), nextLevelP, paddle);
	}
	else if (aux1 == 1)
	{
		r = new Reward(position, PADDLE_HEIGHT, PADDLE_WIDTH / 2, getGame()->getTexture(rewardT), nextLevelP, paddle);
	}
	else if (aux1 == 2)
	{
		r = new Reward(position, PADDLE_HEIGHT, PADDLE_WIDTH / 2, getGame()->getTexture(rewardT), nextLevelP, paddle);
	}
	else if (aux1 == 3)
	{
		r = new Reward(position, PADDLE_HEIGHT, PADDLE_WIDTH / 2, getGame()->getTexture(rewardT), nextLevelP, paddle);
	}
	includeGameObjets(r);
}

void PlayState::nextLevel()
{
	level++;
	cambioNivel = true;
}

void PlayState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_a) {
				paddle->handdleEvents(-1);
			}
			if (event.key.keysym.sym == SDLK_d) {
				paddle->handdleEvents(1);
			}
			if (event.key.keysym.sym == SDLK_s) {
				saveToFile();
			}
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				getGame()->getStateMachine()->pushState(new PauseState(getGame()));
			}
		}
		else if (event.type == SDL_KEYUP)
		{
			paddle->handdleEvents(0);
		}
	}
}

void PlayState::loadFromFile()
{
	string s;
	cout << "escribe el nombre de la partida ";
	cin >> s;
	string name_file = "../Mapas/" + s + ".DAT";

	std::ifstream in(name_file);
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	int aux;
	//if (!in.is_open() || !cinbuf)
		//throw FileNotFoundError(name_file);
	cin >> aux;
	level = aux;
	for each (ArcanoidObject * var in getGameObjets())
	{
		var->loadFromFile();
	}
	while (cin)
	{
		string sType;
		rewardType type;
		int posX, posY;
		cin >> posX >> posY >> sType;
		if (sType == "lifeP")
			type = lifeP;
		else if (sType == "nextLevelP")
			type = nextLevelP;
		else if (sType == "longP")
			type = longP;
		else if (sType == "shortP")
			type = shortP;
		else type = none;

		if (type != none)
		{
			Reward* r = new Reward(Vector2D(posX, posY), PADDLE_HEIGHT, PADDLE_WIDTH / 2, getGame()->getTexture(rewardT), type, paddle);
			includeGameObjets(r);
		}
	}
	std::cin.rdbuf(cinbuf);

}

void PlayState::saveToFile()
{

	string aux;
	cin >> aux;
	string name_file = "../Mapas/" + aux + ".DAT";
	ofstream myfile(name_file.c_str());

	if (!myfile.is_open())
		throw std::string(" fichero de mapa de bloques no encontrado o no valido ");

	myfile << level << endl;

	for each (ArcanoidObject * var in getGameObjets())
	{
		string datos = var->saveToFile();

		if (var == blockMap)
		{
			myfile << datos << endl;
			int j = 0;
			string col;
			while (datos[j] != ' ')
			{
				col.push_back(datos[j]);
				j++;
			}
			int n = std::stoi(datos);
			for (int i = 0; i < n; i++)
			{
				datos = blockMap->saveLineByLine(i);
				myfile << datos << endl;
			}
		}
		else if (datos != "*")
			myfile << datos << endl;

	}

	myfile.close();
}
